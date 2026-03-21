# nCr = n-1 C r-1 + n-1 C r
def nCr(n:int, r:int):
    if r > n:
        return 0
    if n == 0 or r == 0 or r == n:
        return 1
    return nCr(n-1,r-1) + nCr(n-1,r)

(n,r) = tuple(map(int, input().split(" ")))
n,r = 6,2

# print(nCr(n,r))
# nCr(6,2)
# nCr(5,1) + nCr(5,2)
# nCr(4,1) + 1 + nCr(4,2) + nCr(4,1)
# nCr(3,1) + 1 +  nCr(3,2) + nCr()
# nCr(2,1) + nCr(2,1) + nCr(2,2)
# nCr(1,0)->1 + nCr(1,1)
#               nCr()
