from typing import List
class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        # 2 2 5 6 7 9
        cost.sort()
        n = len(cost)
        i = n-1
        totalCost = 0

        while i >= 0:
            totalCost += cost[i]
            if i-1 >= 0:
                totalCost += cost[i-1]
            i -= 3
        
        return totalCost

