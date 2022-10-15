class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        vis = [0 for _ in range(n)]
        nodes = 0
        edges = 0
        adj = [[] for _ in range(n)]
        ans = -1
        
        def bfs(u):
            q = [u]
            vis[u] = 1
            while len(q) != 0:
                u = q.pop(0)
                for v in adj[u]:
                    if not vis[v]:
                        vis[v] = 1
                        q.append(v)
            return 1
        
        for con in connections:
            u, v = con
            adj[u].append(v)
            adj[v].append(u)
        
        for i in range(n):
            edges += len(adj[i])
            if not vis[i]:
                nodes += bfs(i)
        edges //= 2
        
        if edges >= n - 1:
            ans = nodes - 1
        return ans