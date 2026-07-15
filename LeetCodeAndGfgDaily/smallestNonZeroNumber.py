class Solution:
    def find(self, arr):
        # code here
        n = len(arr)
        curr = 0
        # curr = prev + (prev - arr[i])
        # curr = 2*prev - arr[i]
        # starting from end minimum value for curr is zero
        # prev should be 
        # (curr + arr[i])/2
        for i in range(n-1,-1,-1):
            curr = (curr + arr[i] + 1)//2
            
        return curr
        