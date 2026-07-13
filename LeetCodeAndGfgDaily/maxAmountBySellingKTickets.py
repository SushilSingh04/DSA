import heapq

class Solution:
    def maxAmount(self, arr, k):
        # code here
        MOD = 10**9 + 7
        n = len(arr)
        max_heap = [-x for x in arr]
        heapq.heapify(max_heap)
        maxAmount = 0
        
        while k > 0 and max_heap:
            val = -heapq.heappop(max_heap)
            maxAmount = (maxAmount + val) % MOD
            if val-1 >= 0:
                heapq.heappush(max_heap, -val + 1)
            else:
                break
            k -= 1
        
        return maxAmount