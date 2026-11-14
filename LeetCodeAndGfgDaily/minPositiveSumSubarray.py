from typing import List

class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        prefSum = [0]
        s = 0

        for i in range(n):
            s += nums[i]
            prefSum.append(s)

        i = 1
        minSum = float('inf')

        for i in range(n-l+1):
            for j in range(i+l-1, min(n, i+r)):
                # print(i,j)
                if prefSum[j+1] - prefSum[i] > 0:
                    minSum = min(minSum, prefSum[j+1] - prefSum[i])
                    # print(minSum)
        
        return minSum if minSum != float('inf') else -1