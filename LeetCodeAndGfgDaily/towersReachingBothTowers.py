class Solution:
    def countCoordinates(self, mat):
        # code here
        n,m = len(mat), len(mat[0])
        visitedP = [[False]* m for _ in range(n)]
        visitedQ = [[False]*m for _ in range(n)]
        ans = 0
        
        for i in range(n):
            self.dfs(i, 0, mat, visitedP)
            self.dfs(i, m-1, mat, visitedQ)
        
        for i in range(m):
            self.dfs(0, i, mat, visitedP)
            self.dfs(n-1, i, mat, visitedQ)
        
        
        for i in range(n):
            for j in range(m):
                if visitedP[i][j] and visitedQ[i][j]:
                    ans += 1
        
        return ans
    
    def dfs(self, i, j, mat, visited):
        n, m = len(mat), len(mat[0])
        visited[i][j] = True
        
        directions = [(-1,0), (1,0), (0, -1), (0, 1)]
        
        for di, dj in directions:
            ni, nj = i + di, j + dj
            if ni >= 0 and ni < n and nj >= 0 and nj < m and not visited[ni][nj]:
                if mat[ni][nj] >= mat[i][j]:
                    self.dfs(ni, nj, mat, visited)
        