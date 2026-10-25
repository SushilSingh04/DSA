from collections import deque
class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        row = [-1,0,0,1]
        col = [0,1,-1,0]
        islands = 0
        r, c = len(grid), len(grid[0])
        visited = [[False]*c for _ in range(r)]

        for i in range(r):
            for j in range(c):
                if grid[i][j] == 0 and not visited[i][j]:
                    if i == 0 or i == r-1 or j == 0 or j == c-1:
                        boundary = True
                    else:
                        boundary = False
                    visited[i][j] = True
                    q = deque([(i,j)])
                    while q:
                        x,y = q.popleft()
                        for k in range(4):
                            nrow, ncol = x + row[k], y + col[k]
                            if nrow >= 0 and nrow < r and ncol >= 0 and ncol < c and not visited[nrow][ncol] and grid[nrow][ncol] == 0:
                                if nrow == 0 or nrow == r-1 or ncol == 0 or ncol == c-1:
                                    boundary = True
                                q.append((nrow, ncol))
                                visited[nrow][ncol] = True
                    if not boundary:
                        islands += 1
        return islands