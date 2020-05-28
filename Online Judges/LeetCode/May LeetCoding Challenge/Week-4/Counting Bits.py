class Solution:
    def countBits(self, num: int) -> List[int]:
        result = [0]

        for n in range(1, num+1):
            result.append(result[n >> 1] + (n & 1))

        return result
