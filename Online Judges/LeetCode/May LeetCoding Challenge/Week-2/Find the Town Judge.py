class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        inCount, outCount = [0]*(N+1), [0]*(N+1)
        
        for node in trust:
            inCount[node[1]] += 1
            outCount[node[0]] += 1
        for i in range(1, N+1):
            if(inCount[i] == N-1 and outCount[i] == 0):
                return i
        return -1