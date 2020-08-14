class Solution:
    def titleToNumber(self, s: str) -> int:
        return sum((ord(ch)-ord('A')+1)*(26**ex) for ex, ch in enumerate(s[::-1]))
