from typing import List
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        max_ele = max(nums)
        moves = 0
        for i in range(len(nums)):
            moves += max_ele - nums[i]
        
        return moves