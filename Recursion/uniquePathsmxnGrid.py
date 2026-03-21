# def uniquePaths(n: int, m:int):
#     # Only one possible path: a straight line
#     if n == 0 or m == 0:
#         return 1 
#     # sum of paths from left and right
#     return uniquePaths(n-1,m)+uniquePaths(n,m-1)

# print(uniquePaths(4,5))
#          2,3                 3,2
#      1,3     2,2          2,2    3,1
#   0,3   1,2  1,2 2,1  1,2 2,1  2,1 3,0
# 3,5     4,4
# 3,5     4,4
# n = int(input())
def printDigits(n):
    if n == 0:
        print(0)
        return
    def helperPrint(n):
        if n == 0:
            return 
        helperPrint(n//10)
        print(n % 10, end=" ")
    helperPrint(n)

printDigits(121)