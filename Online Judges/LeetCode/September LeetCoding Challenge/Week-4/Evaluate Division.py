class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        grph = collections.defaultdict(dict)

        for edge, val in zip(equations, values):
            grph[edge[0]][edge[1]] = val
            grph[edge[1]][edge[0]] = 1/val

        def bfs(u, v):
            if (u in grph and v in grph):
                q, vis = [(u, 1.0)], set()
                vis.add(u)
                for x, vl in q:
                    if x == v:
                        return vl
                    for y in grph[x]:
                        if y not in vis:
                            vis.add(y)
                            q.append((y, vl*grph[x][y]))
            return -1
        return [bfs(u, v) for u, v in queries]
