class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        lista = []
        
        if num1 == '0' or num2 == '0':
            return "0"
        
        def solve(num1, num2):
            i = len(num1) - 1
            resL = []
            pot = 0
            
            while(i >= 0):
                t1 = int(num1[i])
                j = len(num2) - 1
                c = 0
                k = 0
                res = ""
                while(k < pot):
                    res += '0'
                    k += 1
                
                while(j >= 0):
                    t2 = int(num2[j])
                    ans = (t2 * t1) + c
                    if ans > 9:
                        c = int(str(ans)[0])
                    else:
                        c = 0
                    ans %= 10
                    res += str(ans)
                    j -= 1
                    
                pot += 1
                i -= 1
                
                if c != 0:
                    res += str(c)
                resL.append(res[::-1])
            
            return resL
            
        def suma(num1, num2):
            i = len(num2) - 1
            c = 0
            dif = len(num1) - len(num2)
            res = ""
            
            while i >= 0:
                n1 = int(num1[i + dif])
                n2 = int(num2[i])
                ans = n1 + n2 + c
                if ans > 9:
                    c = 1
                else:
                    c = 0
                ans %= 10
                res += str(ans)
                i -= 1
            
            i = dif - 1
            while(i >= 0):
                n1 = int(num1[i])
                ans = n1 + c
                if ans > 9:
                    c = 1
                else:
                    c = 0
                ans %= 10
                res += str(ans)
                i -= 1
            if c == 1:
                res += str(c)
            return res[::-1]
        
        if len(num1) <= len(num2):
            lista = solve(num1, num2)
        else:
            lista = solve(num2, num1)
        
        print(lista)
        acum = lista[0]
        for i in range(1, len(lista)):
            if len(acum) >= len(lista[i]):
                acum = suma(acum, lista[i])
            else:
                acum = suma(lista[i], acum)
            
        return acum