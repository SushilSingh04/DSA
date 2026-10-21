class Solution:
    def minOperations(self, s: str) -> int:
        mn, mx = min(s), max(s)
        i = 0
        while i < len(s)-1:
            if s[i] > s[i+1]:
                break
            i+=1
        if i == len(s)-1:
            return 0
        elif s[0] == mn or s[-1] == mx:
            return 1
        elif len(s) == 2 and sorted(s) != s:
            return -1
        else:
            for i in range(1, len(s)-1):
                if s[i] == mn or s[i] == mx:
                    return 2
        return 3