import re
def reverseWordsPythonic(s: str) -> str:
        s = s.strip()
        lst = re.split(r'\s+', s)[::-1]
        res = " ".join(lst)
        return res

s = 'The Sky  is  Blue'
res = reverseWordsPythonic(s)
print(res)