#include <bits/stdc++.h>

using namespace std;

string isValid(string s) {
    map <char, int> mapa;
    for(int i = 0; i < s.size(); i++){
        mapa[s[i]]++;
    }

    auto it = mapa.begin();
    int num = it -> second, t, flag = 0;
    it++;
    
    for(; it != mapa.end(); it++){
        t = it -> second;
        if(abs(num - t) == 1 && t < num && t != 1)
            return "NO";
        else if(abs(num - t) >= 2 && t != 1)
            return "NO";
        else if(abs(num - t) == 1 && t < num && t == 1)
            flag++;
        else if(abs(num - t) >= 2 && t == 1)
            flag++;
       	else if((abs(num - t) == 1 && t > num && t != 1))
       		flag++;
    }
    if(flag >= 2)
        return "NO";
    return "YES";
}
int main(){
	cout << isValid("aaabbcc") << endl;


	return 0;
}