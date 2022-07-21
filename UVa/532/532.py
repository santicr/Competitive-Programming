from sys import stdin

n, m, l = int(), int(), int()
levels = []

def bfs(x, y, z):
	global n, m, l, levels
	vis = {(x, y, z): 1}
	dx = [1, 0, 0, -1, 0]
	dy = [0, 1, -1, 0, 0]
	dz = [-1, 1]
	q = [(x, y, z)]
	padres = [[[0 for _ in range(m)] for _ in range(n)] for _ in range(l)]

	while len(q) != 0:
		x, y, z = q.pop(0)

		for i in range(5):
			nx = x + dx[i]
			ny = y + dy[i]

			if nx >= 0 and nx < n and ny >= 0 and ny < m and nx == x and ny == y and levels[z][nx][ny] != '#':
				for i in range(2):
					nz = dz[i] + z
					if nz >= 0 and nz < l and levels[nz][nx][ny] != '#' and (nx, ny, nz) not in vis:
						q.append((nx, ny, nz))
						padres[nz][nx][ny] = padres[z][x][y] + 1
						if levels[nz][nx][ny] == 'E':
							return 'Escaped in ' + str(padres[nz][nx][ny]) + ' minute(s).'
						vis[(nx, ny, z)] = 1

			elif nx >= 0 and nx < n and ny >= 0 and ny < m and levels[z][nx][ny] != '#' and (nx, ny, z) not in vis:
				vis[(nx, ny, z)] = 1
				padres[z][nx][ny] = padres[z][x][y] + 1
				if levels[z][nx][ny] == 'E':
					return 'Escaped in ' + str(padres[z][nx][ny]) + ' minute(s).'
				q.append((nx, ny, z))

	return 'Trapped!'

def main():
	global n, m, l, levels
	l, n, m = map(int, stdin.readline().strip().split())

	while l or n or m:
		levels = []
		x, y, z = 0, 0, 0

		for i in range(l):
			block = []
			for j in range(n):
				block.append(stdin.readline().strip())
			stdin.readline()
			levels.append(block)

		for i in range(l):
			for j in range(n):
				for k in range(m):
					if levels[i][j][k] == 'S':
						z, x, y = i, j, k

		print(bfs(x, y, z))

		l, n, m = map(int, stdin.readline().strip().split())

main()