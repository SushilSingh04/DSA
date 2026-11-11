class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        totalCost = min(costBoth, cost1 + cost2) * min(need1, need2)

        if need1 > need2:
            totalCost += min(cost1, costBoth) * (need1 - need2)
        if need2 > need1:
            totalCost += min(cost2, costBoth) * (need2 - need1)
        
        return totalCost