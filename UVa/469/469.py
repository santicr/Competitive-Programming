from sys import stdin

mat = []
n, m = int(), int()

def bfs(nodo):
	global mat, n, m
	dx = [1, 0, -1, 0, 1, -1, -1, 1]
	dy = [0, -1, 0, 1, 1, -1, 1, -1]
	q = [nodo]
	ans = 1
	visited = [[0 for _ in range(m)] for _ in range(n)]
	visited[nodo[0]][nodo[1]] = 1

	while len(q) != 0:
		u = q[0]
		for i in range(8):
			x = u[0] + dx[i]
			y = u[1] + dy[i]

			if(x >= 0 and x < n and y >= 0 and y < m and visited[x][y] == 0 and mat[x][y] == 'W'):
				visited[x][y] = 1
				ans += 1
				q.append((x, y))
		q.pop(0)

	return ans

def main():
	global mat, n, m
	cases = int(input())
	l = input()
	x, y = int(), int()

	for i in range(cases):
		if i != 0:
			print()
		l = stdin.readline().strip()

		while(l[0] == 'L' or l[0] == 'W'):
			mat.append(l)
			l = stdin.readline().strip()

		n = len(mat)
		m = len(mat[0])

		while(l != ""):
			idx = 0

			for j in range(len(l)):
				if(l[j] == ' '):
					x = int(l[idx:j])
					idx = j + 1

			y = int(l[idx:len(l)])
			print(bfs((x - 1, y - 1)))

			l = stdin.readline().strip()
		mat = []

main()