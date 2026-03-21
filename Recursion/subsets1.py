from typing import List
def subsets(self, nums: List[int]) -> List[List[int]]:
        # 1 2 3
        #     i
        allSubsets = []
        def generateSubsets(idx, currSubset):
            # Base Case
            if idx == len(nums):
                allSubsets.append(currSubset.copy())
                return 
            # Include idx
            currSubset.append(nums[idx])
            generateSubsets(idx+1,currSubset)

            # Exclude idx
            currSubset.pop()
            generateSubsets(idx+1, currSubset)
        generateSubsets(0,[])
        return allSubsets