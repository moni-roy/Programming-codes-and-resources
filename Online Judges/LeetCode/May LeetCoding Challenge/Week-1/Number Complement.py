class Solution:
    def findComplement(self, num: int) -> int:
        ans = (1 << num.bit_length()) - 1
        ans ^= num
        return ans