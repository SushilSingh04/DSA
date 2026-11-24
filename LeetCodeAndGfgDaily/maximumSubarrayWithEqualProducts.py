from typing import List
import math

class Solution:
    def maxLength(self, nums: List[int]) -> int:
        maxLen = 2
        i = 0
        prod = nums[0]*nums[1]
        if gcd(nums[0], nums[1]) > 1:
            i = 1
            prod = nums[1]
            
        for j in range(2,len(nums)):
            while i < len(nums) and math.gcd(prod, nums[j]) > 1:
                prod //= nums[i]
                i += 1
            prod *= nums[j]
            # print(prod, i)
            maxLen = max(maxLen, j-i+1)
        return maxLen
        # 9*8 != 24*1
        
