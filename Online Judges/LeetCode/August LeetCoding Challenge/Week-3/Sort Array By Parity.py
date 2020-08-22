class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        even = [x for x in A if x % 2 == 0]
        odd = [x for x in A if x % 2 == 1]
        return even + odd
