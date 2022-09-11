from sys import stdin
num = 0
sols = []

def esPrimo(num):
	if(num == 2 or num == 3 or num == 5 or num == 7 or num == 11 or num == 13
		or num == 17 or num == 19 or num == 23 or num == 29 or num == 31 or num == 37):
		return True
	return False

def solve(sol, visitados):
	global num, sols
	if(len(sol) < num):
		for i in range(2, num + 1):
			if(visitados[i] == 0 and esPrimo(i + sol[-1])):
				scopy = sol.copy()
				scopy.append(i)
				vcopy = visitados.copy()
				vcopy[i] = 1
				solve(scopy, vcopy)
	else:
		if(esPrimo(sol[0] + sol[-1])):
			sols.append(sol)

def main():
	global num, visitados, sols
	num = stdin.readline()
	cases = 1

	while(len(num) > 0):
		if(cases != 1):
			print()
		visitados = [0 for i in range(18)]
		num = int(num)
		arr = [1]
		solve(arr, visitados)
		print("Case " + str(cases) + ":")
		for i in range(len(sols)):
			for j in range(len(sols[i])):
				if(j != 0):
					print(" " + str(sols[i][j]), end = "")
				else:
					print(sols[i][j], end = "")
			print()

		num = stdin.readline()
		sols = []
		cases += 1
	

main()
