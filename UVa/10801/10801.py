from sys import stdin
from heapq import heappop, heappush

INF = float('inf')

def dijkstra(G, s):
    """G is a graph representation in adjacency list format with vertices
       in the set { 0, ..., |V|-1 } and source a vertex in G"""
    # dist[u] : "minimum distance detected from source to u
    d, p = [[INF for _ in range(len(G[i]))] for i in range(len(G))], [[-1 for _ in range(len(G[i]))] for i in range(len(G))]
    d[s[0]][s[1]] = 0
    heap = [(0, s)]

    while len(heap) != 0:
        costo, u = heappop(heap)
        u1, u2 = u
        if costo == d[u1][u2]:
            for v, w in G[u1][u2]:
                v1, v2 = v
                if d[v1][v2] > d[u1][u2] + w:
                    d[v1][v2] = d[u1][u2] + w
                    p[v1][v2] = (u1, u2)
                    heappush(heap, (d[v1][v2], (v1, v2)))
    return d, p

def main():
    line = stdin.readline()
    while line != "":
        n, res = tuple(map(int, line.strip().split()))
        times = list(map(int, stdin.readline().strip().split()))
        adj = [[[] for _ in range(n)] for _ in range(100)]

        for u1 in range(n):
            floors = list(map(int, stdin.readline().strip().split()))
            for j in range(len(floors)):
                u2 = floors[j]
                for l in range(n):
                    if len(adj[u2][l]):
                        adj[u2][u1].append(((u2, l), 60))
                        adj[u2][l].append(((u2, u1), 60))
                for k in range(j + 1, len(floors)):
                    v1 = floors[k]
                    adj[u2][u1].append(((v1, u1), (v1 - u2) * times[u1]))
                    adj[v1][u1].append(((u2, u1), (v1 - u2) * times[u1]))

        global_ans = INF

        for i in range(n):
            d = dijkstra(adj, (0, i))[0]
            ans = min([d[res][i] for i in range(n)])
            global_ans = min(ans, global_ans)

        global_ans = global_ans if global_ans != INF else "IMPOSSIBLE"
        print(global_ans)

        line = stdin.readline()


main()