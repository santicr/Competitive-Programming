class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        ans = []
        c = 0
        
        def convert(k):
            lista = []
            
            while(k):
                lista.append(k % 10)
                k //= 10
                
            lista.reverse()
            
            return lista
        
        num2 = convert(k)
        print(num2)
        
        m = len(num2) - 1
        n = len(num) - 1
        
        while(n >= 0 or m >= 0):
            if m >= 0 and n >= 0:
                suma = c + num[n] + num2[m]
                if suma >= 10:
                    c = (suma // 10) % 10
                else:
                    c = 0
                ans.append(suma % 10)
            
            elif n >= 0:
                suma = c + num[n]
                if suma >= 10:
                    c = (suma // 10) % 10
                else:
                    c = 0
                ans.append(suma % 10)
            
            elif m >= 0:
                suma = c + num2[m]
                if suma >= 10:
                    c = (suma // 10) % 10
                else:
                    c = 0
                ans.append(suma % 10)
        
            m -= 1
            n -= 1
        if c:
            ans.append(c)
        
        ans.reverse()
        
        return ans