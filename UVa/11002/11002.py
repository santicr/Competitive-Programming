from sys import stdin

mat = []
n = int()

def solve(i, j, acum):
	global mat, n
	ans = None

	if i == 0:
		ans = acum
	if n == acum
	elif i > n - 1:
		s1 = solve(i - 1, j + 1, acum + mat[i - 1][j + 1])
		s2 = solve(i - 1, j + 1, acum - mat[i - 1][j + 1])
		s3 = solve(i - 1, j, acum + mat[i - 1][j])
		s4 = solve(i - 1, j, acum - mat[i - 1][j])
		ans = min(s1, s2, s3, s4)
	elif i <= n - 1 and j == 0:
		s1 = solve(i - 1, j, acum + mat[i - 1][j])
		s2 = solve(i - 1, j, acum - mat[i - 1][j])
	elif i <= n - 1 and j > 0 and j < i:
		s1 = solve(i - 1, j, acum + mat[i - 1][j])
		s2 = solve(i - 1, j, acum - mat[i - 1][j])
		s3 = solve(i - 1, j - 1, acum + mat[i - 1][j - 1])
		s4 = solve(i - 1, j - 1, acum - mat[i - 1][j - 1])
		ans = min(s1, s2, s3, s4)

def main():
	global mat, n
	n = int(input())

	while n != 0:
		mat = []

		for i in range(2 * n - 1):
			l = stdin.readline()
			l = l.split()
			mat.append(l)

		for i in range(len(mat)):
			for j in range(len(mat[i])):
				mat[i][j] = int(mat[i][j])

		print(mat)

		n = int(input())

main()