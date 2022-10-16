class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        adj = [[] for _ in range(n)]
    
        for i in range(len(manager)):
            if manager[i] != -1:
                adj[i].append(manager[i])
                adj[manager[i]].append(i)

        q = [headID]
        vis = [-1 for _ in range(n)]
        vis[headID] = 0
        max_el = 0
        for a in adj:
            print(a)

        while len(q) != 0:
            u = q.pop(0)
            for i in range(len(adj[u])):
                v = adj[u][i]
                if vis[v] == -1:
                    vis[v] = vis[u] + informTime[u]
                    max_el = max(max_el, vis[v])
                    q.append(v)
        return max_el