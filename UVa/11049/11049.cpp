#include <bits/stdc++.h>

using namespace std;

char matriz[13][13];

int main(){
    int inix, iniy, finx, finy, x1, x2, y1, y2;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    while(cin >> inix){
        cin >> iniy >> finx >> finy;
        inix--;
        iniy--;
        finx--;
        finy--;

        for(int i = 0; i < 3; i++){
            cin >> x1 >> y1 >> x2 >> y2;

            for(int i = 0; i < 13; i++){
                for(int j = 0; j < 13; j++){
                    if(i >= x1 && j >= y1 + arr[y1] && i <= x2 + arr[x2] && j <= y2 + arr[y2]){
                        matriz[i][j] = '#';
                        
                    }
                }
            }
        }
    }

    return 0;
}