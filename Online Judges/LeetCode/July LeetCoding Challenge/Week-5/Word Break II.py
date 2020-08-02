class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        cache = {}

        def helper(s: str, wordDict: List[str]) -> List[str]:
            if not s:
                return [""]
            if s in cache:
                return cache[s]
            result = []
            for word in wordDict:
                # print (s, word)
                if s.startswith(word):
                    subResult = helper(s[len(word):], wordDict)
                    # print(subResult)
                    for sub in subResult:
                        sp = ' ' if len(sub) > 0 else ''
                        ss = word + sp + sub
                        if ss not in result:
                            result.append(ss)
            cache[s] = result
            return result
        return helper(s, wordDict)
