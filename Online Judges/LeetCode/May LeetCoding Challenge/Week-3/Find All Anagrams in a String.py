class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        pCounter = Counter(p)
        l = len(p)
        sCounter = Counter(s[:l - 1])
        ans = []
        for i in range(l-1, len(s)):
            sCounter[s[i]] += 1
            if sCounter == pCounter:
                ans.append(i - l + 1)
            sCounter[s[i- l + 1]] -= 1
            if sCounter[s[i - l + 1]] == 0:
                del sCounter[s[i - l +1]]
        return ans
            