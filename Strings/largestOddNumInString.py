def largestOddNumber(s:str):
    i=len(s)-1
    while i>=0:
        if (ord(s[i]) - ord('0')) % 2 == 1:
            return s[:i+1]
        i-=1
    return ""
print(largestOddNumber("275666666"))