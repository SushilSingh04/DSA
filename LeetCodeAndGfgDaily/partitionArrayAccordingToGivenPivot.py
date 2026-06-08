from typing import List
class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        ans1 = []
        ans2 = []
        ans3 = []

        for val in nums:
            if val < pivot:
                ans1.append(val)
            elif val == pivot:
                ans2.append(pivot)
            else:
                ans3.append(val)
        
        return ans1 + ans2 + ans3