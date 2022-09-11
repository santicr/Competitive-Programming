class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ans = ""
        n, m = len(board), len(board[0])
        
        def solve(sol, vis, x, y, idx):
            nonlocal ans
            if sol == word:
                ans = sol
            elif len(sol) < len(word):
                dx = [1, 0, 0, -1]
                dy = [0, 1, -1, 0]
                for i in range(4):
                    nx = dx[i] + x
                    ny = dy[i] + y
                    if nx >= 0 and ny >= 0 and ny < m and nx < n and vis[nx][ny] == 0 and board[nx][ny] == word[idx]:
                        vis[nx][ny] = 1
                        solve(sol + board[nx][ny], vis, nx, ny, idx + 1)
                        vis[nx][ny] = 0
        
        vis = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0]:
                    vis[i][j] = 1
                    solve(word[0], vis, i, j, 1)
                    vis[i][j] = 0
        return ans == word