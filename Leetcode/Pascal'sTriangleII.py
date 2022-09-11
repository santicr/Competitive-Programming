class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        pascal = [[1], [1, 1]]
        
        for i in range(2, rowIndex + 1):
            temp = []
            temp.append(1)
            
            for j in range(len(pascal[i - 1]) - 1):
                temp.append(pascal[i - 1][j] + pascal[i - 1][j + 1])
                
            temp.append(1)
            pascal.append(temp)
        
        return pascal[rowIndex]