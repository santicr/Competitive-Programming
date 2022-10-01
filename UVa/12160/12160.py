from sys import stdin

def bfs(start, final, buttons):
	q = [start]
	vis = {}
	p = {start : 0}

	while len(q) != 0:
		u = q.pop(0)

		if u == final:
			return p[u]

		for i in range(len(buttons)):
			v = buttons[i]
			res = (v + u) % 10 ** 4
			if res not in vis:
				vis[res] = 1
				p[res] = p[u] + 1
				q.append(res)

	return -1

def main():
	l, u, r = tuple(map(int, stdin.readline().strip().split()))
	idx = 1

	while l != u != r != 0:
		line = list(map(int, stdin.readline().strip().split()))
		ans = (bfs(l, u, line))
		res = "Permanently Locked"

		if ans >= 0:
			res = str(ans)

		print(f"Case {idx}: {res}")

		idx += 1
		l, u, r = tuple(map(int, stdin.readline().strip().split()))			

main()