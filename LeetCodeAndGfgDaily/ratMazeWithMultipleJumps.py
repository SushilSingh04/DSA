def shortestDist(self, mat):
    n = len(mat)
    ans = [[0]*n for _ in range(n)]
    dp = [[-1]*n for _ in range(n)]
    
    def solve(i, j):
        # Base case
        n = len(mat)
        if i >= n or j >= n or mat[i][j] == 0:
            return False
        
        # Catch a dead end early and avoid computation
        if dp[i][j] == 0:
            return False
            
        ans[i][j] = 1
    
        if i == n-1 and j == n-1:
            return True
    
        maxJump = mat[i][j]
    
        for jump in range(1,maxJump+1):
            if j + jump < n:
                if solve(i, j + jump):
                    dp[i][j] = 1
                    return True
                    
            if i + jump < n:
                if solve(i + jump, j):
                    dp[i][j] = 1
                    return True
                
        # Storing only dead ends is enough        
        dp[i][j] = 0
        ans[i][j] = 0
        return False
    
    if solve(0, 0):
        return ans
    return [[-1]]