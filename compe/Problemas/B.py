from sys import stdin

def main():
	cases = int(input())
	for i in range(cases):
		str1 = stdin.readline().strip()
		str2 = stdin.readline().strip()
		lista, lista2 = [], []
		ant = '+'
		for i in range(len(str2)):
			if(ant != str2[i]):
				ant = str2[i]
				lista.append([ant, 1])
			else:
				lista[-1][1] += 1
		ant = '-'
		for i in range(len(str1)):
			if(ant != str1[i]):
				ant = str1[i]
				lista2.append([ant, 1])
			else:
				lista2[-1][1] += 1
		if len(str1) > len(str2) or len(lista2) != len(lista):
			print("NO")
		else:
			flag = True
			for i in range(len(lista2)):
				if(lista[i][1] < lista2[i][1] or lista[i][0] != lista2[i][0]):
					flag = False
					break
			if(flag):
				print("YES")
			else:
				print("NO")

main()