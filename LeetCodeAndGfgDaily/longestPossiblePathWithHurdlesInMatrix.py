class Solution:
    def longestPath(self, mat, xs, ys, xd, yd):
        # code here
        n,m = len(mat), len(mat[0])
        visited = [[False] * m for _ in range(n)]
        return self.solve(xs, ys, mat, xd, yd, visited)
        
    def solve(self, i, j, mat, xd, yd, visited):
        if i == xd and j == yd:
            return 0
        dirs = [(-1,0), (1,0), (0,1), (0,-1)]
        visited[i][j] = True
            
        cnt = -1
        for di, dj in dirs:
            ni,nj = i + di, j + dj
            if ni >= 0 and ni < n and nj >= 0 and nj < m and not visited[ni][nj] and mat[ni][nj] == 1:
                tmp = self.solve(ni, nj, mat, xd, yd, visited)
                if tmp != -1:
                    cnt = max(cnt, tmp + 1)
        
        visited[i][j] = False
        return cnt
        