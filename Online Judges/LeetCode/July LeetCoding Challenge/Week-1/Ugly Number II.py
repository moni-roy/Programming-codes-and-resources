class Solution:
    def nthUglyNumber(self, n: int) -> int:
        num = [1]
        i, j, k = 0, 0, 0
        for _ in range(n):
            l = min(num[i]*2, num[j]*3, num[k]*5)
            num.append(l)
            if l == num[i]*2:
                i += 1
            if l == num[j]*3:
                j += 1
            if l == num[k]*5:
                k += 1
        return num[n-1]
