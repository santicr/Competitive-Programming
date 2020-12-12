#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases, k, temp, indice;
    cin >> cases;
    
    while(cases--){
        vector <int> vec, pos;
        cin >> k;
        indice = k;
        
        for(int i = 0; i < k; i++){
            vec.push_back(i + 1);
            cin >> temp;
            pos.push_back(temp);
        }

        for(int i = 0; i < k; i++){
            if(i == 0){
                cout << vec[pos[i]];
                vec.erase(vec.begin() + pos[i]);
            }
            else{
                cout << " " << vec[pos[i]];
                vec.erase(vec.begin() + pos[i]);
            }
        }
        cout << endl;

    }

    return 0;
}