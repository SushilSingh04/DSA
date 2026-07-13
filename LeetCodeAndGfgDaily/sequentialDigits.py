from typing import List

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        digits = '123456789'
        low_s = str(low)
        high_s = str(high)
        res = []

        curr_len = len(low_s)

        while curr_len <= 9:
            i = 0
            while i + curr_len <= 9:
                curr_s = digits[i:curr_len + i]
                if len(curr_s) > len(high_s) or (len(curr_s) == len(high_s) and curr_s > high_s):
                    return res
                elif (len(curr_s) == len(low_s) and curr_s >= low_s) or len(curr_s) > len(low_s):
                    res.append(int(curr_s))
                i += 1
            curr_len += 1
        
        return res