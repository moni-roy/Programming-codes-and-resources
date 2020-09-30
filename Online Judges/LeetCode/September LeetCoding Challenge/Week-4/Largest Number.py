class Comparator(str):
    def __lt__(x, y):
        return (x+y) > (y+x)


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        ret = ''.join(sorted(map(str, nums), key=Comparator))

        return '0' if ret[0] == '0' else ret
