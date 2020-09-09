class DSU:
    def __init__(self, N):
        self.par = list(range(N))

    def find(self, U):
        if self.par[U] != U:
            self.par[U] = self.find(self.par[U])
        return self.par[U]

    def union(self, U, V):
        X, Y = self.find(U), self.find(V)
        self.par[X] = Y


class Solution:
    def factors(self, n):
        for i in range(2, int(math.sqrt(n))+1):
            if n % i == 0:
                return self.factors(n//i) | set([i])
        return set([n])

    def largestComponentSize(self, A: List[int]) -> int:
        n = len(A)
        uf = DSU(n)

        factor = defaultdict(list)

        for i, num in enumerate(A):
            fct = self.factors(num)
            for f in fct:
                factor[f].append(i)

        for k, ind in factor.items():
            for i in range(len(ind)-1):
                uf.union(ind[i], ind[i+1])

        return max(Counter([uf.find(i) for i in range(n)]).values())
