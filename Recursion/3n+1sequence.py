def lenOfThree(n:int):
    if n == 1:
        return 1
    if n % 2 == 1:
        return 1 + lenOfThree(3*n+1)
    else:
        return 1+lenOfThree(n//2)
    
n = int(input())
print(lenOfThree(n))
# lenOfThree(3)
# 1+lenOfThree(10)
# 1+lenOfthree(5)
# 1 + lenOfThree(16) -> 7
# 1 + lenOfThree(8) -> 6
# 1 + lenOfThree(4) -> 4
# 1 + 2
# 1 + 1

