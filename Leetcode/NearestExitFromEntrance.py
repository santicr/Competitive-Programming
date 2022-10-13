class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        n, m = len(maze), len(maze[0])
        start = tuple(entrance)
        
        def bfs(node):
            nonlocal maze
            q = [node]
            vis = [[-1 for _ in range(m)] for _ in range(n)]
            dx = [1, 0, 0, -1]
            dy = [0, 1, -1, 0]
            x, y = node
            vis[x][y] = 0
            
            while len(q) != 0:
                x, y = q.pop(0)
                for i in range(4):
                    nx = dx[i] + x
                    ny = dy[i] + y
                    if nx >= 0 and ny >= 0 and nx < n and ny < m and maze[nx][ny] == '.' and vis[nx][ny] == -1:
                        q.append((nx, ny))
                        vis[nx][ny] = vis[x][y] + 1
                        if nx == 0 or nx == n - 1 or ny == 0 or ny == m - 1:
                            return vis[nx][ny]
            
            return -1
        
        return bfs(start)