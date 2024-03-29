#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> sols;
int n;

bool esPrimo(int num){
	if(num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13
		|| num == 17 || num == 19 || num == 23 || num == 29 || num == 31 || num == 37)
		return true;
	return false;
}

void solve(vector <int> visitados, vector <int> sol){
	int tam = sol.size();
	cout << tam << endl;

	if(tam < n){
		for(int i = 2; i <= n; i++){
			if(!visitados[i] && esPrimo(i + sol[tam - 1])){
				visitados[i] = 1;
				sol.push_back(i);
				solve(visitados, sol);
				sol.pop_back();
				visitados[i] = 0;
			}
		}
	}
	else{
		if(esPrimo(sol[0] + sol[tam - 1]))
			sols.push_back(sol);
	}
}

int main(){
	int casos = 1;
	while(cin >> n){
		if(casos >= 2)
			printf("\n");
		vector <int> visitados;
		
		for(int i = 0; i <= n + 4; i++)
			visitados.push_back(0);

		solve(visitados, vector <int> (1));

		cout << "Case " << casos++ << ":" << '\n';
		for(int i = 0; i < sols.size(); i++){
			for(int j = 0; j < n; j++){
				if(j == 0)
					cout << sols[i][j];
				else
					cout << " " << sols[i][j];
			}
			cout << endl;
		}

		sols = vector <vector<int>> ();
	}

	return 0;
}