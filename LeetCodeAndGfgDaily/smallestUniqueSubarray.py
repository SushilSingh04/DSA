from typing import List
import math

class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        base = max(nums) + 1
        MOD = (1 << 32) + 1

        def check_size(size):
            h = 0
            seen = {}
            for i in range(size):
                h = (h*base + nums[i]) % MOD
            seen[h] = seen.get(h,0)+1

            p = math.pow(base, size-1, MOD)
            for i in range(size, n):
                h = (h - p*nums[i-size]) % MOD
                h = (h*base + nums[i]) % MOD
                seen[h] = seen.get(h, 0) + 1
            
            return any(v == 1 for v in seen.values())

        l,h = 0,n-1
        while l <= h:
            mid = (l+h)//2
            if check_size(mid):
                h = mid-1
            else:
                l = mid+1
        
        return l