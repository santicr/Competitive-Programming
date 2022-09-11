#include <bits/stdc++.h>

using namespace std;

vector <string> grafo;
string str;
int x, y;

bool salida(){
    for(int i = 0; i < str.size(); i++)
        if(str[i] != '_')
            return true;
    return false;
}

int get_pos(string temp){
    for(int i = 0; i < temp.size(); i++)
        if(temp[i] == '*')
            return i;
    return -1;
}

void BFS(){
    queue <pair <int, int>> cola;
    pair <int, int> val;
    int dx[] = {0, 1, -1, 0, 1, -1, 1, -1};
    int dy[] = {1, 0, 0, -1, 1, -1, -1, 1};
    int i, j, i1, j1;
    cola.push(make_pair(x, y));
    grafo[x][y] = '#';

    while(!cola.empty()){
        val = cola.front();
        cola.pop();
        i = val.first;
        j = val.second;

        for(int index = 0; index < 8; index++){
            i1 = dx[index];
            j1 = dy[index];

            if(grafo[i + i1][j + j1] == ' '){
                grafo[i + i1][j + j1] = '#';
                cola.push(make_pair(i + i1, j + j1));
            }
        }

    }
}

int main(){
    int cases, fila = 0, temp;
    cin >> cases;
    cin.ignore();
    while(cases--){

        while(getline(cin, str)){
            temp = get_pos(str);
            x = temp != -1 ? x = fila : x = x;
            y = temp != -1 ? y = temp : y = y;
            grafo.push_back(str);
            fila++;
            if(!salida())
                break;
        }

        BFS();

        for(int i = 0; i < grafo.size(); i++){
            for(int j = 0; j < grafo[i].size(); j++)
                cout << grafo[i][j];
            cout << endl;
        }

        grafo.clear();
        fila = 0;

    }

    return 0;
}