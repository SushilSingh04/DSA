from typing import List

class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        maxIncLen, maxDecLen = 1,1
        currIncLen, currDecLen = 1,1

        for i in range(1,len(nums)):
            if nums[i-1] > nums[i]:
                currIncLen += 1
                currDecLen = 1
            elif nums[i-1] == nums[i]:
                currIncLen = 1
                currDecLen = 1
            else:
                currDecLen += 1
                currIncLen = 1
            maxIncLen = max(maxIncLen, currIncLen)
            maxDecLen = max(maxDecLen, currDecLen)
        
        return max(maxIncLen, maxDecLen)
             