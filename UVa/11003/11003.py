from sys import stdin

maximos = []
pesos = []
memo = {}

def solve(n, m):
	global maximos, pesos, memo
	ans = None
	if((n, m) in memo):
		ans = memo[(n, m)]
	else:
		if(n == 0):
			ans = 0
		elif(n > 0 and m <= maximos[n - 1]):
			ans = max(solve(n - 1, m + pesos[n - 1]) + 1, solve(n - 1, m))
		elif(n > 0 and m > maximos[n - 1]):
			ans = solve(n - 1, m)
			
		memo[(n, m)] = ans
	return ans

def main():
	global maximos, pesos, memo
	n = int(input())

	while(n != 0):
		memo = {}
		pesos = [0 for i in range(n + 1)]
		maximos = [0 for i in range(n + 1)]

		for i in range(n):
			linea = stdin.readline()
			linea = linea.split()
			w, m = int(linea[0]), int(linea[1])
			pesos[i] = w
			maximos[i] = m

		print(solve(n, 0))

		n = int(input())
main()