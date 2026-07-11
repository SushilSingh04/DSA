class Solution:
    def getCount(self, n):
        # code here 
        # s = a + a+ 1 ... a + k-1
        # n = k/2(2*a + k-1)
        # n = k*a + k*(k-1)/2
        # n - k * (k - 1)/2 = k * a
        
        k = 2
        cnt = 0;
        while n >= k*(k + 1)//2:
            if (n - k*(k-1)//2) % k == 0:
                cnt += 1
            k += 1
        
        
        return cnt