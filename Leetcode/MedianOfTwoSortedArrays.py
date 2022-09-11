class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n = len(nums1)
        m = len(nums2)
        arr = nums1 + nums2
        arr.sort()
        
        if (n + m) % 2 != 0:
            return float(arr[(n + m) // 2])
        elif (n + m) % 2 == 0:
            return float((arr[(n + m) // 2] + arr[((n + m) // 2) - 1]) / 2)
            