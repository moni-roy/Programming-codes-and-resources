class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total, mx = 0, float('inf')
        st = 0
        for i in range(len(gas)):
            total += gas[i] - cost[i]
            if total < mx:
                mx = total
                st = i+1
        return -1 if total < 0 else (st) % len(gas)
