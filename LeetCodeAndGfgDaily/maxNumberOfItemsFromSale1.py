from typing import List

class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)
        freeCopies = [0]*n
        cheapest = float('inf')
        for i in range(n):
            cheapest = min(cheapest, items[i][1])
            for j in range(n):
                if i == j: continue
                if items[j][0] % items[i][0] == 0:
                    freeCopies[i] += 1
        
        dp = [[-1]*(budget+1) for _ in range(n)]
        def solve(n, remBudget):
            if n == 0:
                return remBudget//cheapest
            if dp[n-1][remBudget] != -1:
                return dp[n-1][remBudget]

            price = items[n-1][1]
            take = 0
            if price <= remBudget:
                take = 1 + freeCopies[n-1] + solve(n-1, remBudget-price)

            skip = solve(n-1, remBudget)

            dp[n-1][remBudget] =  max(take, skip)
            return dp[n-1][remBudget]
        
        return solve(n, budget)


            