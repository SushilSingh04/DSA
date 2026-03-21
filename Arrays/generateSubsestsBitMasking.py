n = int(input())
# l = input().split(" ")
lst = [1,2,3,4]

for mask in range(1<<n):
    subset = []
    for i in range(n):
        if mask & (1 << i):
            subset.append(lst[i])
    for i in range(len(subset)):
        print(subset[i], end=" ")
    print()