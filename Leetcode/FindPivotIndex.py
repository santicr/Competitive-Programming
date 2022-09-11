class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        ans = -1
        acum = nums[0]
        acums = [nums[0]]
        res = []
        
        for i in range(1, len(nums)):
            acum += nums[i]
            acums.append(nums[i] + acums[i - 1])
        
        for i in range(len(nums)):
            if i == 0:
                res.append((0, acum - nums[i]))
            elif i == len(nums) - 1:
                res.append((acum - nums[i], 0))
            else:
                res.append((acums[i - 1], acum - acums[i]))
        
        for i in range(len(res)):
            if res[i][0] == res[i][1]:
                ans = i
                break
        
        return ans
            