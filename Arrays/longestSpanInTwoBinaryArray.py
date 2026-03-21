# Equal sum in two arrays over the same range
# 1. Subtract both arrays 
# 2. Calculate prefixSum over it
# 3. Problem reduces to calculating longest size subarray with sum k (k = 0).

from collections import defaultdict
class Solution:
    def equalSumSpan(self, a1, a2):
        # code here
        n = len(a1)
        mp = defaultdict(lambda: None)
        mp[0] = -1
        prefixSum = 0
        maxLen = 0
        for i in range(n):
            prefixSum += a1[i] - a2[i]
            if prefixSum in mp:
                maxLen = max(maxLen, i - mp[prefixSum])
            else:
                mp[prefixSum] = i
        return maxLen