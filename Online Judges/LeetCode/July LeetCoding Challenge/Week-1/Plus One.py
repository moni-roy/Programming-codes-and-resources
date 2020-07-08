class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits == []:
            return [1]
        if digits[-1] == 9:
            digits = self.plusOne(digits[:-1])
            digits.extend([0])
        else:
            digits[-1] += 1

        return digits
