#include <bits/stdc++.h>

using namespace std;

int a1, a2, b1, b2, c1, c2;
pair <int, int> pareja;
int res[9][9];
bool visitados[10][10];

bool cond(int x, int x1, int y, int y1){
    if(x + x1 != -1 && y + y1 != -1 && x + x1 != 8 && y + y1 != 8 && !(x + x1 == c1 && y + y1 == c2))
        return true;
    return false;
}

void BFS(){
    queue <pair<int, int>> cola;
    pair <int, int> val;
    int x, y, x1, y1;
    cola.push(pareja);
    visitados[a1][a2] = true;

    while(!cola.empty()){
        val = cola.front();
        cola.pop();
        x = val.first;
        y = val.second;
        int arx[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int ary[] = {0, 0, -1, 1, 1, -1, -1, 1};

        if(x == b1 && y == b2){
            cout << res[x][y] << endl;
            break;
        }

        for(int i = 0; i < 8; i++){
            x1 = arx[i];
            y1 = ary[i];

            if(cond(x, x1, y, y1) && visitados[x + x1][y + y1] == false){
                visitados[x + x1][y + y1] = true;
                cola.push(make_pair(x + x1, y + y1));
                res[x + x1][y + y1] = res[x][y] + 1;
            }
        }

    }
}

int main(){
    int cases = 0;

    while(cin >> a1){
        cin >> a2 >> b1 >> b2 >> c1 >> c2;
        a1--;
        a2--;
        b1--;
        b2--;
        c1--;
        c2--;
        pareja = make_pair(a1, a2);
        cout << "Case " << ++cases << ": ";
        BFS();
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                visitados[i][j] = false;
                res[i][j] = 0;
            }
        }
    }

    return 0;
}