from sys import stdin
import sys
import faulthandler; faulthandler.enable()
e = -10**7
arr = []
memo = []

sys.setrecursionlimit(10**8)

def solve(n):
    global e, arr, memo
    ans = 0
    for i in range(n):
    	if arr[i] >= 0:
    		ans += arr[i]
    return ans

def solve2(n, f):
    global e, arr, memo
    ans = None
    if memo[n][f] is not None:
    	ans = memo[n][f]
    else:
	    if n > 0 and f == 1:
	    	ans = max(solve2(n - 1, 1), solve2(n - 1, 0) + arr[n - 1])
	    elif n > 0 and f == 0:
	    	ans = max(solve2(n - 1, 0) + arr[n - 1], 0)
	    elif n == 0:
    		ans = 0

	    memo[n][f] = ans
    return ans

def maxSubarray():
    global e, arr, memo
    memo = [[None for _ in range(4)] for _ in range(10**5+5)]
    flag = False
    res1, res2 = int(), int()
    for i in range(len(arr)):
    	if arr[i] >= 0:
    		flag = True
    		break
    if flag == False:
    	res1, res2 = max(arr), max(arr)
    else:
    	res1 = solve(len(arr))
    	res2 = solve2(len(arr), 1)
    
    return [res2, res1]

def main():
	global arr, memo
	cases = int(input())
	for i in range(cases):
		n = int(input())
		linea = stdin.readline()
		linea = linea.split()
		arr = []

		for j in range(len(linea)):
			arr.append(int(linea[j]))
		print(len(arr))
		ans = maxSubarray()
		print(str(ans[0]) + ' ' + str(ans[1]))
main()