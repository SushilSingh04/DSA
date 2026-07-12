from typing import List

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        if not arr:
            return []

        res = []
        ans = sorted(set(arr))
        mp = {}

        for i in range(len(ans)):
            mp[ans[i]] = i + 1
        
        for i in range(len(arr)):
            res.append(mp[arr[i]])
        

        return res
        

