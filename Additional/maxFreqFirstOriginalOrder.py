lst = [int(val) for val in list(input().split())]
ll = []
for val in lst:
    if val not in ll:
        ll.append(val)

res = []
counts = []
for val in ll:
    counts.append(lst.count(val))

# print(counts)
for i in range(len(ll)):
    maxFreq = max(counts)
    index = counts.index(maxFreq)
    res += [ll[index]]*maxFreq
    counts[index] = 0

print(res)

# lst = []
# lst =    [4, 5, 4, 4, 3, 3, 6, 8]
# ll =     [4, 5, 3, 6, 8]
# counts = [3, 1, 2, 1, 1]

