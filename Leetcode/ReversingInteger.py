class Solution:
    def reverse(self, x: int) -> int:
        limit = [-2**(31), 2**31 - 1]
        ans = 0
        pos = True
        if x < 0: pos = False
        s = str(abs(x))
        
        for i in range(len(s)):
            ans += (int(s[i]) * 10**i)
        print(ans)
        
        if not pos:
            ans *= -1
        
        if ans >= limit[0] and ans <= limit[1]:
            return ans
        return 0