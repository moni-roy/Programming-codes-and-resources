class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(list)
        degree = [0]*numCourses

        for u, v in prerequisites:
            graph[v].append(u)
            degree[u] += 1

        bfs = [u for u in range(numCourses) if degree[u] == 0]

        for u in bfs:
            for v in graph[u]:
                degree[v] -= 1
                if degree[v] == 0:
                    bfs.append(v)
        return len(bfs) == numCourses
