class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1Count = Counter(s1)
        len1 = len(s1)
        s2Count = Counter(s2[:len1 - 1])

        for i in range(len1-1, len(s2)):
            s2Count[s2[i]] += 1
            if(s2Count == s1Count):
                return True
            s2Count[s2[i - len1 + 1]] -= 1
            if(s2Count[s2[i - len1 + 1]] == 0):
                del s2Count[s2[i - len1 + 1]]
        return False
