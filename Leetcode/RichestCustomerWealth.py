class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        ans = int()
        
        for i in range(len(accounts)):
            res = 0
            for j in range(len(accounts[i])):
                res += accounts[i][j]
            ans = max(res, ans)
        
        return ans