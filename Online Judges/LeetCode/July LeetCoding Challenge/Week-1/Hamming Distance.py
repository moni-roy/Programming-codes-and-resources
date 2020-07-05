class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        xy = x ^ y
        return bin(xy).count('1')
