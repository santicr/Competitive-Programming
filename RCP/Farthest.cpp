#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

vector <string> grafo;
bool vis[1000][1000];
int res[1000][1000];
int posi, posj, n, m, cases;
int arrx[4] = {0, 1, 0, -1};
int arry[4] = {1, 0, -1, 0};

int recorrer(){
	for(int i = 0; i < 1000; i++)
		for(int j = 0; j < 1000; j++)
			res[i][j] = 0;
	queue <pair <int, int> > cola;
	cola.push(make_pair(posi, posj));
	vis[posi][posj] = true;
	res[posi][posj] = 0;
	
	int max = -1;
	
	while(!cola.empty()){
		pair <int, int> val = cola.front();
		int x = val.first, y = val.second;
		cola.pop();
		
		for(int i = 0; i < 4; i++){
			if(grafo[x + arrx[i]][y + arry[i]] == '.' && !vis[x + arrx[i]][y + arry[i]]){
				vis[x + arrx[i]][y + arry[i]] = true;
				res[x + arrx[i]][y + arry[i]] = res[x][y] + 1;
				if(max < res[x + arrx[i]][y + arry[i]])
					max = res[x + arrx[i]][y + arry[i]];
				cola.push(make_pair(x + arrx[i], y + arry[i]));
			}
		}
	}
	
	return max;
}

int main(){
	string cadena;
	int r = -1;
	cin >> cases;
	
	while(cases--){
		bool paso = false;
		cin >> n >> m;
		
		while(m--){
			r++;
			cin >> cadena;
			if(!paso){
				for(int i = 0; i < cadena.size(); i++){
					if(cadena[i] == '@'){
						paso = true;
						posi = r;
						posj = i;
						break;
					}
				}
			}
			grafo.push_back(cadena);
		}
		cout << posi << posj << endl;
		
		cout << recorrer() << endl;
	}
	
	return 0;
}
