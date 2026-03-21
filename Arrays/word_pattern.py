# 290 leetcode
# Create two hashmaps

def wordPattern(self, pattern: str, s: str) -> bool:
    lst_s = s.split(" ")
    d_ch = {}
    d_word = {}
    if len(lst_s) != len(pattern):
        return False
    for i in range(len(pattern)):
        ch = pattern[i]
        word = lst_s[i]
        if ch not in d_ch:
            d_ch[ch] = word
        if word not in d_word:
            d_word[word] = ch
        if word in d_word or ch in d_ch:
            if d_word[word] != ch or d_ch[ch] != word:
                return False
    return True