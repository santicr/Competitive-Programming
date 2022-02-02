from sys import stdin

def main():
	cases = int(input())
	for i in range(cases):
		dos = 0
		tres = 0
		cuatro = 0
		cinco = 0
		seis = 0

		num = stdin.readline()
		p = False

		for j in range(len(num) - 1):
			tres += int(num[j])
		
		if(tres % 3 != 0):
			tres = 0
		if(int(num[-2]) % 2 == 0):
			dos = 1
		if(int(num[-2]) % 5 == 0):
			cinco = 1
		if((len(num) >= 3 and (int(num[-3] + num[-2]) % 4 == 0)) or int(num) % 4 == 0):
			cuatro = 1
		if(dos and tres):
			seis = 1

		if(dos):
			if(p): print(" ", end="")
			print(2, end="")
			p = True
		if tres:
			if(p): print(" ", end="")
			print(3, end="")
			p = True
		if(cuatro):
			if(p): print(" ", end="")
			print(4, end="")
			p = True
		if cinco:
			if(p): print(" ", end="")
			print(5, end="")
			p = True
		if seis:
			if(p): print(" ", end = "")
			print(6, end = "")
			p = True
		if not p:
			print(-1)
		else:
			print()

main()