class Solution:
    def addBinary(self, a: str, b: str) -> str:
        n, m = len(a) - 1, len(b) - 1
        ans = ""
        c = 0
        
        while(n >= 0 or m >= 0):
            if n >= 0 and m >= 0:
                suma = int(a[n]) + int(b[m]) + c
                ans += str(suma % 2)
                
                if suma >= 2:
                    c = 1
                else:
                    c = 0
            
            elif n >= 0:
                suma = int(a[n]) + c
                ans += str(suma % 2)
                
                if suma >= 2:
                    c = 1
                else:
                    c = 0
                    
            elif m >= 0:
                suma = int(b[m]) + c
                ans += str(suma % 2)
                
                if suma >= 2:
                    c = 1
                else:
                    c = 0
            
            n -= 1
            m -= 1
        
        if c:
            ans += '1'
            
        return ans[::-1]