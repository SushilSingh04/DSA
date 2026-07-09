from typing import List

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        n = len(nums)
        connected_components = [0]*n
        group_id = 0

        for i in range(1, n):
            if nums[i] - nums[i-1] > maxDiff:
                group_id += 1
            connected_components[i] = group_id
        
        ans = []
        for l, r in queries:
            if connected_components[l] == connected_components[r]:
                ans.append(True)
            else:
                ans.append(False)
        
        return ans

        