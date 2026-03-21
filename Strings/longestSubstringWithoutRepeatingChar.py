from collections import Counter
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLen = 0
        l = 0
        r = 0
        d = {}
        while r < len(s):
            char = s[r]
            if char in d and d[char] >= l:
                l = d[char]+1
            d[char] = r
            maxLen = max(r-l+1, maxLen)
            r += 1
        return maxLen
