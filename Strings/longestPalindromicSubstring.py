def longestPalindrome(s: str) -> str:
    res = ''
    resLen = 0
    for i in range(len(s)):
        # odd length palindrome
        l,r = i,i
        while l >= 0 and r < len(s) and s[l] == s[r]:
            if (r-l+1) > resLen:
                res_l = l
                res_r = r
                resLen = r-l+1
            l -= 1
            r += 1

        # Even length palindrome
        l,r = i,i+1
        while l>=0 and r<len(s) and s[l] == s[r]:
            if (r-l+1) > resLen:
                res_l = l
                res_r = r
                resLen = r-l+1
            l-=1
            r+=1
    return s[res_l:res_r+1]

# Example usage:
input_str = "babad"
print(longestPalindrome(input_str))  # Output could be "bab" or "aba"