from sys import stdin
import sys
first, second = str(), str()
memo = {}
sys.setrecursionlimit(10**6)

def solve(index1, index2):
	global memo, first, second
	ans = None
	if((index1, index2) in memo):
		ans = memo[(index1, index2)]
	else:
		if(index1 < len(first) and index2 < len(second)):
			if(first[index1] == second[index2] and index2 == len(second) - 1):
				ans = 1 + solve(index1 + 1, index2)
			elif(first[index1] == second[index2] and index1 == len(first) - 1):
				ans = 0
			elif(first[index1] != second[index2]):
				ans = solve(index1 + 1, index2)
			elif(first[index1] == second[index2]):
				ans = solve(index1 + 1, index2 + 1) + solve(index1 + 1, index2)
		else:
			ans = 0
		memo[(index1, index2)] = ans
	return ans

def main():
	global memo, first, second
	cases = int(input())

	for i in range(cases):
		memo = {}
		first = stdin.readline().strip()
		second = stdin.readline().strip()
		print(solve(0, 0))
main()