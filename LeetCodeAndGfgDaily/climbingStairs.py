from typing import List

class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        dp = [0]*(n+1)
        dp[0] = 0
        
        for j in range(1,n+1):
            ans = float('inf')
            for i in range(j-3,j):
                if i >= 0:
                    ans = min(ans, dp[i] + costs[j-1] + (j-i)**2)
            dp[j] = ans
        
        return dp[n]