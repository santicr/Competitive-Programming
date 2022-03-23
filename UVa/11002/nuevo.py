from sys import stdin

lab = []
n = int()
sol = float("inf")
cam = []

def solve(i, j, ans, c):
	global n, sol, lab, cam
	ccopy = c.copy()
	if(i == 0 and j == 0):
		if(abs(ans) < sol):
			sol = abs(ans)
			cam = c
	if(i >= n):
		solve(i - 1, j, ans - lab[i - 1][j], c + [-lab[i - 1][j]])
		c = ccopy.copy()
		solve(i - 1, j, ans + lab[i - 1][j], c + [lab[i - 1][j]])
		c = ccopy.copy()
		solve(i - 1, j + 1, ans - lab[i - 1][j + 1], c + [-lab[i - 1][j + 1]])
		c = ccopy.copy()
		solve(i - 1, j + 1, ans + lab[i - 1][j + 1], c + [lab[i - 1][j + 1]])
		c = ccopy.copy()
	elif(j == len(lab[i]) - 1 and i > 0):
		solve(i - 1, j - 1, ans - lab[i - 1][j - 1], c + [-lab[i - 1][j - 1]])
		c = ccopy.copy()
		solve(i - 1, j - 1, ans + lab[i - 1][j - 1], c + [lab[i - 1][j - 1]])
		c = ccopy.copy()
	elif(j == 0 and i > 0):
		solve(i - 1, j, ans - lab[i - 1][j], c + [-lab[i - 1][j]])
		c = ccopy.copy()
		solve(i - 1, j, ans + lab[i - 1][j], c + [lab[i - 1][j]])
		c = ccopy.copy()
	elif(i > 0 and j > 0 and j < len(lab[i]) - 1):
		solve(i - 1, j - 1, ans + lab[i - 1][j - 1], c + [lab[i - 1][j - 1]])
		c = ccopy.copy()
		solve(i - 1, j - 1, ans - lab[i - 1][j - 1], c + [-lab[i - 1][j - 1]])
		c = ccopy.copy()
		solve(i - 1, j, ans + lab[i - 1][j], c + [lab[i - 1][j]])
		c = ccopy.copy()
		solve(i - 1, j, ans - lab[i - 1][j], c + [-lab[i - 1][j]])
		c = ccopy.copy()

def main():
	global n, lab, sol, cam
	n = int(input())
	while(n != 0):
		n = int(n)
		for i in range(2 * n - 1):
			linea = stdin.readline().strip()
			linea = linea.split()
			for j in range(len(linea)):
				linea[j] = int(linea[j])
			lab.append(linea)
		
		solve(2*n-2, 0, lab[2*n-2][0], [lab[2*n-2][0]])
		print(sol)
		print(cam)
		n = int(input())
main()