class Solution:
    def findCoverage(self, mat):
        # code here  
        n, m = len(mat), len(mat[0])
        ans = 0
        # For each row and each column:
            # Forwards: count 0's after the first 1 encountered
            # Backwards: count 0's before the first 1 encountered
            
        for i in range(n):
            # Forward
            for j in range(m):
                if mat[i][j] == 1:
                    for k in range(j+1,m):
                        if mat[i][k] == 0:
                            ans += 1
                    break
            
            # Backward
            for j in range(m-1,-1,-1):
                if mat[i][j] == 1:
                    for k in range(j-1,-1,-1):
                        if mat[i][k] == 0:
                            ans += 1
                    break
                
        for i in range(m):
            # Forward
            for j in range(n):
                if mat[j][i] == 1:
                    for k in range(j+1,n):
                        if mat[k][i] == 0:
                            ans += 1
                    break
            
            # Backward
            for j in range(n-1,-1,-1):
                if mat[j][i] == 1:
                    for k in range(j-1,-1,-1):
                        if mat[k][i] == 0:
                            ans += 1
                    break
                
        return ans
                        
        