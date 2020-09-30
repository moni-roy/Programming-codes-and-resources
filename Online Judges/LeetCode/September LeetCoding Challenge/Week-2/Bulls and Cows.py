class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        A = 0
        s = defaultdict(int)
        g = defaultdict(int)
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                A += 1
            else:
                s[secret[i]] += 1
                g[guess[i]] += 1
        B = sum(min(s[k], g[k]) for k in s)
        return '%sA%sB' % (A, B)
