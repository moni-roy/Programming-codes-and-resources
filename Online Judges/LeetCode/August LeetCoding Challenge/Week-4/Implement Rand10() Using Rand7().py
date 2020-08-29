# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        rand40 = 41
        while rand40 > 40:
            rand40 = (rand7() - 1) * 7 + rand7()
        return rand40 % 10 + 1