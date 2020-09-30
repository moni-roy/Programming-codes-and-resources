class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        sc = Counter(s)
        tc = Counter(t)

        for t in tc:
            if sc[t] != tc[t]:
                return t
        return ""
