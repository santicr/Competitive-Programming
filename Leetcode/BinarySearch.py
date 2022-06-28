class Solution(object):
    def search(self, nums, target):
        def binSearch(arr, x):
            l, h = 0, len(arr)
            while(l + 1 < h):
                m = (l + h) // 2
                if arr[m] > x:
                    h = m
                else:
                    l = m
            return l
    
        nums.sort()
        
        ans = -1
        i = binSearch(nums, target)
        
        if nums[i] == target:
            ans = i
        return ans