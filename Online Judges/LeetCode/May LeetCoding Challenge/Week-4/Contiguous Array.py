class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        count, maxLen = 0, 0
        mapTable = {0: 0}

        for index, num in enumerate(nums, 1):
            if num == 0:
                count -= 1
            else:
                count += 1
            if count in mapTable:
                maxLen = max(maxLen, index - mapTable[count])
            else:
                mapTable[count] = index
        return maxLen
