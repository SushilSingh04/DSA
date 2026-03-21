def removeElement(nums, val: int) -> int:
    i = 0
    n = len(nums)
    j = n-1
    while j >= 0 and nums[j] == val:
        j -= 1
    
    while i <= j:
        if nums[i] == val:
            tmp = nums[i]
            nums[i] = nums[j]
            nums[j] = tmp
            j -= 1
        i += 1
        while nums[j] == val:
            j -= 1
    return j+1