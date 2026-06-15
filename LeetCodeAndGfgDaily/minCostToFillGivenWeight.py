# Essentially unbounded knapsack

def minimumCost(self, cost, w):
    n = len(cost)
    dp = [-2]*(w+1) # -1 is also a state hence -2
    
    def solve(remWeight):
        # base case
        if remWeight == 0:
            return 0
        
        if dp[remWeight] != -2:
            return dp[remWeight]
        
        minCost = float('inf')
        for i in range(n):
            # Calculate minCost if remWeight is greater than current weight
            if i + 1 <= remWeight and cost[i] != -1: # Don't include -1 as cost in minCost
                c = solve(remWeight - (i + 1))
                if c != -1: # calculate minCost only if previous cost is not -1
                    minCost = min(minCost, c + cost[i])

        # minCost didn't change at all. Means didn't find any solution
        if minCost == float('inf'):
            dp[remWeight] = -1 # Memoize this state as well to avoid unncessary computation
        # Found a solution
        else:
            dp[remWeight] = minCost
            
        return dp[remWeight]
        
    return solve(w)