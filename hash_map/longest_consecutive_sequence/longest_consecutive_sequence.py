from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        nums = sorted(nums)
        l = ml = 1
        for ix in range(len(nums) -1):
            diff = nums[ix+1] - nums[ix]
            if diff == 1:
                l+=1
            if diff > 1 or ix == len(nums)-2:
                ml = max(l, ml)
                l = 1
        return ml