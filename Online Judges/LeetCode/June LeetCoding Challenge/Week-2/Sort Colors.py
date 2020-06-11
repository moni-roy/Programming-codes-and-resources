class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        low, high = 0, len(nums)-1

        for pos in range(0, high+1):
            while nums[pos] == 2 and pos < high:
                nums[high], nums[pos] = nums[pos], nums[high]
                high -= 1

            while nums[pos] == 0 and pos >= low:
                nums[low], nums[pos] = nums[pos], nums[low]
                low += 1
