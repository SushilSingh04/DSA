class Solution:
    def countWays(self, n, m):
        MOD = 10**9 + 7
        dp = [-1] * (n + 1)

        def solve(i):
            if i < m:
                return 1
            if i == m:
                return 2
            if dp[i] != -1:
                return dp[i]

            dp[i] = (solve(i - 1) + solve(i - m)) % MOD
            return dp[i]

        return solve(n)
		
		