from sys import stdin

mat = []
n, m = -1, -1

def bfs():
	global mat, n, m
	dxh = [-2, -1, 1, 2, -2, -1, 1, 2]
	dyh = [1, 2, 2, 1, -1, -2, -2, -1]
	dxk = [1, 0, 0, -1, 1, 1, -1, -1]
	dyk = [0, 1, -1, 0, 1, -1, 1, -1]
	vis = [[float("inf") for _ in range(m)] for _ in range(n)]
	q = []
	end = tuple()

	for i in range(n):
		for j in range(m):
			if mat[i][j] == 'Z':
				for k in range(8):
					nx = dxh[k] + i
					ny = dyh[k] + j
					if nx >= 0 and ny >= 0 and nx < n and ny < m and mat[nx][ny] == '.':
						vis[nx][ny] = -1
			elif mat[i][j] == 'A':
				q.append((i, j))
				vis[i][j] = 0
			elif mat[i][j] == 'B':
				end = (i, j)

	while len(q) != 0:
		x, y = q.pop(0)
		for i in range(8):
			nx = dxk[i] + x
			ny = dyk[i] + y
			if nx >= 0 and ny >= 0 and nx < n and ny < m and mat[nx][ny] == '.' and vis[nx][ny] > vis[x][y] + 1:
				vis[nx][ny] = vis[x][y] + 1
				q.append((nx, ny))
			elif nx >= 0 and ny >= 0 and nx < n and ny < m and mat[nx][ny] == 'B' and vis[nx][ny] > vis[x][y] + 1:
				vis[nx][ny] = vis[x][y] + 1

	return vis[end[0]][end[1]]

def main():
	global n, m, mat
	t = int(input())

	for i in range(t):
		n, m = tuple(map(int, stdin.readline().strip().split()))
		mat = []

		for j in range(n):
			l = stdin.readline().strip()
			mat.append(l)

		ans = bfs()
		if ans == float("inf"):
			print("King Peter, you can't go now!")
		else:
			print(f"Minimal possible length of a trip is {ans}")

main()