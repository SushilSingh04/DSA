from typing import List
class Solution:
    def minElement(self, nums: List[int]) -> int:
        minSum = float('inf')
        for val in nums:
            s = 0
            while val:
                s += val % 10
                val //= 10
            minSum = min(minSum, s)
        return minSum