from sys import stdin

n, m = int(), int()

def bfs(node, end, mat):
	global n, m
	q = [node]
	x, y = node
	dx = [1, 0, 0, -1]
	dy = [0, 1, -1, 0]
	vis = [[float("inf") for _ in range(m)] for _ in range(n)]
	ans = -1
	vis[x][y] = 0

	while len(q) != 0:
		x, y = q.pop(0)
		if x == end[0] and y == end[1]:
			ans = vis[x][y]
		for i in range(4):
			nx = dx[i] + x
			ny = dy[i] + y
			if nx >= 0 and ny >= 0 and nx < n and ny < m and mat[nx][ny]:
				q.append((nx, ny))
				mat[nx][ny] = 0
				vis[nx][ny] = vis[x][y] + 1
	return ans

def main():
	global n, m
	line = stdin.readline().strip().split()
	n, m = tuple(map(int, line))

	while n != 0 or m != 0:
		mat = [[1 for _ in range(m)] for _ in range(n)]
		rows = int(input())

		for i in range(rows):
			lst = list(map(int, stdin.readline().strip().split()))
			r = lst[0]
			for j in range(2, len(lst)):
				if lst[j] < m:
					mat[r][lst[j]] = 0

		start = tuple(map(int, stdin.readline().strip().split()))
		end = tuple(map(int, stdin.readline().strip().split()))
		ans = bfs(start, end, mat)

		print(ans)

		line = stdin.readline().strip().split()
		n, m = tuple(map(int, line))

main()