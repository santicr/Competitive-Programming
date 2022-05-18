from sys import stdin

adj = []
vsols = {}
sols = []
streetcorner = int()
visitados = []

def bfs(u):
	global adj, visitados
	cola = [u]
	vis = [0 for _  in range(23)]

	while len(cola) != 0:
		u = cola[0]
		for i in range(len(adj[u])):
			v = adj[u][i]
			if vis[v] == 0:
				vis[v] = 1
				cola.append(v)
				visitados[v] = 1

		cola.pop(0)

def solve(u, sol, vis):
	global streetcorner, sols, vsols, adj, visitados
	sb = str()
	for i in range(len(sol)):
		sb += (str(sol[i]))
		sb += ' '
	if u == streetcorner and sb not in vsols:
		sb = sb.split()
		sols.append(sb)
	elif visitados[u] == 1:
		for i in range(len(adj[u])):
			v = adj[u][i]
			if v not in vis or vis[v] == 0:
				vis[v] = 1
				solve(v, sol + [v], vis)
				vis[v] = 0

def main():
	global streetcorner, sols, vsols, adj, visitados
	case = 0
	streetcorner = stdin.readline().strip()
	while(streetcorner != ""):
		sols = []
		vsols = {}
		adj = [[] for _ in range(23)]
		visitados = [0 for _ in range(23)]
		case += 1
		print("CASE " + str(case) + ":")
		streetcorner = int(streetcorner)
		l = stdin.readline()
		l = l.split()
		u = int(l[0])
		v = int(l[1])
		while(u != 0 and v != 0):
			adj[u].append(v)
			adj[v].append(u)
			l = stdin.readline()
			l = l.split()
			u = int(l[0])
			v = int(l[1])
		for i in range(0, 23):
			adj[i].sort()
		bfs(1)
		if visitados[streetcorner] == 1:
			(solve(1, [1], {1:1}))
		for i in range(len(sols)):
			for j in range(len(sols[i])):
				if j != 0:
					print("", end = " ")
				print(int(sols[i][j]), end = "")
			print()
		print("There are " + str(len(sols)) + " routes from the firestation to streetcorner " + str(streetcorner) + ".")
		streetcorner = stdin.readline().strip()
main()