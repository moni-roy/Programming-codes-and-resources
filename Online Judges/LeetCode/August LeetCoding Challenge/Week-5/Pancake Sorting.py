class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        def flipSublist(sublist, k):
            i = 0
            while i < k/2:
                sublist[i], sublist[k-i-1] = sublist[k-i-1], sublist[i]
                i += 1

        ans = []
        ln = len(A)
        while ln > 0:
            idx = A.index(ln)

            if idx != ln-1:
                if idx != 0:
                    ans.append(idx+1)
                    flipSublist(A, idx+1)
                ans.append(ln)
                flipSublist(A, ln)
            ln -= 1
        return ans
