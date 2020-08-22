class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0 for i in range(num_people)]
        st = 1
        while candies:
            for i in range(num_people):
                if candies == 0:
                    break
                if candies >= st:
                    ans[i] += st
                    candies -= st
                    st += 1
                else:
                    ans[i] += candies
                    candies = 0
        return ans
