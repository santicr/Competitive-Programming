class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[-1 for _ in range(n)] for _ in range(n)]
        val = 1
        d = 0
        i, j = 0, 0
        
        def fill(mat, direc, val, i, j):
            n = len(mat)
            if direc == 0:
                while(j < n and mat[i][j] == -1):
                    mat[i][j] = val
                    val += 1
                    j += 1
                return val, i + 1, j - 1
            elif direc == 1:
                while(i < n and mat[i][j] == -1):
                    mat[i][j] = val
                    val += 1
                    i += 1
                return val, i - 1, j - 1
            elif direc == 2:
                while(j >= 0 and mat[i][j] == -1):
                    mat[i][j] = val
                    val += 1
                    j -= 1
                return val, i - 1, j + 1
            elif direc == 3:
                while(i >= 0 and mat[i][j] == -1):
                    mat[i][j] = val
                    val += 1
                    i -= 1
                return val, i + 1, j + 1
        
        while(val != n * n):
            val, i, j = fill(ans, d % 4, val, i, j)
            d += 1
        print(i, j)
        ans[i][j] = n * n
            
        return ans
        