class Solution:
    def climbStairs(self, n: int) -> int:
        memo = {}
        
        def solve(n):
            ans = None
            if n in memo:
                ans = memo[n]
            else:    
                if n == 0:
                    ans = 1
                elif n < 0:
                    ans = 0
                else:
                    ans = solve(n - 1)
                    ans += solve(n - 2)
                memo[n] = ans
            return ans
        
        return solve(n)