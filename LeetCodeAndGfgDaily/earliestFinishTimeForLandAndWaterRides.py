from typing import List
class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        n_land = len(landStartTime)
        n_water = len(waterStartTime)
        minFinishTime = float('inf')
        minLandFinishTime = float('inf')
        minWaterFinishTime = float('inf')

        for i in range(n_land):
            finishTime = landStartTime[i] + landDuration[i]
            minLandFinishTime = min(minLandFinishTime, finishTime)
            
        # print(minLandFinishTime)

        for i in range(n_water):
            finishTime = waterStartTime[i] + waterDuration[i]
            minWaterFinishTime = min(minWaterFinishTime, finishTime)
            if waterStartTime[i] <= minLandFinishTime:
                minFinishTime = min(minLandFinishTime + waterDuration[i], minFinishTime)
            else:
                minFinishTime = min(waterStartTime[i] + waterDuration[i], minFinishTime)


        # print(minFinishTime)
        for i in range(n_land):
            if landStartTime[i] <= minWaterFinishTime:
                minFinishTime = min(minWaterFinishTime + landDuration[i], minFinishTime)
            else:
                minFinishTime = min(landStartTime[i] + landDuration[i], minFinishTime)


        return minFinishTime
                

