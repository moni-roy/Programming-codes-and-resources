class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        dp = [1] * len(nums)
        nums.sort()
        mx = 0
        num = 0
        for i in range(0, len(nums)):
            for j in range(0, i):
                if nums[i] % nums[j] == 0:
                    dp[i] = max(dp[i], dp[j]+1)
            if mx < dp[i]:
                mx = dp[i]
                num = nums[i]
        #print(num, mx)
        result = []
        for i in range(len(nums)-1, -1, -1):
            if dp[i] == mx and num % nums[i] == 0:
                result.append(nums[i])
                mx -= 1
                num = nums[i]
        return result
