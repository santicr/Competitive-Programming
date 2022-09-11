class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort(key = lambda x: len(x))
        s = strs[0]
        idx = 0
        ans = ""
        
        while(idx < len(s)):
            for i in range(len(strs)):
                if strs[i][idx] != s[idx]:
                    return ans
            ans += s[idx]
            idx += 1
        
        return ans