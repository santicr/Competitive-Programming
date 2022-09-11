from sys import stdin

def main():
	t = int(input())
	n, k, p = int(), int(), int()
	
	for i in range(t):
		l = stdin.readline().strip()
		l = l.split()
		n, k, p = int(l[0]), int(l[1]), int(l[2])
		suma = p + k
		print("Case " + str(i + 1) + ": ", end = "")
		if suma > n:
			if suma % n == 0:
				print(n)
			else:
				print(suma % n)
		else:
			print(suma)

main()