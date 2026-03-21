
# Similar to the profile Aggressive Cows
# Instead of minimizing distances it's the difference between elements

def maxMinDiff(self, arr, k):
    # code here
    # 0 1 2 3 4 9 13
    # 0 1 2 3 4 5 6 7 8 9 10 11 12 13
    # l
    #             m
    #                               h
    nums = sorted(arr)
    low = 0
    high = nums[-1] - nums[0]
    ans = 0
    while low <= high:
        mid = (low + high)//2
        if self.fitKElements(nums, mid, k):
            ans = mid
            low = mid+1
        else:
            high = mid-1
    return ans # or high
        
def fitKElements(self,nums, min_dist, k):
    count = 1 # first element already placed at index 0
    j = 0 # where to place the next element
    for i in range(1,len(nums)):
        if nums[i] - nums[j] >= min_dist:
            j = i
            count += 1
        if count == k: # k elements can be placed, return True
            return True
    return False