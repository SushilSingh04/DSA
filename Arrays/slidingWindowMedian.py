from typing import List
from sortedcontainers import SortedSet
def medianSlidingWindow(nums: List[int], k: int) -> List[float]:
    l = 0
    r = 0
    s = SortedSet()
    while r < k-1:
        s.add(nums[r])
        r += 1
    medians = []

    while r < len(nums):
        s.add(nums[r])
        r += 1
        print(s)
        if k % 2 == 0:
            median = (s[k//2] + s[k//2-1])/2
        else:
            median = s[k//2]
        medians.append(median)
        s.discard(nums[l])
        l += 1
    # if k % 2 == 0:
    #     medians.append([k//2] + s[k//2-1]/2)
    # else:
    #     medians.append(s[k//2])
    return medians

print(medianSlidingWindow([1,3,-1,-3,5,3,6,7], 3))