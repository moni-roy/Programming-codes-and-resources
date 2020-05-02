class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        ans = 0
        for i in range(0, len(S)):
            if(J.find(S[i])!=-1):
                ans += 1
        return ans