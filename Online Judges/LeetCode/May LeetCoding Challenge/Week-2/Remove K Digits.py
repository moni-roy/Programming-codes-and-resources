class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if(len(num) == k): return "0"
        list = []
        for d in num:
            while k and list and list[-1]>d:
                k = k-1
                list.pop()
            list.append(d)
        return ''.join(list[:-k or None]).lstrip('0') or '0'