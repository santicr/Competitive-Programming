from sys import stdin

numeros = []
memo = {}
d = int()

def solve(n, m, acum):
	global numeros, memo, d
	ans = None

	if((n, m, acum) in memo):
		ans = memo[(n, m, acum)]
	else:
		if(m == 0 and acum % d == 0):
			ans = 1
		elif(m == 0 and acum % d != 0):
			ans = 0
		elif(n == 0 and m > 0):
			ans = 0;
		elif(n > 0 and m > 0):
			r1 = solve(n - 1, m - 1, acum + (numeros[n - 1] % d));
			r2 = solve(n - 1, m, acum);
			ans = r1 + r2;

		memo[(n, m, acum)] = ans

	return ans

def main():
	global numeros, memo, d
	linea = stdin.readline()
	linea = linea.split()
	n, q = int(linea[0]), int(linea[1])
	index = 0

	while(n != 0 and q != 0):
		print("SET " + str(index + 1) + ":")
		numeros = []

		for i in range(n):
			val = int(input())	
			numeros.append(val)
		
		for i in range(q):
			linea = stdin.readline()
			linea = linea.split()
			d, m = int(linea[0]), int(linea[1])
			print("QUERY " + str(i + 1) + ": " + str(solve(n, m, 0)))
			memo = {}


		index += 1
		linea = stdin.readline()
		linea = linea.split()
		n, q = int(linea[0]), int(linea[1])
main()