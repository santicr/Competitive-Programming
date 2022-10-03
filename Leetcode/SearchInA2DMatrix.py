class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def binSearch(arr, x):
            l, h = 0, len(arr)
            while(l + 1 < h):
                mid = (l + h) // 2
                if arr[mid] > x:
                    h = mid
                else:
                    l = mid
            return l
        
        for i in range(len(matrix)):
            idx = binSearch(matrix[i], target)
            if matrix[i][idx] == target:
                return True
        return False