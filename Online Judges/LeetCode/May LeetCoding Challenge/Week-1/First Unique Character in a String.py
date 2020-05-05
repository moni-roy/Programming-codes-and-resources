class Solution:
    def firstUniqChar(self, s: str) -> int:
        arr = Counter(s)
        for i in range(len(s)):
            if(arr[s[i]] == 1):
                return i
        return -1
        