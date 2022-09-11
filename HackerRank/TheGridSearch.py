def comp(i, j, n, m, G, P):
	idx = 0
	while(idx < n):
		if P[idx] != G[i][j:m + j]:
			return False
		else:
			i += 1
		idx += 1
	return True

def gridSearch(G, P):
	n, m = len(P), len(P[0])
	idx, idy = 0, 0
	i = 0
	while i < len(G):
		j = 0
		while j < len(G[0]):
			g = G[i][j]
			p = P[idx][idy]

			if p == g:
				res = comp(i, j, n, m, G, P)
				if res == True:
					return "YES"
			j += 1
		i += 1
	return "NO"

print(gridSearch(["1234","5678","0123","8736"], ["67", "12"]))