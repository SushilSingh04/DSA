# 1. Calculate an LPS array for needle
# 2. 


def strStr(self, haystack: str, needle: str) -> int:
        lps = [0]*len(needle)
        prevLps,i = 0,1
        while i < len(needle):
            if needle[i] == needle[prevLps]:
                lps[i] = prevLps + 1 # index matched found till now +1
                prevLps += 1 # move the index prevLps by 1
                i += 1
            elif prevLps == 0:
                lps[i] = 0
                i += 1
            else:
                prevLps = lps[prevLps - 1] # Important
        
        i, j = 0, 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i, j = i+1, j+1
            elif j == 0:
                i += 1
            else:
                j = lps[j-1]
            if j == len(needle):
                return i - len(needle) # currently at the end of the needle
        return -1