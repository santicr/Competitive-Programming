from sys import stdin

lights = []

def solve():
	global lights

	lights.sort(key = lambda x : (x[0], x[1], -x[2]))

	for i in range(len(lights)):
		c, l, r = lights[i][0], lights[i][1], lights[i][2]
		if c != 1:
			break
		for j in range(i + 1, len(lights))
			

def main():
	global lights
	n = int(input())
	m = int(input())

	for i in range(m):
		l = stdin.readline().strip()
		l = l.split()
		tl = []
		for j in range(len(l)):
			tl.append(int(l[j]))
		lights.append(tl)

	lights.sort(key = lambda x : (x[0], x[1], -x[2]))
	solve()

main()