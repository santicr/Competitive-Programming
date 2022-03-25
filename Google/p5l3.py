def solution(mat):
	dx = [1, -1, 0, 0]
	dy = [0, 0, 1, -1]
	n = len(mat)
	m = len(mat[0])
	cola = [(0, 0, 0)]
	vis = [[[0 for _ in range(m)] for _ in range(n)], [[0 for _ in range(m)] for _ in range(n)]]
	vis[0][0][0] = 1
	ans = float("inf")

	while len(cola) != 0:
		u = cola[0]

		for i in range(4):
			x = u[0] + dx[i]
			y = u[1] + dy[i]
			z = u[2]

			if(x >= 0 and x < n and y >= 0 and y < m and vis[z][x][y] == 0):
				if((z == 0 or z == 1) and mat[x][y] == 0):
					v = (x, y, z)
					vis[z][x][y] = vis[z][u[0]][u[1]] + 1				
					cola.append(v)
					if(x == n - 1 and y == m - 1):
						ans = min(ans, vis[z][x][y])
				elif(z == 0 and mat[x][y] == 1):
					v = (x, y, 1)
					vis[1][x][y] = vis[z][u[0]][u[1]] + 1				
					cola.append(v)
					if(x == n - 1 and y == m - 1):
						ans = min(ans, vis[1][x][y])

		cola.pop(0)

	return ans

def main():
	M = [[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]
	for i in range(len(M)):
		print(M[i])
	print(solution(M))

main()