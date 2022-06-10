from sys import stdin

mat = []

def der(nodo, n):
	ans = mat[nodo[0]][nodo[1]]
	y = 1
	for i in range(1, n):
		ans += mat[nodo[0]][nodo[1] + y]
		y += 1
	return ans

def abajo(nodo, n):
	ans = 0
	x = 1
	for i in range(1, n):
		ans += mat[nodo[0] + x][nodo[1]]
		x += 1
	return ans

def izq(nodo, n):
	ans = 0
	y = -1
	for i in range(1, n):
		ans += mat[nodo[0]][nodo[1] + y]
		y -= 1
	return ans

def arriba(nodo, n):
	ans = 0
	x = -1
	for i in range(1, n - 1):
		ans += mat[nodo[0] + x][nodo[1]]
		x -= 1
	return ans

def main():
	global mat
	n = int(input())
	cases = 1

	while n != 0:
		mat = [[0 for _ in range(n)] for _ in range(n)]
		ans = []
		x = 0
		y = 0

		for i in range(n):
			l = stdin.readline()
			l = l.split()
			for j in range(n):
				mat[i][j] = int(l[j])

		while n > 0:
			ans.append(der((x, y), n) + abajo((x, y + (n - 1)), n) +
						 izq((x + (n - 1), y + (n - 1)), n) + arriba((x + (n - 1), y), n))
			x += 1
			y += 1
			n -= 2

		print("Case " + str(cases) + ': ', end = "")
		for i in range(len(ans)):
			if i != 0:
				print(" " + str(ans[i]), end = "")
			else:
				print(ans[i], end = "")
		print()
		cases += 1
		n = int(input())

main()