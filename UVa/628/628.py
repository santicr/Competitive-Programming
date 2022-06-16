from sys import stdin

w = []
r = []
digits = [str(i) for i in range(10)]
sols = []

def solve(sol, visited, rule, idx):
	global sols, digits, w, r
	if len(sol) == len(rule):
		sols.append(sol)
	else:
		c = rule[idx]
		if c == '#':
			visited = {}
			for j in range(len(w)):
				p = w[j]
				if (p in visited and visited[p] == 0) or p not in visited:
					visited[p] = 1
					solve(sol + [p], visited, rule, idx + 1)
					visited[p] = 0
		elif c == '0':
			visited = {}
			for j in range(10):
				d = digits[j]
				if (d in visited and visited[d] == 0) or d not in visited:
					visited[d] = 1
					solve(sol + [d], visited, rule, idx + 1)
					visited[d] = 0

def main():
	global w, r, sols, digits
	n = stdin.readline().strip()

	while n != "":
		n = n.split()
		n = int(n[0])

		for i in range(n):
			l = stdin.readline().strip()
			w.append(l)

		m = int(input())
		print("--")

		for i in range(m):
			l = stdin.readline().strip()
			r.append(l)
			solve([], {}, r[i], 0)
			for j in range(len(sols)):
				cad = ""
				for k in range(len(sols[j])):
					cad += sols[j][k]
				print(cad)
			sols = []

		w = []
		r = []
		n = stdin.readline().strip()

main()