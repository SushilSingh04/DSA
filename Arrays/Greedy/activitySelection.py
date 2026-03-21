# Optimal Substructure-
    # Sort on the basis of finish time
    # calculate number of tasks that can be finished


class Solution:
    def activitySelection(self, start, finish):
        #code here
        # (1,3) (3,4) (0,6) (5,7) (8,9) (5,9)
        tasks = []
        for beg, end in zip(start, finish):
            tasks.append((beg, end))
            
        tasks.sort(key=lambda t: t[1])

        # print(tasks)
        endTime = -1
        n = 0
        for st, end in tasks:
            if st > endTime:
                # print(st, end)
                n += 1
                endTime = end
        return n