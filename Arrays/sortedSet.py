from sortedcontainers import SortedSet

s = SortedSet([5,3,1,2])
# 1 2 3 4
size = 4
print(s.discard)
print((s[size//2]+s[size//2-1])/2)