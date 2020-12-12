#include <bits/stdc++.h>

using namespace std;

vector <vector <char>> grafo(1002);
bool visitadosf[1002][1002];
int n, m;
bool acabo = false;
int res [1002][1002];
queue <tuple <int, int, char>> cola;
vector <tuple <int, int, char>> vec;

void BFS(){
    tuple <int, int, char> val;
    int x, y;
    char c;

    while(!cola.empty()){
        val = cola.front();
        cola.pop();
        x = get <0>(val);
        y = get <1>(val);
        c = get <2>(val);

        if(c == 'J' && grafo[x][y] == c){
            if(x + 1 != n && grafo[x + 1][y] == '.'){
                cola.push(make_tuple(x + 1, y, c));
                grafo[x + 1][y] = c;
                res[x + 1][y] = res[x][y] + 1;
            } 

            if(x - 1 != -1 && grafo[x - 1][y] == '.'){
                cola.push(make_tuple(x - 1, y, c));
                grafo[x - 1][y] = c;
                res[x - 1][y] = res[x][y] + 1;
            }

            if(y + 1 != m && grafo[x][y + 1] == '.'){
                cola.push(make_tuple(x, y + 1, c));
                grafo[x][y + 1] = c;
                res[x][y + 1] = res[x][y] + 1;
            }

            if(y - 1 != -1 && grafo[x][y - 1] == '.'){
                cola.push(make_tuple(x, y - 1, c));
                grafo[x][y - 1] = c;
                res[x][y - 1] = res[x][y] + 1;
            }
            
            if(x + 1 == n || y + 1 == m || x - 1 == -1 || y - 1 == -1){
                acabo = true;
                break;
            }
        }

        if(c == 'F' && x < n && y < m && y >= 0 && x >= 0 && visitadosf[x][y] == false){
            visitadosf[x][y] = true;
            if(x + 1 != n && grafo[x + 1][y] != '#' && grafo[x + 1][y] != 'F'){
                cola.push(make_tuple(x + 1, y, c));
                grafo[x + 1][y] = c;
            }

            if(x - 1 != -1 && grafo[x - 1][y] != '#' && grafo[x - 1][y] != 'F'){
                cola.push(make_tuple(x - 1, y, c));
                grafo[x - 1][y] = c;
            }

            if(y + 1 != n && grafo[x][y + 1] != '#' && grafo[x][y + 1] != 'F'){
                cola.push(make_tuple(x, y + 1, c));
                grafo[x][y + 1] = c;
            }

            if(y - 1 != -1 && grafo[x][y - 1] != '#' && grafo[x][y - 1] != 'F'){
                cola.push(make_tuple(x, y - 1, c));
                grafo[x][y - 1] = c;
            }
        }
    }
    if(acabo)
        cout << res[x][y] + 1 << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}

int main(){
    int cases;
    char c;
    cin >> cases;
    while(cases--){
        cin >> n >> m;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> c;
                if(c == 'J')
                    cola.push(make_tuple(i, j, 'J'));

                else if(c == 'F')
                    vec.push_back(make_tuple(i, j, 'F'));
                
                grafo[i].push_back(c);
                visitadosf[i][j] = false;
                res[i][j] = 0;
            }
        }

        for(int i = 0; i < vec.size(); i++)
            cola.push(vec[i]);

        BFS();
        
        acabo = false;
        vec.clear();

        for(int i = 0; i < n; i++)
            grafo[i] = vector <char> ();

        while(!cola.empty())
            cola.pop();
    }

    return 0;
}