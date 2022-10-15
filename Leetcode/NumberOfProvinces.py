class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        ans = 0
        vis = [0 for _ in range(n)]
        
        def bfs(u, vis):
            q = [u]
            vis[u] = 1
            
            while len(q) != 0:
                u = q.pop(0)
                
                for i in range(len(isConnected[u])):
                    v = isConnected[u][i]
                    if not vis[i] and v:
                        vis[i] = 1
                        q.append(i)
        
        for i in range(len(vis)):
            if vis[i] == 0:
                ans += 1
                bfs(i, vis)
            
        return ans