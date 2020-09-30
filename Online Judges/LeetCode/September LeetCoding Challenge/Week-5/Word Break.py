class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        yes = [False]*len(s)
        for i in range(len(s)):
            for word in wordDict:
                # print(word, i)
                if word == s[i-len(word)+1:i+1] and (yes[i-len(word)] or i-len(word) == -1):
                    yes[i] = True
                    # print(s[i-len(word)+1:i+1])

        return yes[-1]
