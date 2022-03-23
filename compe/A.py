from sys import stdin

def main():
	numeros = list(map(int, stdin.readline().split()))
	d, numeros, ans = numeros[3], sorted(numeros[:3]), 0 
	if numeros[1] - numeros[0] < d: ans = ans + (d - (numeros[1] - numeros[0]))
	if numeros[2] - numeros[1] < d: ans = ans + (d - (numeros[2] - numeros[1]))
	print(ans)

main()