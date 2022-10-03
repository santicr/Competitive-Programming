class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        j = 0
        new = []
        
        while(j < len(matrix)):
            new_mat = []
            i = len(matrix) - 1 
            while(i >= 0):
                new_mat.append(matrix[i][j])
                i -= 1
            new.append(new_mat)
            j += 1
        
        for i in range(len(matrix)):
            matrix[i] = new[i]
            
        