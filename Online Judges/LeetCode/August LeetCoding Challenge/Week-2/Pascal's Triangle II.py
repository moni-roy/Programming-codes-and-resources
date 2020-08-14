class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        result = [1]

        for _ in range(rowIndex):
            result = [x+y for x, y in zip([0]+result, result+[0])]

        return result
