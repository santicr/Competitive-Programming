from sys import stdin
import math

def main():
	cases = int(input())
	lista = [(180000, 0), (300000, 0.1), (400000, 0.15), (300000, 0.2)]

	for i in range(cases):
		k = int(input())
		ans = 0
		print("Case " + str(i + 1) + ": ", end = "")

		for j in range(4):
			x = lista[j][0]
			y = lista[j][1]

			if k > x:
				k -= x
				ans += (x * y)
			else:
				ans += (k * y)
				k = 0

		if k != 0:
			ans += k * 0.25
		if ans > 0 and ans < 2000:
			print("2000")
		else:
			print(int(math.ceil(ans)))

main()