class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)
        idx = 0
        ans = -1
        i = 0
        
        while(i < n):
            if haystack[i] == needle[0]:
                if haystack[i:m + i] == needle:
                    return i
            i += 1
        
        return ans