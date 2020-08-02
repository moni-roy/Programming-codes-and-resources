class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adjList = defaultdict(list)

        for v, u in prerequisites:
            adjList[u].append(v)

        ans = []
        isPossible = True

        color = {k: 0 for k in range(numCourses)}

        def dfs(u):
            nonlocal isPossible

            if not isPossible:
                return

            color[u] = 1

            if u in adjList:
                for v in adjList[u]:
                    if color[v] == 0:
                        dfs(v)
                    elif color[v] == 1:
                        isPossible = False

            color[u] = 2
            ans.append(u)

        for u in range(numCourses):
            if color[u] == 0:
                dfs(u)

        return ans[::-1] if isPossible else []
