def main():
	n = int(input())
	arr = []

	for i in range(n):
		val = (input())
		arr.append((val, len(val)))

	arr.sort(key = lambda x : (x[1], x[0]))

	for i in range(n):
		print(arr[i][0])

main()