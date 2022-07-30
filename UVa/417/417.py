from sys import stdin

cad = "abcdefghijklmnopqrstuvwxyz"
dic = {}

def main():
	dic = {cad[i]: i + 1 for i in range(len(cad))}
	acum = 27
	for i in range(len(cad)):
		for j in range(i + 1, len(cad)):
			dic[cad[i] + cad[j]] = acum
			acum += 1

	for i in range(len(cad)):
		for j in range(i + 1, len(cad)):
			for k in range(j + 1, len(cad)):
				dic[cad[i] + cad[j] + cad[k]] = acum
				acum += 1

	for i in range(len(cad)):
		for j in range(i + 1, len(cad)):
			for k in range(j + 1, len(cad)):
				for l in range(k + 1, len(cad)):
					dic[cad[i] + cad[j] + cad[k] + cad[l]] = acum
					acum += 1

	for i in range(len(cad)):
		for j in range(i + 1, len(cad)):
			for k in range(j + 1, len(cad)):
				for l in range(k + 1, len(cad)):
					for m in range(l + 1, len(cad)):
						dic[cad[i] + cad[j] + cad[k] + cad[l] + cad[m]] = acum
						acum += 1
	
	l = stdin.readline().strip()
	while l != "":
		if l in dic:
			print(dic[l])
		else:
			print(str(0))
		l = stdin.readline().strip()

main()