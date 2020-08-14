from itertools import combinations


class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        # print(characters, list(combinations(characters, combinationLength)))
        self.combination = [''.join(x) for x in combinations(
            characters, combinationLength)][::-1]
        # print (self.combination)
        self.next = self.combination.pop
        self.hasNext = lambda: bool(self.combination)

    def next(self) -> str:
        return self.next

    def hasNext(self) -> bool:
        return self.hasNext


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
