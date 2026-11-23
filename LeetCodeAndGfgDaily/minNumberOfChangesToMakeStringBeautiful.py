class Solution:
    def minChanges(self, s: str) -> int:
        i=cnt = 0
        while i < len(s)-1:
            if s[i] != s[i+1]:
                cnt += 1    
            i+=2
        
        return cnt
    