from typing import List
class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        # 0231 -> 0132 -> 0123
        i = 0
        while i < len(nums):
            if i != nums[i]:
                break
            i+=1

        if i == len(nums):
            return 0

        ans = 2**32-1
        for i in range(len(nums)):
            if i != nums[i]:
                ans = ans & nums[i]
                print(ans)

        return ans