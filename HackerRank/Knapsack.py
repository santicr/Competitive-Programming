from sys import stdin
import sys

arr = []
k = int()
memo = {}

sys.setrecursionlimit(10**7)

def solve(n, m):
	global arr, k, memo
	ans = None

	if (n, m) in memo:
		ans = memo[(n, m)]
	else:
		if n == 0:
			ans = 0
		elif n > 0 and m + arr[n - 1] <= k:
			ans = max(solve(n, m + arr[n - 1]) + arr[n - 1], solve(n - 1, m), solve(n - 1, m + arr[n - 1]) + arr[n - 1])
		elif m + arr[n - 1] > k:
			ans = solve(n - 1, m)
		memo[(n, m)] = ans

	return ans


def main():
	global arr, n, k, memo
	cases = int(input())

	for i in range(cases):
		memo = {}
		arr = []
		l = stdin.readline()
		l = l.split()
		n, k = int(l[0]), int(l[1])
		l = stdin.readline()
		l = l.split()

		for j in range(n):
			arr.append(int(l[j]))

		print(solve(n, 0))

main()