from sys import stdin

memo = {}
arr = []
acum = 0

def solve(n, m):
	global acum, memo, arr
	ans = None
	if((n, m) in memo):
		ans = memo[(n, m)]
	else:
		if(n == 0):
			ans = m
		elif(n != 0 and m + arr[n - 1] <= acum):
			ans = max(solve(n - 1, m + arr[n - 1]), solve(n - 1, m))
		elif(n != 0 and m + arr[n - 1] > acum):
			ans = solve(n - 1, m)
		memo[(n, m)] = ans
	return ans

def main():
	global acum, memo, arr
	cases = int(input())

	for i in range(cases):
		arr = []
		memo = {}
		acum = 0
		n = 0
		l = stdin.readline().strip()
		l = l.split()

		for j in range(len(l)):
			acum += int(l[j])
			arr.append(int(l[j]))
			n += 1

		t = acum
		acum /= 2

		if(solve(n, 0) * 2 == t):
			print("YES")
		else:
			print("NO")

main()