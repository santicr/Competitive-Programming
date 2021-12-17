from sys import stdin

prices = []
weights = []
memo = {}

def solve(n, m):
	global prices, weights, memo
	ans = None

	if((n, m) in memo):
		ans = memo[(n, m)]
	else:	
		if(n == 0):
			ans = 0
		elif(m == 0):
			ans = 0
		elif(weights[n - 1] <= m and n > 0):
			ans = max(solve(n - 1, m), solve(n - 1, m - weights[n - 1]) + prices[n - 1])
		elif(weights[n - 1] > m and n > 0):
			ans = solve(n - 1, m)
		memo[(n, m)] = ans

	return ans

def main():
	global prices, weights, memo
	cases = int(input())

	for j in range(cases):
		memo = {}
		prices = []
		weights = []
		n = int(input())

		for i in range(n):
			linea = stdin.readline()
			linea = linea.split()
			prices.append(int(linea[0]))
			weights.append(int(linea[1]))

		g = int(input())
		ans = 0

		for i in range(g):
			mw = int(input())
			ans += (solve(n, mw))
		print(ans)
main()