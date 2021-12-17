w = [5]
b = [4]
memo = {}

def ks01(n, m):
	ans = None
	if((n,m) in memo):
		ans = memo[(n,m)]
	else:
		if(n == 0):
			ans = 0
		elif(n > 0 and w[n - 1] <= m):
			ans = max(ks01(n - 1, m), ks01(n - 1, m - w[n - 1]) + b[n - 1])
		elif(n > 0 and w[n - 1] > m):
			ans = ks01(n - 1, m)
		memo[(n, m)] = ans
	return ans

def main():
	print(ks01(1, 20))
	print(memo)

main()	