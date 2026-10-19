from typing import List

class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        smaller = eq = 0
        for i in range(len(nums)):
            if nums[i] < target:
                smaller += 1
            elif nums[i] == target:
                eq += 1
        
        lst = []
        if eq == 0:
            return lst
        for i in range(smaller, smaller + eq):
            lst.append(i)
        return lst