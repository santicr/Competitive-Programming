from sys import stdin

adj = []
mapa = {}
n = int()

def bfs(start):
	global adj, n, mapa
	q = [start]
	vis = [-1 for _ in range(n)]
	vis[start] = 0

	while(len(q) != 0):
		u = q.pop(0)
		for i in range(len(adj[u])):
			v = adj[u][i]
			if vis[v] == -1:
				vis[v] = vis[u] + 1
				q.append(v)
				if vis[v] in mapa:
					mapa[vis[v]] += 1
				else:
					mapa[vis[v]] = 1

def main():
	global adj, n, mapa
	n = int(input())

	adj = [[] for _ in range(n)]

	for i in range(n):
		line = stdin.readline().strip().split()
		for j in range(1, len(line)):
			adj[i].append(int(line[j]))

	t = int(input())

	for i in range(t):
		u = int(input())
		mapa = {}
		bfs(u)
		max_el = 0

		for k in mapa:
			v = mapa[k]
			if v > max_el:
				max_el = v
				day = k

		if not max_el:
			print(0)
		else:
			print(f"{max_el} {day}")

main()