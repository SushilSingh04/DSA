class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        val = abs(30*(hour%12) - 11*minutes/2)
        if val > 180:
            val = 360 - val
            
        return val