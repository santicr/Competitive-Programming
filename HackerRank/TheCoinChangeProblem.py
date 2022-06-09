from sys import stdin
import sys

arr = []
memo = {}

sys.setrecursionlimit(10**7)

def solve(n, m):
	global arr, memo
	ans = None

	if (n, m) in memo:
		ans = memo[(n, m)]
	else:
		if n == 0 and m == 0:
			ans = 1
		elif n > 0 and m == 0:
			ans = 1
		elif n == 0 and m > 0:
			ans = 0
		elif n > 0 and m - arr[n - 1] >= 0:
			ans = max(solve(n - 1, m - arr[n - 1]) + solve(n - 1, m), solve(n, m - arr[n - 1]) + solve(n - 1, m))
		elif n > 0 and m - arr[n - 1] < 0:
			ans = solve(n - 1, m)
		memo[(n, m)] = ans

	return ans

def main():
	global arr, memo
	arr = []
	memo = {}
	l = stdin.readline()
	l = l.split()
	k, n = int(l[0]), int(l[1])
	l = stdin.readline()
	l = l.split()
	
	for i in range(n):
		arr.append(int(l[i]))

	print(solve(n, k))

main()