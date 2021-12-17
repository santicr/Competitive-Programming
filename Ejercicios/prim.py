from sys import stdin
from heapq import heappush, heappop

d, p = [0 for i in range(55)], [0 for i in range(55)]
n = 10
adj = [[] for _ in range(7)]

def prim():
	global n, adj, d, p
	s = 0
	queue = []
	visited = [False for i in range(n + 1)]

	for i in range(n):
		d[i] = float("inf")
		p[i] = -1

	total = 0
	d[s] = 0
	heappush(queue, (0, s))

	while len(queue) > 0:
		peso, u = heappop(queue)
		visited[u] = True
		
		if peso == d[u]:
			total += peso
            #for v in range(n):
			for (v, pesoAux) in adj[u]:
                #pesoAux = grafo[u][v]
				if not visited[v] and pesoAux < d[v]:
					p[v] = u
					d[v] = pesoAux;
					heappush(queue, (d[v], v))
	print(total)

def main():
	aristas = int(input())
	for i in range(aristas):
		linea = stdin.readline()
		linea = linea.split()
		u, v, w = int(linea[0]), int(linea[1]), int(linea[2])
		adj[u].append((v, w))
		adj[v].append((u, w))
	linea = stdin.readline()
	linea = linea.split()
	u, v, w = int(linea[0]), int(linea[1]), int(linea[2])
	prim()
	adj[u].append((v, w))
	adj[v].append((u, w))
	prim()
	print(adj)
	adj[0].remove((4, 4))
	print(adj)

main()