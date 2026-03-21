def frequencySort(s: str) -> str:
        d = {}
        for ch in s:
            d[ch] = d.get(ch,0)+1
        
        d = sorted(d.items(), key = lambda x: -x[1])
        res = ""
        for k,v in d:
            res += k*v
        return res
s = "tree"
print(frequencySort(s))