class Solution:
    def chooseSwap(self, s):
        # code here
        n = len(s)
        firstIdx = [-1]*26
        
        for i in range(n):
            idx = ord(s[i]) - 97
            if firstIdx[idx] == -1:
                firstIdx[idx] = i
        
        for i in range(n):
            curr = ord(s[i]) - 97
            for c in range(curr):
                # starting from 'a' first letter that has the first occurance later than curr is the letter to swap
                if firstIdx[c] > i:
                    x = chr(97 + c)
                    y = s[i]
                    
                    res = ''
                    for i in range(len(s)):
                        if s[i] == x:
                            res += y
                        elif s[i] == y:
                            res += x
                        else:
                            res += s[i]
                    
                    for i in range(len(s)):
                        if res[i] > s[i]:
                            return s
                        elif res[i] < s[i]:
                            return res
        return s