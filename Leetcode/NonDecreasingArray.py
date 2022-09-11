class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        def isAsc(arr):
            for i in range(len(arr) - 1):
                if arr[i] > arr[i + 1]:
                    return False
            return True
    
        breakPoints = 0
        
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                breakPoints += 1
                if i + 2 >= len(nums):
                    nums[i + 1] = nums[i]
                elif i + 2 < len(nums):
                    if nums[i + 2] > nums[i]:
                        nums[i + 1] = nums[i]
                    else:
                        nums[i] = nums[i + 1]
        print(nums)
        
        if breakPoints == 0: return True
        if breakPoints == 1 and isAsc(nums): return True
        return False