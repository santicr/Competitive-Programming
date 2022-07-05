class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        vis = [[0 for _ in range(n)] for _ in range(n)]
        dist = [[-1 for _ in range(n)] for _ in range(n)]
        
        def bfs(u):
            q = [u]
            vis[u[0]][u[1]] = 1
            dist[u[0]][u[1]] = 1
            dx = [1, 0, 0, -1, 1, 1, -1, -1]
            dy = [0, 1, -1, 0, -1, 1, 1, -1]
            
            while len(q) != 0:
                x, y = q.pop(0)
                
                for i in range(8):
                    nx = dx[i] + x
                    ny = dy[i] + y
                    
                    if nx >= 0 and nx < n and ny >= 0 and ny < n and not grid[nx][ny]:
                        q.append((nx, ny))
                        grid[nx][ny] = 1
                        dist[nx][ny] = dist[x][y] + 1
            
        if not grid[0][0]:
            bfs((0, 0))
        
        return dist[n - 1][n - 1]