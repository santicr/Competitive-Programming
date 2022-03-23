from sys import stdin

def main():
	secuencia = stdin.readline()
	secuencia = secuencia.split()
	ans = -float("inf")
	for i in range(len(secuencia) - 1):
		acum = 1
		for j in range(i, len(secuencia) - 1):
			acum *= int(secuencia[j])
		if ans < acum: ans = acum
	print(ans)

main()