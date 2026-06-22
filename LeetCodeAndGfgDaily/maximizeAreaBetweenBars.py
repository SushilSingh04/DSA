class Solution:
    def maxArea(self, height):
        # code here
        i = 0
        j = len(height)-1
        maxArea = 0
        
        while i < j:
            # maxArea depends on width and minimum of height[i] and height[j]
            maxArea = max(maxArea, (j - i - 1)*min(height[i], height[j]))
            
            # Safe to discard i when it is less than equal to j
            if height[i] <= height[j]:
                i += 1
            else:
                j -= 1
                
        
        return maxArea
