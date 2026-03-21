a, b = map(int, input().split())

def solve(a,b):
    memo = [[-1]*(b+1) for i in range(a+1)]
    return minMoves(a,b,memo)

def minMoves(a, b, memo):
    if a == b:
        return 0
    if memo[a][b] != -1:
        return memo[a][b]
    ans = float('inf')
    # Horizontal Cutting
    for i in range(1,a):
        tmpAns = 1 + minMoves(i,b,memo)+minMoves(a-i,b,memo)
        ans = min(ans, tmpAns)
    
    # Vertical Cutting
    for i in range(1,b):
        tmpAns = 1 + minMoves(a,i,memo) + minMoves(a,b-i,memo)
        ans = min(ans, tmpAns)
    
    memo[a][b] = ans
    return ans

print(solve(a,b))