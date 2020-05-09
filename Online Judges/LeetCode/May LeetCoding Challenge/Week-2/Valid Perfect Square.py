class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        l , h = 1, num/2
        if(num<=0):
            return False
        if(num == 1):
            return True
        while l<=h:
            m = int((l+h)/2)
            if(m*m == num):
                return True
            if(m*m<num):
                l = m+1
            else:
                h = m-1
        return False
            