class Solution:
    def longestPalindrome(self, s: str) -> int:
        count = Counter(s)
        odd, length = 0, 0
        for char in count:
            length += count[char]
            if count[char] % 2 == 1:
                length -= 1
                odd = 1
        return length + odd
