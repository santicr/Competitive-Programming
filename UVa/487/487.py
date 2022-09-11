from sys import stdin
mat = []
sols = []
vsols = {}

def cond(x, y, sol):
	global mat
	ans = False
	if mat[x][y] > mat[sol[-1][0]][sol[-1][1]]:
		ans = True
	return ans

def solve(vis, sol):
	global mat, sols, vsols
	if len(sol) == 0:
		for i in range(len(mat)):
			for j in range(len(mat)):
				vis[(i, j)] = 1
				solve(vis, sol + [(i, j)])
				vis[(i, j)] = 0
	else:
		dx = [1, 1,  1, 0,  0, -1, -1, -1]
		dy = [0, 1, -1, 1, -1, -1, 1,  0]
		sb = str()
		for i in range(len(sol)):
			sb += mat[sol[i][0]][sol[i][1]]
		if len(sol) >= 3 and sb not in vsols:
			sols.append(sb)
			vsols[sb] = 1

		for i in range(8):
			nx = sol[-1][0] + dx[i]
			ny = sol[-1][1] + dy[i]
			if nx >= 0 and nx < len(mat) and ny >= 0 and ny < len(mat) and ((nx,ny) not in vis or vis[(nx, ny)] == 0) and cond(nx, ny, sol):
				vis[(nx, ny)] = 1
				solve(vis, sol + [(nx, ny)])
				vis[(nx, ny)] = 0

def main():
	global mat, sols, vsols
	t = int(input())
	stdin.readline()

	for i in range(t):
		if i != 0:
			print()
		n = int(input())
		mat = []
		ans = []
		sols = []
		vsols = {}

		for j in range(n):
			l = stdin.readline().strip()
			mat.append(l)
		solve({}, [])

		sols.sort()
		sols.sort(key = len)

		for e in sols:
			print(e)
	
		stdin.readline()
main()