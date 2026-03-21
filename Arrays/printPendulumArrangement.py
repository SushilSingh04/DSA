def pendulumArrangement(self,arr):
    # code here
    n = len(arr)
    res = [0]*n
    arr.sort()
    
    if n%2 == 0:
        i = (n-1)//2
    else:
        i = n//2
        
    dist = 1
    res[i] = arr[0]
    j=1
    while j < n:
        res[i+dist*1] = arr[j]
        j += 1
        if j < n:
            res[i+dist*-1] = arr[j]
        j += 1
        dist += 1
    
    return res

arr = [4, 3, 2, 1, 5, 6]
print(pendulumArrangement(None, arr))  # Output: [5, 3, 1, 2, 4, 6]