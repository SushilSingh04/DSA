class Solution:
    def optimalArray(self, arr):
        n = len(arr)
        res = []
        
        for i in range(n):
            currLen = i + 1
            
            if i == 0:
                res.append(0)
            else:
                median = i//2
                res.append(res[i-1] + arr[i] - arr[median])
            
        return res
        