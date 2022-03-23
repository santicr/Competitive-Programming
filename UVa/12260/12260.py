from sys import stdin

values = []

def solve(index):
	pv, jv = values[index][0], values[index][1]
	if(name == "Petra" and pv > jv):
		ans = pv
	elif(name == "Petra" and pv == jv):

def main():
	global values

	cases = int(input())
	for i in range(cases):
		goodies = int(input())
		name = stdin.readline.strip()
		for j in range(goodies):
			linea = stdin.readline()
			linea = linea.split()
			pv, jv = int(linea[0]), int(linea[1])
			values.append((pv, jv))

		solve()