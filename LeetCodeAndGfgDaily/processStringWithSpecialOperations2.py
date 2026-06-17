class Solution:
    def processStr(self, s: str, k: int) -> str:
        n = len(s)
        L = 0

        # Calculating final length after processing
        for ch in s:
            if ch == '*':
                if L > 0:
                    L -= 1
            elif ch == '#':
                L = L*2
            elif ch == '%':
                continue
            else:
                L += 1
        # k is out of bounds      
        if k >= L:
            return '.'
        
        
        for i in range(n-1,-1,-1):
            if s[i] == '*':
                L += 1
            elif s[i] == '#':
                L //= 2
                if k >= L:
                    k = k - L
            elif s[i] == '%':
                k = L - k - 1
            else:
                L -= 1
            if L == k:
                return s[i]

            