class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        spt = str.split()
        if len(spt) != len(pattern):
            return False
        c_map = {}
        w_map = {}
        for c, w in zip(pattern, spt):
            if c not in c_map:
                if w in w_map:
                    return False
                else:
                    c_map[c] = w
                    w_map[w] = c
            elif c_map[c] != w:
                return False
        return True
