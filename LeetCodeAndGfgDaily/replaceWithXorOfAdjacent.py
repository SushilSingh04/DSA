class Solution:
    def replaceElements(self, arr):
        # code here
        #          i
        # 2  1  4  7
        #       p  c
        
        n = len(arr)
        if n == 1:
            arr[0] = arr[0] ^ arr[0]
            return
            
        prev, curr = arr[0], arr[1]
        
        for i in range(n):
            if i == 0:
                arr[i] = prev ^ curr
            elif i == n-1:
                arr[i] = prev ^ curr
            else:
                arr[i] = prev ^ arr[i+1]
                prev = curr
                curr = arr[i+1]
                
                
        