class TrieNode:
    def __init__(self):
        self.isWord = False
        self.child = {}


class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        root = self.root

        for c in word:
            if c in root.child:
                root = root.child[c]
            else:
                root.child[c] = TrieNode()
                root = root.child[c]
        root.isWord = True

    def search(self, word: str) -> bool:
        root = self.root
        self.ans = False
        self.dfs(root, word)
        return self.ans

    def dfs(self, root, word):
        if not word:
            if root.isWord:
                self.ans = True
            return
        if word[0] == '.':
            for u in root.child.values():
                self.dfs(u, word[1:])
        else:
            if word[0] in root.child:
                self.dfs(root.child[word[0]], word[1:])
        return


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
