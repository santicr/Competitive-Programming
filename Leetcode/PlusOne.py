class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        cad = ""
        uno = "1"
        ans = []
        
        for i in range(len(digits)):
            cad += str(digits[i])
            
        i = len(cad) - 1
        num = int(cad[i]) + 1
        ans.append(num % 10)
        c = 0
        i -= 1
        
        if num >= 10:
            c = 1
        else:
            c = 0
        
        while(i >= 0):
            num = int(cad[i]) + c
            ans.append(num % 10)
            
            if num >= 10:
                c = 1
            else:
                c = 0
            i -= 1
        
        if c == 1:
            ans.append(c)
            
        ans.reverse()
        
        return ans