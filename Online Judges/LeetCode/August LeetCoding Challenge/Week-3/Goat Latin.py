class Solution:
    def toGoatLatin(self, S: str) -> str:
        S = S.split(' ')
        v = "aAeEiIoOuU"
        ans = []
        a = "a"
        for s in S:
            if s[0] not in v:
                t = s[1::] + s[0] + "ma" + a
                ans.append(t)
            else:
                t = s + "ma" + a
                ans.append(t)
            a += "a"
        return " ".join(i for i in ans)
