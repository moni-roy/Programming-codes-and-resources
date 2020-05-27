class Solution:
    def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool:
        graph = defaultdict(list)
        for u, v in dislikes:
            graph[v].append(u)
            graph[u].append(v)

        color = {}

        def dfs(u, c=0):
            if u in color:
                return color[u] == c
            color[u] = c
            ret = 1
            for v in graph[u]:
                ret = ret & dfs(v, c ^ 1)
            return ret
        ans = 1
        for u in range(1, N+1):
            if u not in color:
                ans &= dfs(u, 0)
        return ans
