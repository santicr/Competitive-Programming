from sys import stdin

n, m = int(), int()
grid = []

def bfs(ns, nf):
	global n, m, grid
	q = [ns]
	padres = [[float("inf") for _ in range(m)] for _ in range(n)]
	padres[ns[0]][ns[1]] = 0
	dx = [0, 1, 0, -1, 1, 1, -1, -1]
	dy = [1, 0, -1, 0, 1, -1, 1, -1]
	dxn = [-1, -1, 0, 1, 1, 1, 0, -1]
	dyn = [0, 1, 1, 1, 0, -1, -1, -1]

	while len(q) != 0:
		x, y = q.pop(0)
		idx = int(grid[x][y])
		nxn = dxn[idx] + x
		nyn = dyn[idx] + y

		if nxn >= 0 and nxn < n and nyn >= 0 and nyn < m and padres[x][y] < padres[nxn][nyn]:
			q.append((nxn, nyn))
			padres[nxn][nyn] = padres[x][y]

		for i in range(8):
			nx = dx[i] + x
			ny = dy[i] + y

			if nx >= 0 and nx < n and ny >= 0 and ny < m and padres[x][y] + 1 < padres[nx][ny]:
				q.append((nx, ny))
				padres[nx][ny] = padres[x][y] + 1

	return padres[nf[0]][nf[1]]

def main():
	global n, m, grid
	n, m = map(int, stdin.readline().strip().split())

	for i in range(n):
		grid.append(stdin.readline().strip())

	q = int(input())

	for i in range(q):
		xi, yi, xf, yf = map(int, stdin.readline().strip().split())
		ans = bfs((xi - 1, yi - 1), (xf - 1, yf - 1))
		print(ans)

main()