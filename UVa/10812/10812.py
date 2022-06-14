from sys import stdin

cases = int(input())

for i in range(cases):
	l = stdin.readline()
	l = l.split()
	s, d = int(l[0]), int(l[1])
	div = (s + d) / 2
	if(div == int(div) and d <= s):
		print(str(int(div)) + ' ' + str(int(s - div)))
	else:
		print("impossible")