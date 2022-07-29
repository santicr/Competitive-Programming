class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        n = len(values)
        memo = {}
        
        def solve(i, m):
            ans = None
            
            if (i, m) in memo:
                ans = memo[(i, m)]
            else: 
                if i >= n and m > 0:
                    ans = -float("inf")
                elif m == 0:
                    ans = 0
                elif i < n and m == 2:
                    a1 = solve(i + 1, m - 1) + values[i] + i
                    a2 = solve(i + 1, m)
                    ans = max(a1, a2)
                elif i < n and m == 1:
                    a1 = solve(i + 1, m - 1) + values[i] - i
                    a2 = solve(i + 1, m)
                    ans = max(a1, a2)
                memo[(i, m)] = ans
            
            return ans  
            
        return solve(0, 2)