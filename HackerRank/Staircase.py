def main():
	n = int(input())
	M = n
	arr = []

	while(n >= 0):
		l = str()
		for i in range(n, M):
			l += ' '
		for i in range(n):
			l += '#'
		arr.append(l)
		n -= 1
		
	while(M >= 0):
		M -= 1
		print(arr[M])
main()