class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        ret, mask = 0, 0
        for i in range(32)[::-1]:
            mask = mask | (1 << i)
            st = set()
            for num in nums:
                st.add(num & mask)
            tm = (ret | (1 << i))
            for s in st:
                if (tm ^ s) in st:
                    ret = tm
                    break
        return ret
