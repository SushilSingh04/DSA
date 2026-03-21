def generateParens(n):
    allParens = []
    def backtrack(open_count, close_count, currString):
        if len(currString) == 2*n:
            allParens.append(currString)
            return
        if open_count < n:
            backtrack(open_count+1, close_count, currString+'(')
        if close_count < open_count:
            backtrack(open_count, close_count+1, currString+')')
    backtrack(0,0,'')
    return allParens

print(generateParens(3))