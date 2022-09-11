class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        memo = {}
        
        def solve(n):
            ans = None
            if n in memo:
                ans = memo[n]
            else:
                if n <= 0:
                    ans = 0
                elif n > 0:
                    a1 = solve(n - 1) + cost[n - 1]
                    a2 = solve(n - 2) + cost[n - 1]
                    ans = min(a1, a2)
                memo[n] = ans
            return ans
        
        return min(solve(n), solve(n - 1))