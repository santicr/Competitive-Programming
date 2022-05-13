from sys import stdin

def solve(n, m):
	global X, N
	ans = None
	if m == 0:
		ans = True
	elif n == 0:
		ans = False
	elif m < 0:
		ans = False
	elif n > 0 and m > 0:
		ans = solve(n - 1, m) + solve(n - 1, m - ((n - 1)**N))

	return ans

def main():
	global X, N
	X = int(input())
	N = int(input())
	print(solve(X//N + 1, X))

main()