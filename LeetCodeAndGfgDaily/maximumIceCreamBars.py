from typing import List

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        cntBars = 0

        for cost in costs:
            if cost <= coins:
                coins -= cost
                cntBars += 1
                
        return cntBars