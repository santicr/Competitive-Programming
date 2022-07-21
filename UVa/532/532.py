from sys import stdin

n, m, l = int(), int(), int()
levels = []

def bfs(x, y, z):
	global n, m, l, levels
	vis = {(x, y, z): 1}
	dx = [1, 0, 0, -1, 0]
	dy = [0, 1, -1, 0, 0]
	dz = [0, -1, 1]
	q = [(x, y, z)]

	while len(q) != 0:
		x, y, z = q.pop(0)

		for i in range(5):
			nx = x + dx[i]
			ny = y + dy[i]


	return False

def main():
	global n, m, l, levels
	l, n, m = map(int, stdin.readline().strip().split())
	x, y, z = 0, 0, 0

	for i in range(l):
		block = []
		for j in range(n):
			block.append(stdin.readline().strip())
		levels.append(block)

	for i in range(l):
		for j in range(n):
			for k in range(m):
				if levels[i][j][k] == 'S':
					z, x, y = i, j, k

	print(bfs(x, y, z))

main()