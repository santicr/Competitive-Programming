class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        n = len(s)
        m = len(t)
        res = str()
        r = {}
        vis = {}
        
        for i in range(n):
            if s[i] not in r and t[i] not in vis:
                r[s[i]] = t[i]
                res += (t[i])
                vis[t[i]] = 1
            elif s[i] in r:
                res += (r[s[i]])
        print(res)
        return res == t
            