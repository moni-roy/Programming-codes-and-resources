class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ret = []
        for i in range(1, 10):
            nm = i
            d = i
            while nm <= high and d < 10:
                if nm >= low:
                    ret.append(nm)
                d = d + 1
                nm = nm*10 + d
        return sorted(ret)
