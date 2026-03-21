def minIncrements(self, arr): 
    arr.sort()
    i = 0
    cnt = 0
    while i < len(arr)-1:
        if arr[i] >= arr[i+1]:
            cnt += arr[i] - arr[i+1]+1
            arr[i+1] = arr[i]+1
        i += 1
    return cnt