class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        arr2.sort()
        n = len(arr2)
        cnt = 0

        def find_closest(val):
            low, high = 0, n-1
            if val <= arr2[0]:
                return arr2[0]
            if val >= arr2[n-1]:
                return arr2[n-1]
            
            while low <= high:
                mid = (low + high)//2
                if val == arr2[mid]:
                    return arr2[mid]
                elif val > arr2[mid]:
                    low = mid+1
                else:
                    high = mid-1
            # print(low, high, val)
            if abs(val - arr2[low]) > abs(val - arr2[high]):
                return arr2[high]
            else:
                return arr2[low]
                
        for val in arr1:
            ans = find_closest(val)
            if abs(ans - val) > d:
                cnt += 1
    
        return cnt
