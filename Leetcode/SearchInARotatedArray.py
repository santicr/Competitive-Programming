class Solution:
    def search(self, nums: List[int], target: int) -> int:
        ans = [i for i in range(len(nums)) if nums[i] == target]
        if len(ans) > 0: return ans[0]
        else: return -1