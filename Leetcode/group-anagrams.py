class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        ans = []
        res = []
        
        for i in range(len(strs)):
            temp = ''.join(sorted(strs[i]))
            if temp not in dic:
                dic[temp] = [strs[i]]
            else:
                dic[temp].append(strs[i])
        
        for k in dic:
            ans.append(dic[k])
        
        return ans