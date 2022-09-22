from sys import stdin

n, m, query = int(), int(), int()
dic = {}
vis1, vis2 = [], []


def bfsQueen():
	global n, m, query, dic, vis1
	dx = [1, 0, 0, -1]
	dy = [0, -1, 1, 0]
	q = []
	vis1 = [[0 for _ in range(8)] for _ in range(8)]
	vis1[dic[m][0]][dic[m][1]] = 1

	for i in range(4):
		nx = dx[i] + dic[m][0]
		ny = dy[i] + dic[m][1]

		if nx >= 0 and nx < 8 and ny >= 0 and ny < 8 and not (nx == dic[n][0] and ny == dic[n][1]):
			q.append((nx, ny, i))
			vis1[nx][ny] = 1

	while len(q) != 0:
		x, y, it = q.pop(0)
		nx = dx[it] + x
		ny = dy[it] + y

		if nx >= 0 and ny >= 0 and nx < 8 and ny < 8 and not (nx == dic[n][0] and ny == dic[n][1]):
			q.append((nx, ny, it))
			vis1[nx][ny] = 1

def bfsKing():
	global n, m, query, dic, vis2
	dx = [1, 0, 0, -1]
	dy = [0, -1, 1, 0]
	q = []
	vis2 = [[0 for _ in range(8)] for _ in range(8)]
	vis2[dic[n][0]][dic[n][1]] = 1

	for i in range(4):
		nx = dx[i] + dic[n][0]
		ny = dy[i] + dic[n][1]

		if nx >= 0 and nx < 8 and ny >= 0 and ny < 8 and not (nx == dic[m][0] and ny == dic[m][1]):
			q.append((nx, ny, i))
			vis2[nx][ny] = 1

def prints():
	for el in vis1:
		print(el)

	print()

	for el in vis2:
		print(el)

def main():
	global n, m, query
	line = stdin.readline().strip()
	idx = 0

	for i in range(8):
		for j in range(8):
			dic[idx] = (i, j)
			idx += 1

	while line != "":
		ams = ""
		n, m, query = tuple(map(int, line.split()))

		if n == m:
			ans = "Illegal state"

		else:
			x, y = dic[query]
			bfsQueen()
			bfsKing()

			if not vis1[x][y] or m == query:
				ans = "Illegal move"

			elif vis1[x][y] and vis2[x][y]:
				ans = "Move not allowed"

			else:
				m = query
				bfsQueen()
				vis2[dic[n][0]][dic[n][1]] = 0
				ans = "Stop"

				for i in range(8):
					for j in range(8):
						if vis2[i][j] and not vis1[i][j]:
							ans = "Continue"

		print(ans)

		line = stdin.readline().strip()

main()


