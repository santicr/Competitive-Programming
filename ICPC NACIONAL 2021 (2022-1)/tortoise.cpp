#include <bits/stdc++.h>

using namespace std;

int n, m;
map <int, vector <int>> puentes;
int puentesAux[20000];

int solve(int r, int t, int estado){
	bool ans;
	if(turno % 2 != 0 && r >= (n - 1) && n == t)
		ans = true;
	else if(turno % 2 == 0 && r >= (n - 1) && n == t)
		ans = false;
	else if(turno % 2 != 0){
		bool p1, p2, p3, p4;
		if(puentesAux[r] > 0){
			for(int i = 0; i < puentesAux[r]; i++){
				p1 = solve(puentes[r][i] + 1, t, turno + 1);
				p2 = solve(puentes[r][i], t, turno + 1);
				p3 = solve(r + 1 + )
			}
		}
	}
}

int main(){


	return 0;
}