import math
n = int(input())

lst = list(map(int, [input() for _ in range(n)]))
# print(lst)
sq_rt = math.sqrt(n)
chunks = [float("inf")]*sq_rt
for i in range(n):
    chunks[i /sq_rt] = min(chunks[i /sq_rt], lst[i])