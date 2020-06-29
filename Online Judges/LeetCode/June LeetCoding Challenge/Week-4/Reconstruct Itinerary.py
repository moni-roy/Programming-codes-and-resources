class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = collections.defaultdict(list)

        for u, v in tickets:
            graph[u].append(v)

        for u in graph.keys():
            graph[u].sort(reverse=True)

        stack = []
        stack.append("JFK")
        res = []

        while stack:
            u = stack[-1]
            while graph[u]:
                stack.append(graph[u].pop())
                u = stack[-1]
            res.append(stack.pop())
        return res[::-1]
