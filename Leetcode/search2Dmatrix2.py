class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def binSearch(lst, x):
            l, h = 0, len(lst)
            while l + 1 < h:
                m = (l + h) // 2
                if lst[m] > x:
                    h = m
                else:
                    l = m
            return lst[l]
        
        for i in range(len(matrix)):
            c = binSearch(matrix[i], target)
            if c == target:
                return True
        
        return False