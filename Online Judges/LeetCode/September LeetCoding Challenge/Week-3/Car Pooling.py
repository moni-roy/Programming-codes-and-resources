class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        timestamp = [0]*1001

        for trip in trips:
            timestamp[trip[1]] += trip[0]
            timestamp[trip[2]] -= trip[0]

        inBus = 0
        for pas in timestamp:
            inBus += pas
            if inBus > capacity:
                return False
        return True
