class Solution:
    def largestArea(self, n, m, arr):
        r_s = [-1]
        c_s = [-1]
        
        for blocked in arr:
            r, c = blocked[0]-1, blocked[1]-1
            r_s.append(r)
            c_s.append(c)
            
        r_s.append(n)
        c_s.append(m)
        
        r_s.sort()
        c_s.sort()
        
        max_diff_row = 0
        max_diff_col = 0
        
        for i in range(1,len(r_s)):
            max_diff_row = max(max_diff_row, r_s[i] - r_s[i-1] - 1)
        
        for j in range(1, len(c_s)):
            max_diff_col = max(max_diff_col, c_s[j] - c_s[j-1] - 1)
        
        return max_diff_row * max_diff_col
            
            
        