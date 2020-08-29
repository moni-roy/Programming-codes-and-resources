class TrieNode():
    def __init__(self):
        self.child = {}
        self.isWord = False


class Trie():
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        root = self.root

        for char in word:
            if char not in root.child:
                root.child[char] = TrieNode()
            root = root.child[char]
        root.isWord = True


class StreamChecker:
    def __init__(self, words: List[str]):
        self.trie = Trie()
        self.stream = []
        for word in words:
            self.trie.insert(word[::-1])

    def query(self, letter: str) -> bool:
        self.stream.append(letter)
        i = len(self.stream) - 1
        root = self.trie.root

        while i >= 0:
            if root.isWord:
                return True
            if self.stream[i] not in root.child:
                return False
            root = root.child[self.stream[i]]
            i -= 1
        return root.isWord


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
