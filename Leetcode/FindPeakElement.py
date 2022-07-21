class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        ans = 0
        max_num = -2**31 - 2
        for i in range(len(nums)):
            if nums[i] > max_num:
                max_num = nums[i]
                ans = i
        return ans