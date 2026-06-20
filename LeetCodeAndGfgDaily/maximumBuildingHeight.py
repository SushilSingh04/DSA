from typing import List

class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        restrictions.append([1,0])
        restrictions.append([n, n-1])
        n = len(restrictions)
        restrictions.sort()

        for i in range(1,n):
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + restrictions[i][0] - restrictions[i-1][0])
        
        # peak = ha + x
        # peak = hb + d-x
        # ha + x = hb + d - x => 2x = hb - ha + d => x = (hb - ha + d)//2
        # peak = ha + x => ha + hb/2 - ha/2 + d/2 => ha/2 + hb/2 + d/2

        maxHeight = 0
        for i in range(n-2, -1, -1):
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + restrictions[i+1][0] - restrictions[i][0])
            a, ha = restrictions[i]
            b, hb = restrictions[i+1]

            d = b - a
            maxHeight = max(maxHeight, (ha + hb + d)//2)
        
        return maxHeight

        
