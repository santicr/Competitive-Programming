from sys import stdin

sols = []
l = str()

def solve(sol, idx, it):
	global sols, l
	if len(sol) == len(l):
		sols.append(sol)
	else:
		index = 0
		for i in range(idx, idx + it):
			sc = sol.copy()
			sc.insert(index, idx)
			solve(sc, idx + 1, it + 1)
			index += 1

def main():
	global sols, l
	l = stdin.readline().strip()
	cases = 0

	while(l != ""):
		if(cases != 0):
			print()
		sols = []
		solve([0], 1, 2)

		for i in range(len(sols)):
			sc = ""
			for j in range(len(sols[i])):
				sc += l[(sols[i][j])]
			print(sc)
		cases += 1

		l = stdin.readline().strip()

main()