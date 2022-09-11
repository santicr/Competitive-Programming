from sys import stdin

mat = []
visited = []
dx = [0, 1, -1, 0]
dy = [1, 0, 0, -1]
n = int()

def bfs(nodo):
	global mat, visited, n
	visited[nodo[0]][nodo[1]] = 1
	cola = [nodo]

	while len(cola) != 0:
		u = cola.pop()

		for i in range(4):
			x = u[0] + dx[i]
			y = u[1] + dy[i]

			if x >= 0 and x < n and y >= 0 and y < n and visited[x][y] == 0 and (mat[x][y] == 'x' or mat[x][y] == '@'):
				visited[x][y] = 1
				cola.append((x, y))


def main():
	global visited, n, mat
	cases = int(input())
	t = 0
	while t < cases:
		n = int(input())
		mat = [[' ' for _ in range(n)] for _ in range(n)]
		visited = [[0 for _ in range(n)] for _ in range(n)]
		ans = 0

		for i in range(n):
			mat[i] = stdin.readline().strip()

		for i in range(n):
			for j in range(n):
				if(visited[i][j] == 0 and mat[i][j] == 'x'):
					bfs((i, j))
					ans += 1

		print("Case " + str(t + 1) + ': ', end = "")
		print(ans)

		t += 1

main()