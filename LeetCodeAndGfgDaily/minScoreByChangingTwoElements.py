from typing import List

class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        first_s = second_s = third_s = float('inf')
        first_g = second_g = third_g = float('-inf')

        for i in range(len(nums)):
            if first_s > nums[i]:
                third_s = second_s
                second_s = first_s
                first_s = nums[i]
            elif second_s > nums[i]:
                third_s = second_s
                second_s = nums[i]
            elif third_s > nums[i]:
                third_s = nums[i]

            if first_g < nums[i]:
                third_g = second_g
                second_g = first_g
                first_g = nums[i]
            elif second_g < nums[i]:
                third_g = second_g
                second_g = nums[i]
            elif third_g < nums[i]:
                third_g = nums[i]

        ans = min(abs(first_s-third_g), abs(first_g-third_s), abs(second_g-second_s))
        print(first_s, second_s, third_s, first_g, second_g, third_g)


        return ans

        
        