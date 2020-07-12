class Solution:
    def reverseBits(self, n: int) -> int:
        Ans, pwr = 0, 31

        while n:
            Ans += (n & 1) << pwr
            n = n >> 1
            pwr -= 1
        return Ans
