class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people = sorted(people, key=lambda x: (-x[0], x[1]))

        ret = []

        for p in people:
            ret.insert(p[1], p)
        return ret
