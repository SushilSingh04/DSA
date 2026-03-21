from typing import List

# Memoization -> Top Down (from n to 0)
# Standing at idx frog could have come from either idx-1 or idx-2
# Return the minimum cost of reaching stone N from stone 1, cost is |hi-hj|
# Given heights of each stone

def minCostfrogJump(heights: List[int]):
    dp = [-1 for i in range(len(heights))]
    def rec(idx: int):
        if idx <=1 :
            return abs(heights[0] - heights[idx])
        # Frog jumped from idx-1 to idx
        option1 = abs(heights[idx]-heights[idx-1]) + rec(idx-1, heights)
        option2 = abs(heights[idx]-heights[idx-2]) + rec(idx-2, heights)

        dp[idx] = min(option1, option2)
        return dp[idx]
    return rec(0)