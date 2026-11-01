class Solution:
    def minMoves(self, nums: list[int]) -> int:
        # 4 10 20 -> 20 26 20 -> 26 26 26 => moves = 20-4 + 10-4
        # 4 10 9  -> 10 10 15 -> 15 15 15 => moves = 9-4 + 10-4 = 11
        # 2 3 10 10 -> 10 11 18 10 -> moves = 8 + 8 + 1
        moves = 0
        min_ele = min(nums)
        for val in nums:
            moves += val - min_ele

        return moves
