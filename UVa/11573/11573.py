from sys import stdin

mat = []
n, m = int(), int()

def solve(ini, fin):
	global mat, n, m
	vis = [[float("inf") for _ in range(m)] for _ in range(n)]
	dx = [1, 0, 0, -1, 1, -1, -1, 1]
	dy = [0, 1, -1, 0, 1, -1, 1, -1]
	nums = {4:0, 2:1, 6:2, 0:3, 3:4, 7:5, 1:6, 5:7}
	q = [ini]

	vis[ini[0]][ini[1]] = 0

	while len(q) != 0:
		x, y = q.pop(0)
		num = int(mat[x][y])
		nx = dx[nums[num]] + x
		ny = dy[nums[num]] + y

		if nx >= 0 and ny >= 0 and nx < n and ny < m and vis[x][y] < vis[nx][ny]:
			q.append((nx, ny))
			vis[nx][ny] = vis[x][y]

		for i in range(8):
			nx = dx[i] + x
			ny = dy[i] + y

			if nx >= 0 and ny >= 0 and nx < n and ny < m and vis[x][y] + 1 < vis[nx][ny]:
				q.append((nx, ny))
				vis[nx][ny] = vis[x][y] + 1

	return vis[fin[0]][fin[1]]

def main():
	global mat, n, m
	n, m = tuple(map(int, stdin.readline().strip().split()))

	for i in range(n):
		temp = stdin.readline().strip()
		mat.append(temp)

	q = int(input())

	for i in range(q):
		ix, iy, fx, fy = tuple(map(int, stdin.readline().strip().split()))
		ix -= 1
		iy -= 1
		fx -= 1
		fy -= 1
		print(solve((ix, iy), (fx, fy)))


main()