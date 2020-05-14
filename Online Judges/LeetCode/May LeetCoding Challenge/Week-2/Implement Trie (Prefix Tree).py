class Trie:

    def __init__(self):
        self.root = {}
        
    def insert(self, word: str) -> None:
        node = self.root
        for letter in word:
            if letter not in node:
                node[letter] = {}
            node = node[letter]
        node["#"] = "#"
        
    def search(self, word: str) -> bool:
        node = self.root
        for letter in word:
            if letter not in node:
                return False
            node = node[letter]
        return "#" in node
    
    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for letter in prefix:
            if letter not in node:
                return False
            node = node[letter]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)