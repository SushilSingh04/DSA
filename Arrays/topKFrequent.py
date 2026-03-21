from collections import Counter
from typing import List
def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    n = len(nums)
    d = Counter(nums)
    buckets = [[] for _ in range(n+1)]
    ans = []

    for num,freq in d.items():
        buckets[freq].append(num)

    for i in range(n,0,-1):
        for num in buckets[i]:
            ans.append(num)
            if len(ans) == k:
                return ans