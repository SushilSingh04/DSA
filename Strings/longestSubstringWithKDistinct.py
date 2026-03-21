# Pattern: HashMap with sliding window (for maintaining a window of k size)

from collections import defaultdict

class Solution:
    def longestKSubstr(self, s, k):
        # code here
        i = 0
        freq = defaultdict(int)
        maxLen = -1
        for j in range(len(s)):
            freq[s[j]] += 1
            while len(freq) > k:
                freq[s[i]] -= 1
                if freq[s[i]] == 0:
                    del freq[s[i]]
                i += 1
            if len(freq) == k:
                maxLen = max(maxLen, j-i+1)
        return maxLen 