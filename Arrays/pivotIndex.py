from typing import List
def pivotIndex(self, nums: List[int]) -> int:
    leftSum = 0
    rightSum = sum(nums)
    for i in range(len(nums)):
        if i != 0:
            leftSum += nums[i-1]
        rightSum -= nums[i]
        if rightSum == leftSum:
            return i
    return -1