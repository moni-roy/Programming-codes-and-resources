class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        numStr = [str(i) for i in range(1, n+1)]
        fact = [1]*n
        for i in range(1, n):
            fact[i] = i*fact[i-1]
        ans = []
        k -= 1
        while n:
            i = int(k / fact[n-1])
            k %= fact[n-1]
            ans.append(numStr[i])
            numStr.pop(i)
            n -= 1
        return ''.join(ans)
