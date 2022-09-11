class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        ans = ""
        
        def concat(cad):
            ans = cad
            while(ans in s):
                if ans == s:
                    return True
                ans += cad
                
            if cad == s:
                return True
            else:
                return False
                
        for i in range(n - 1):
            ans += s[i]
            if(concat(ans)):
                return True
        
        return False