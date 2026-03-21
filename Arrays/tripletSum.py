def hasTripletSum(self, arr, target):
    # Code Here
    arr.sort()
    n = len(arr)
    for i in range(n-2):
        st = i+1
        end = n-1
        new_target = target - arr[i]
        while st < end:
            if arr[st]+arr[end] > new_target:
                end -= 1
            elif arr[st]+arr[end] < new_target:
                st += 1
            else:
                return True
    return False
        