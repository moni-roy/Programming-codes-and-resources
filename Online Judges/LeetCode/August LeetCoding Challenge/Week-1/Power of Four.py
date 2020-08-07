class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        return num > 0 and floor(log(num)/log(4)) == ceil(log(num)/log(4))
