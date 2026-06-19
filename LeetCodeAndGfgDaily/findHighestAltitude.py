from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        maxAltitude = 0
        currAltitude = 0
        
        for stepGain in gain:
            currAltitude += stepGain
            maxAltitude = max(maxAltitude, currAltitude)
        
        return maxAltitude