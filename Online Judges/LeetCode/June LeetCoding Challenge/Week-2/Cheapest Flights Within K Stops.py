class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        cost = [[1e8]*(n) for j in range(K + 2)]

        cost[0][src] = 0

        for i in range(1, K+2):
            cost[i][src] = 0
            for u, v, k in flights:
                cost[i][v] = min(cost[i][v], cost[i-1][u] + k)

        return cost[K+1][dst] if cost[K+1][dst] != 1e8 else -1
