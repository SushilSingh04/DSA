from typing import List
from collections import deque
class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        row = [-1,0,0,1]
        col = [0,1,-1,0]
        islands = 0
        r, c = len(grid), len(grid[0])

        for i in range(r):
            for j in range(c):
                if grid[i][j] != 0:
                    total_val = grid[i][j]                    
                    grid[i][j] = 0
                    q = deque([(i,j)])
                    while q:
                        x,y = q.popleft()
                        for l in range(4):
                            nrow, ncol = x + row[l], y + col[l]
                            if nrow >= 0 and nrow < r and ncol >= 0 and ncol < c and grid[nrow][ncol] != 0:
                                total_val += grid[nrow][ncol]
                                q.append((nrow, ncol))
                                grid[nrow][ncol] = 0
                    if total_val % k == 0:
                        islands += 1
        return islands