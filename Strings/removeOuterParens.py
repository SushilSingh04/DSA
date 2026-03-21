

def removeOutermostParens(s:str) -> str:
    res = ''
    depth = 0
    for ch in s:
        if ch == '(':
            depth+=1
            if depth > 1:
                res += "("
        else:
            depth-=1
            if depth > 0:
                res += ")"
    return res

s = '(()())()'
print(removeOutermostParens(s))