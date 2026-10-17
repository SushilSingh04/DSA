class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        digit_sum = lambda x: sum(map(int, str(x)))
        final_pos = {x:k for k, x in enumerate(sorted(nums, key = lambda x:(digit_sum(x), x)))}

        goto_pos = [final_pos[x] for x in nums]
        # [0 1 2 3]
        swaps = 0
        
        for i in range(len(nums)):
            while goto_pos[i] != i:
                f_pos = goto_pos[i]
                goto_pos[i], goto_pos[f_pos] = goto_pos[f_pos], goto_pos[i]
                swaps += 1
        
        return swaps