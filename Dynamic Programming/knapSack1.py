from typing import List
def knapSack(weights: List[int], values: List[int], n:int, W:int, dp:List[List[int]]) -> int:
    if n == 0 or W == 0:
        return 0
    if dp[n][W] != -1:
        return dp[n][W]
    # Pick 
    pick = 0
    if weights[n-1] <= W:
        pick = values[n-1] + knapSack(weights, values, n-1, W-weights[n-1], dp)

    # Not Pick
    notPick = knapSack(weights, values, n-1, W, dp)
    dp[n][W] = max(pick, notPick)
    return dp[n][W]

def solve(weights: List[int], values: List[int], n:int, W:int):
    dp = [[-1 for _ in range(W+1)] for _ in range(n+1)]
    return knapSack(weights, values, n, W, dp)

weights = [10, 4, 3, 7, 5]
values = [3,5,1,6,7]
W = 18
print(solve(weights, values, len(values), W))