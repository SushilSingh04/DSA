# Frog can jump from i to i+1, i+2, ... i+k
heights = [0]*10
dp = [-1 for i in range(heights)]
k = 3
def rec(heights, idx):
    if idx <= 1:
        return abs(heights[0]- heights[idx])
    if dp[idx] != -1:
        return dp[idx]
    ans = float('inf')
    for i in range(idx-1,i >= idx-k, -1):
        if i < 0:
            break
        ans = min(ans, abs(heights[i]-heights[idx])+ rec(heights, idx-i))
    dp[idx] = ans
    return ans