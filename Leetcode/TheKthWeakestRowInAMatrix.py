class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        arr = []
        for i in range(len(mat)):
            ones = 0
            for j in range(len(mat[i])):
                if mat[i][j] == 1:
                    ones += 1
            arr.append((i, ones))
        
        arr.sort(key = lambda x : (x[1], x[0]))
        
        ans = [arr[i][0] for i in range(k)]
        
        return ans