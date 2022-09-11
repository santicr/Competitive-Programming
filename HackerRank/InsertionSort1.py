from sys import stdin

def main():
	n = int(input())
	l = stdin.readline().strip().split()
	arr = []

	for i in range(n - 1):
		arr.append(int(l[i]))

	val = int(l[n - 1])
	flag = False

	for i in range(n - 2, -1, -1):
		if arr[i] > val:
			arr.insert(i + 1, arr[i])
			for j in range(len(arr)):
				print(arr[j], end = " ")
			arr.pop(i + 1)
		else:
			flag = True
			arr.insert(i + 1, val)
			for j in range(len(arr)):
				print(arr[j], end = " ")
			break
		print()

	if not flag:
		arr.insert(0, val)
		for j in range(len(arr)):
				print(arr[j], end = " ")

main()