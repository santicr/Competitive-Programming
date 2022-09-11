class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> p1, p2;
        string a = "", b = "";
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '#')
                p1.push(s[i]);
            else if(!p1.empty() && s[i] == '#')
                p1.pop();
        }
        
        for(int i = 0; i < t.size(); i++){
            if(t[i] != '#')
                p2.push(t[i]);
            else if(!p2.empty() && t[i] == '#')
                p2.pop();
        }
        
        while(!p1.empty()){
            a += p1.top();
            p1.pop();
        }
        
        while(!p2.empty()){
            b += p2.top();
            p2.pop();
        }
        
        return a == b;
    }
};