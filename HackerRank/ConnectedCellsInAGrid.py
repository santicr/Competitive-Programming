from sys import stdin
visited = {}
grid = []

def bfs(i, j):
	global visited, grid
	visited[(i, j)] = 1
	cola = [(i, j)]
	dx = [0, 0, 1, 1,-1,-1,-1, 1]
	dy = [1,-1, 1,-1, 1, -1, 0, 0]
	ans = 1
	n = len(grid)
	m = len(grid[0])

	while len(cola) != 0:
		for i in range(8):
			x = cola[0][0] + dx[i]
			y = cola[0][1] + dy[i]
			if x >= 0 and x < n and y >= 0 and y < m and (x, y) not in visited and grid[x][y] == 1:
				cola.append((x, y))
				visited[(x, y)] = 1
				ans += 1
		cola.pop(0)

	return ans

def solve(n, m):
	global visited, grid
	ans = -float("inf")
	for i in range(n):
		for j in range(m):
			if grid[i][j] == 1 and (i, j) not in visited:
				ans = max(bfs(i, j), ans)
	return ans

def main():
	global visited, grid
	n = int(input())
	m = int(input())

	for i in range(n):
		linea = stdin.readline()
		linea = linea.split()
		t = []
		for j in range(m):
			t.append(int(linea[j]))
		grid.append(t)

	print(solve(n, m))

main()