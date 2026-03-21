def migratoryBirds(arr):
    # Write your code here
    maxCntVal = 0
    maxCnt = 0
    arr.sort()
    i = 0
    j = 1
    # Two pointer approach
    while i<len(arr)-1 and j<len(arr):    
        if arr[i] == arr[j]:
            j += 1
            if maxCnt < (j-i):
                maxCnt = j-i
                maxCntVal = arr[i]
        else:
            i = j
            j+=1
    return maxCntVal