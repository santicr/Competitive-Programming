class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        vis = [[0 for _ in range(n)] for _ in range(n)]
        dist = [[float("inf") for _ in range(n)] for _ in range(n)]
        
        def bfs(u):
            q = [u]
            vis[u[0]][u[1]] = 1
            dx = [0, 1, -1, 0]
            dy = [1, 0, 0, -1]
            dist[u[0]][u[1]] = 0
            
            while len(q) != 0:
                u = q.pop(0)
                
                for i in range(4):
                    x = dx[i] + u[0]
                    y = dy[i] + u[1]
                
                    if x >= 0 and x < n and y >= 0 and y < n and not grid[x][y] and dist[x][y] > dist[u[0]][u[1]] + 1:
                        dist[x][y] = dist[u[0]][u[1]] + 1
                        q.append((x, y))
                    elif x >= 0 and x < n and y >= 0 and y < n and grid[x][y] and vis[x][y] == 0:
                        vis[x][y] = 1
                        dist[x][y] = 0
                        q.append((x, y))
        
        for i in range(n):
            flag = False
            for j in range(n):
                if grid[i][j]:
                    bfs((i, j))
                    flag = True
                    break
            if flag:
                break
        
        ans = -1
        for i in range(n):
            for j in range(n):
                if dist[i][j] != float("inf") and dist[i][j] != 0:
                    ans = max(ans, dist[i][j])
        
        return ans
                