from sys import stdin

def binSearch(arr, x):
	low, high = 0, len(arr)
	while low + 1 < high:
		m = (high + low) // 2
		if arr[m] > x:
			high = m
		else:
			low = m
	return low

def main():
	l = stdin.readline().strip()
	l = l.split()
	arr, ac = [], []
	n, d = int(l[0]), int(l[1])
	med = None
	ans = 0

	l = stdin.readline().strip()
	l = l.split()

	for i in range(n):
		ac.append(int(l[i]))

	arr = ac[0:d]
	arr.sort()

	for i in range(d, n):
		if d % 2 != 0:
			med = arr[d // 2]
		else:
			med = (arr[d // 2] + arr[(d // 2) - 1]) / 2

		if ac[i] >= 2 * med:
			ans += 1

		arr.pop(binSearch(arr, ac[i - d]))
		idx = binSearch(arr, ac[i])
		if ac[idx] > arr[idx]:
			arr.insert(idx + 1, ac[i])
		else:
			arr.insert(idx, ac[i])

	print(ans)

main()