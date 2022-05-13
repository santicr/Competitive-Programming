memo = {}
def solve(n):
	if n in memo:
		ans = memo[n]
	else:
		ans = None
		if n == 0:
			ans = 1
		elif n == 1:
			ans = 1
		else:
			ans = n * solve(n - 1)
		memo[n] = ans
	return ans

def main():
	n = int(input())
	print(solve(n))

main()