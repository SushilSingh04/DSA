def longestSubarray(self, arr, k):  
    # code here
    d = {}
    pref = 0
    maxlen = 0
    for i in range(len(arr)):
        pref += arr[i]
        d[pref] = i
        if pref == k:
            maxlen = i+1
    
    pref = 0
    for i in range(len(arr)):
        new_target = pref + k
        pref += arr[i]
        if new_target in d:
            maxlen = max(maxlen, d[new_target]-i)
    return maxlen