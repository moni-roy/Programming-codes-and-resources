class Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        sum, maxSum, minSum, curMax, curMin = 0, -float('inf'), float('inf'), 0, 0
        for a in A:
            curMax = max(curMax + a, a)
            curMin = min(curMin + a, a);
            
            maxSum = max(maxSum, curMax)
            minSum = min(minSum, curMin)
            
            sum = sum + a
        return max(maxSum, sum - minSum) if maxSum > 0 else maxSum