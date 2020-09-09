class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return self.check(s)

    def KMP(self, s, lps):
        n = len(s)
        l = 0
        i = 1
        lps[0] = 0
        while i < n:
            if s[i] == s[l]:
                l += 1
                lps[i] = l
                i += 1
            else:
                if l != 0:
                    l = lps[l-1]
                else:
                    lps[i] = 0
                    i += 1

    def check(self, s):
        n = len(s)
        lps = [0]*n
        self.KMP(s, lps)
        l = lps[n-1]
        if l > 0 and n % (n-l) == 0:
            return True
        return False
