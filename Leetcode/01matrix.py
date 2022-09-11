class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        vis = [[0 for _ in range(m)] for _ in range(n)]
        dist = [[float("inf") for _ in range(m)] for _ in range(n)]
        flag = False
        
        def bfs(u):
            x, y = u[0], u[1]
            vis[x][y] = 1
            q = [u]
            dist[x][y] = 0
            dx = [0, 1, -1, 0]
            dy = [1, 0, 0, -1]
            
            while len(q) != 0:
                x, y = q.pop(0)
                
                for i in range(4):
                    nx = x + dx[i]
                    ny = y + dy[i]
                    
                    if nx >= 0 and nx < n and ny >= 0 and ny < m and not mat[nx][ny] and vis[nx][ny] == 0:
                        vis[nx][ny] = 1
                        dist[nx][ny] = 0
                        q.append((nx, ny))
                    elif nx >= 0 and nx < n and ny >= 0 and ny < m and mat[nx][ny] and dist[x][y] + 1 < dist[nx][ny]:
                        dist[nx][ny] = dist[x][y] + 1
                        q.append((nx, ny))
            
        for i in range(n):
            for j in range(m):
                if not mat[i][j]:
                    bfs((i, j))
                    flag = True
                    break
            if flag:
                break
        
        return dist