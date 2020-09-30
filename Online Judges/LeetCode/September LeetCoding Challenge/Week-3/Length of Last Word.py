class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        spl = s.split()
        # print(spl)
        if len(spl):
            return len(spl[len(spl)-1])
        return 0
