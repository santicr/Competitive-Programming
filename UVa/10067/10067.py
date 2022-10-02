from sys import stdin

vis = {}

def bfs(start, end):
	global vis
	q = [start]
	mat = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
	p = {start: 0}

	while len(q) != 0:
		u1, u2, u3, u4 = q.pop(0)
		u = (u1, u2, u3, u4)
		if u == end:
			return p[u]
		
		for i in range(4):
			v1 = (u1 + mat[i][0]) % 10
			v2 = (u2 + mat[i][1]) % 10
			v3 = (u3 + mat[i][2]) % 10
			v4 = (u4 + mat[i][3]) % 10
			v = (v1, v2, v3, v4)

			if v not in vis:
				vis[v] = 1
				q.append(v)
				p[v] = p[u] + 1

			v1 = u1 - mat[i][0]
			v2 = u2 - mat[i][1]
			v3 = u3 - mat[i][2]
			v4 = u4 - mat[i][3]
			if v1 == -1: v1 = 9
			if v2 == -1: v2 = 9
			if v3 == -1: v3 = 9
			if v4 == -1: v4 = 9
			v = (v1, v2, v3, v4)

			if v not in vis:
				p[v] = p[u] + 1
				vis[v] = 1
				q.append(v)
	return -1

def main():
	global vis
	cases = int(input())

	for i in range(cases):
		start = tuple(map(int, stdin.readline().strip().split()))
		end = tuple(map(int, stdin.readline().strip().split()))
		vis[start] = 1
		n = int(input())

		for j in range(n):
			num = tuple(map(int, stdin.readline().strip().split()))
			vis[num] = 1

		print(bfs(start, end))
		vis = {}

		stdin.readline().strip()

main()