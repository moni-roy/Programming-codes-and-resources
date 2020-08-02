class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = reduce(lambda x, y: x ^ y, nums)
        first, second = 0, 0
        xor &= -xor
        for num in nums:
            if num & xor:
                first ^= num
            else:
                second ^= num
        return [first, second]
