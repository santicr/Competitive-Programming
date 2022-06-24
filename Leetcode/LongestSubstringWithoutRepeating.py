class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        idx = 0
        ans = 0
        d = {}
        t = 0
        
        while(i < len(s)):
            d = {s[i]:1}
            t = 1
            for j in range(i + 1, len(s)):
                if (s[j] not in d):
                    d[s[j]] = 1
                    t += 1
                else:
                    break
            ans = max(ans, t)
            i += 1
        ans = max(ans, t)
        return ans