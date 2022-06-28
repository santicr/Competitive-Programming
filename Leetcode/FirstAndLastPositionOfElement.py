class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        i = bisect_left(nums, target)
        j = bisect_right(nums, target)
        
        if i < len(nums) and nums[i] == target:
            return [i, j - 1]
        
        return [-1, -1]