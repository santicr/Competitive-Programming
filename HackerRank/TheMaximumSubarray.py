from sys import stdin

arr = []

def maxSubsequence(n, m):
	ans = None
	if n == -1:
		ans = m
	elif n >= 0 and m + arr[n] > m:
		ans = maxSubsequence(n - 1, m + arr[n])
	elif n >= 0 and m + arr[n] <= m:
		ans = maxSubsequence(n - 1, m)
	return ans

def maxSubarray(n, m):
	pass

def main():
	global arr
	t = int(input())
	
	for i in range(t):
		n = int(input())
		arr = map(int, stdin.readline().split())
		print(maxSubsequence(n), maxSubarray(n))

main()