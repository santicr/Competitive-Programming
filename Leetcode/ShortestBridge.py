class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        vis = [[0 for _ in range(n)] for _ in range(n)]
        qglob = []
        
        def bfs(node, glob):
            nonlocal grid
            dx = [1, 0, 0, -1]
            dy = [0, 1, -1, 0]
            x, y = node
            q = [node]
            vis[x][y] = 1
            
            if not glob:
                while len(q) != 0:
                    x, y = q.pop(0)
                    for i in range(4):
                        nx = x + dx[i]
                        ny = y + dy[i]
                        if nx >= 0 and ny >= 0 and nx < n and ny < n and grid[nx][ny] and not vis[nx][ny]:
                            vis[nx][ny] = 1
                            q.append((nx, ny))
            else:
                while len(qglob) != 0:
                    x, y = qglob.pop(0)
                    for i in range(4):
                        nx = x + dx[i]
                        ny = y + dy[i]
                        if nx >= 0 and ny >= 0 and nx < n and ny < n and grid[nx][ny] and not vis[nx][ny]:
                            return vis[x][y] - 1
                        elif nx >= 0 and ny >= 0 and nx < n and ny < n and not grid[nx][ny] and not vis[nx][ny]:
                            vis[nx][ny] = vis[x][y] + 1
                            qglob.append((nx, ny))
                        

        for i in range(n):
            flag = 0
            for j in range(n):
                if grid[i][j]:
                    bfs((i, j), 0)
                    flag = 1
                    break
            if flag:
                break
        
        for i in range(n):
            for j in range(n):
                if vis[i][j] and grid[i][j]:
                    qglob.append((i, j))
        return (bfs((0, 0), 1))
        