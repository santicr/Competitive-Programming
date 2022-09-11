from sys import stdin
arr = []

def binSearch(x):
	global arr
	low, high = 0, len(arr)

	while(low + 1 < high):
		mid = ((low + high) // 2)
		if(x < arr[mid][0]):
			high = mid
		else:
			low = mid
	return low

def solve(n, k):
	global arr
	arr.sort(key = lambda x:x[0])
	ans = None
	for i in range(n):
		if arr[i][0] < k:
			x = k - arr[i][0]
			index = binSearch(x)
			if arr[index][0] == x and arr[index][1] < arr[i][1]:
				ans = [arr[index][1] + 1, arr[i][1] + 1]
				break
			elif arr[index][0] == x and arr[index][1] >= arr[i][1]:
				ans = [arr[i][1] + 1, arr[index][1] + 1]
				break
	return ans

def main():
	global arr
	t = int(input())

	for i in range(t):
		k = int(input())
		n = int(input())
		linea = stdin.readline()
		linea = linea.split()
		arr = []
		for i in range(n):
			arr.append((int(linea[i]), i))
		ans = solve(n, k)
		print(str(ans[0]) + ' ' + str(ans[1]))
main()