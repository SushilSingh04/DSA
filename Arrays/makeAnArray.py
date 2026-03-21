def solve (N, A):
    # Write your code here
    k = -1
    if sum(A) % (N-1) == 0:
        k = sum(A)//(N-1)
    if k >= max(A):
        return k
    else:
        return -1