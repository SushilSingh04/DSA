from collections import defaultdict
from bisect import bisect_left, bisect_right

class Solution:
    def freqInRange(self, arr, queries):
        n = len(arr)
        m = len(queries)
        mp = defaultdict(list)
        
        for i, val in enumerate(arr):
            mp[val].append(i)
            
        # Do binary search on the list value for each query if the key is present
        # Find upperBound - lowerBound
        ans = []
        
        for [l,r,x] in queries:
            if x in mp:
                lst = mp[x]
                left = 0
                right = len(lst) - 1
                
                #Lower Bound
                lb = bisect_left(lst, l)
                ub = bisect_right(lst, r)
                ans.append(ub - lb)
            else:
                ans.append(0)
        
        return ans