def bitwiseComplement(self, n: int) -> int:
    tmp = n
    cnt = 0
    while tmp > 0:
        tmp //= 2
        cnt += 1
    if n == 0:
        return 1
    return 2**cnt - n - 1