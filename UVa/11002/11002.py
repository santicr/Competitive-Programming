from sys import stdin

lab = []
n = int()
memo = {}

def solve(i, j):
	global n, memo, lab
	ans = None
	if((i, j) in memo):
		ans = memo[(i, j)]
	else:
		if(i == 2*n-2 and j == 0):
			a = lab[i][j] + solve(i - 1, j)
			b = lab[i][j] - solve(i - 1, j)
			c = lab[i][j] + solve(i - 1, j + 1)
			d = lab[i][j] - solve(i - 1, j + 1)
			if(abs(a) < abs(b) and abs(a) < abs(c) and abs(a) < abs(d)):
				ans = abs(a)
			elif(abs(b) < abs(a) and abs(b) < abs(c) and abs(b) < abs(d)):
				ans = abs(b)
			elif(abs(c) < abs(a) and abs(c) < abs(b) and abs(c) < abs(d)):
				ans = abs(c)
			else:
				ans = abs(d)
		elif(i == 0 and j == 0):
			ans = lab[i][j]
		elif(i >= n):
			a = lab[i][j] + solve(i - 1, j)
			b = lab[i][j] - solve(i - 1, j)
			c = lab[i][j] + solve(i - 1, j + 1)
			d = lab[i][j] - solve(i - 1, j + 1)
			if(abs(a) < abs(b) and abs(a) < abs(c) and abs(a) < abs(d)):
				ans = abs(a)
			elif(abs(b) < abs(a) and abs(b) < abs(c) and abs(b) < abs(d)):
				ans = abs(b)
			elif(abs(c) < abs(a) and abs(c) < abs(b) and abs(c) < abs(d)):
				ans = abs(c)
			else:
				ans = abs(d)

		elif(i > 0 and j > 0 and j < len(lab[i]) - 1):
			a = lab[i][j] + solve(i - 1, j - 1)
			b = lab[i][j] - solve(i - 1, j - 1)
			c = lab[i][j] + solve(i - 1, j)
			d = lab[i][j] - solve(i - 1, j)
			if(abs(a) < abs(b) and abs(a) < abs(c) and abs(a) < abs(d)):
				ans = abs(a)
			elif(abs(b) < abs(a) and abs(b) < abs(c) and abs(b) < abs(d)):
				ans = abs(b)
			elif(abs(c) < abs(a) and abs(c) < abs(b) and abs(c) < abs(d)):
				ans = abs(c)
			else:
				ans = abs(d)

		elif(j == len(lab[i]) - 1 and i > 0):
			a = lab[i][j] + solve(i - 1, j - 1)
			b = lab[i][j] - solve(i - 1, j - 1)
			if(abs(a) < abs(b)):
				ans = abs(a)
			else:
				ans = abs(b)
		elif(j == 0 and i > 0):
			a = lab[i][j] + solve(i - 1, j)
			b = lab[i][j] - solve(i - 1, j)
			if(abs(a) < abs(b)):
				ans = abs(a)
			else:
				ans = abs(b)
		memo[(i, j)] = ans
	return ans

def main():
	global n, lab, memo
	n = int(input())
	while(n != 0):
		for i in range(2 * n - 1):
			linea = stdin.readline().strip()
			linea = linea.split()
			for j in range(len(linea)):
				linea[j] = int(linea[j])
			lab.append(linea)

		memo = {}
		print(solve(2*n-2, 0))
		n = int(input())
main()