def lengthOfLastWord(self, s: str) -> int:
    i = len(s)-1
    j = len(s)-1
    while j >= 0 and s[j] == ' ':
        j -= 1
    if j >= 0:
        i = j
    while i >= 0 and s[i] != ' ':
        i -= 1
    return j-i