class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ret = []
        def backtrack(remain, lis, nex):

            if remain == 0 and len(lis) == k:
                ret.append(list(lis))
                return
            elif remain < 0 or len(lis) == k:
                return

            for i in range(nex+1, 10):
                lis.append(i)
                backtrack(remain - i, lis, i)
                lis.pop()

        backtrack(n, [], 0)
        return ret
