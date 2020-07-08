class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        Ans = []
        nums.sort()

        for i in range(len(nums)):
            if i == 0 or (i > 0 and nums[i-1] != nums[i]):
                low = i + 1
                high = len(nums) - 1
                extra = - nums[i]
                while low < high:
                    if nums[low] + nums[high] == extra:
                        Ans.append([nums[i], nums[low], nums[high]])

                        while low < len(nums)-1 and nums[low] == nums[low+1]:
                            low += 1
                        while high > 0 and nums[high] == nums[high-1]:
                            high -= 1
                    if (nums[low] + nums[high]) < extra:
                        low += 1
                    else:
                        high -= 1
        return Ans
