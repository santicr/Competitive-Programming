class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        def isSub(s, t, n, m):
            if n == -1:
                return True
            elif m == -1:
                return False
                
            if s[n] == t[m]:
                return isSub(s, t, n - 1, m - 1)
            elif s[n] != t[m]:
                return isSub(s, t, n, m - 1)
                
        n = len(s)
        m = len(t)
        return isSub(s, t, n - 1, m - 1)