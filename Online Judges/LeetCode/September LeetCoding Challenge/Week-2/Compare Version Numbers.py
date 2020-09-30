class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')
        i, j = 0, 0
        # print(len(v1), len(v2))

        while i < len(v1) or j < len(v2):
            x, y = 0, 0
            if i < len(v1):
                x = int(v1[i])
            if j < len(v2):
                y = int(v2[j])

            if x > y:
                return 1
            if x < y:
                return -1
            i += 1
            j += 1
        return 0
