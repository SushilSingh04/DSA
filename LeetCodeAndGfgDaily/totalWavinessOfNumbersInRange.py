class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        cnt = 0
        for val in range(num1, num2+1):
            s = str(val)
            for i in range(1,len(s)-1):
                if s[i] > s[i-1] and s[i] > s[i+1]:
                    cnt += 1
                elif s[i] < s[i-1] and s[i] < s[i+1]:
                    cnt += 1
        
        return cnt





