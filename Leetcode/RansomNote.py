class Solution:
    
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dR = {}
        dM = {}
        
        for i in range(len(ransomNote)):
            s = ransomNote[i]
            if s not in dR:
                dR[s] = 1
            else:
                dR[s] += 1
        
        for i in range(len(magazine)):
            s = magazine[i]
            if s not in dM:
                dM[s] = 1
            else:
                dM[s] += 1
        
        for k in dR:
            if k not in dM or dM[k] < dR[k]:
                return False
        return True