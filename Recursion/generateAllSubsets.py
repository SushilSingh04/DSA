def subsets(nums):
        allSubsets = []
        def generateSubsets(idx, currSubset):
            if idx == len(nums):
                allSubsets.append(currSubset.copy())
                return
            # Include idx
            currSubset.append(nums[idx])
            generateSubsets(idx+1, currSubset)

            #Exclude idx
            currSubset.pop()
            generateSubsets(idx+1, currSubset)
            
        generateSubsets(0, [])
        return allSubsets

print(subsets([1,2,3]))
            