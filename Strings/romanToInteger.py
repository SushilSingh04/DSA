def romanToInt(s: str) -> int:
        val = 0
        # Start from the right end
        i = 0
        d = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        while i < len(s):
            # If next element has higher value then next-prev and increment by 2
            if i < len(s)-1 and d[s[i+1]] > d[s[i]]:
                val += d[s[i+1]] - d[s[i]]
                i += 2
            # else simply add the value
            else:
                val += d[s[i]]
                i += 1
        return val  

print(romanToInt('CVMIV'))