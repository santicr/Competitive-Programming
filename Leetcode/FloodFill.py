class Solution(object):
    def floodFill(self, image, sr, sc, color):
        mat = image
        n = len(image)
        m = len(image[0])
        vis = [[0 for _ in range(m)] for _ in range(n)]
        vis[sr][sc] = 1
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        q = [(sr, sc)]
        
        while len(q) != 0:
            x, y = q.pop(0)
            
            for i in range(4):
                nx = dx[i] + x
                ny = dy[i] + y
                
                if nx >= 0 and nx < n and ny >= 0 and ny < m and vis[nx][ny] == 0:
                    vis[nx][ny] = 1
                    if mat[nx][ny] == mat[sr][sc]:
                        mat[nx][ny] = color
                        q.append((nx, ny))
        mat[sr][sc] = color
        return image
                        