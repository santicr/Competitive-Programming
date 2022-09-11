from sys import stdin

def solve(arr, ac, order):
	if order == 0:
		arr.sort(reverse = True)
	else:
		arr.sort()

	vis, pos = {}, {}
	keys = []
	ans = 0

	for i in range(len(arr)):
		if arr[i] != ac[i]:
			pos[ac[i]] = arr[i]
			keys.append(ac[i])

	for i in range(len(keys)):
		k = keys[i]
		while(k not in vis):
			vis[k] = 1
			k = pos[k]
			if k not in vis:
				ans += 1

	return ans

def main():
	n = int(input())
	l = stdin.readline().strip()
	l = l.split()

	arr, ac = [], []

	for i in range(n):
		arr.append(int(l[i]))
		ac.append(int(l[i]))

	print(min(solve(arr, ac, 0), solve(arr, ac, 1)))


main()