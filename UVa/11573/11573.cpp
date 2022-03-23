#include <bits/stdc++.h>

using namespace std;

int dirx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int diry[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, q, xi, yi, xf, yf;
string fila;
vector <string> mat;

int dist(int xi, int yi, int xf, int yf){
	return (abs(xi - xf) + abs(yf - yi));
}

bool cond(int vx, int vy){
	return vx >= 0 && vx < n && vy >= 0 && vy < m;
}

int solve(pair <int, int> pi, pair <int, int> pf){
	queue <pair <int, int>> cola;
	map <pair<int, int>, int> vis;
	pair <int,int> u, v;
	bool flag = false;
	int ux, uy, vx, vy, val, ans = -1;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			vis[{i, j}] = -1;
	
	cola.push(pi);
	vis[pi] = 0;

	while(!cola.empty()){
		u = cola.front();
		ux = u.first;
		uy = u.second;

		val = mat[ux][uy] - '0';
		vx = ux + dirx[val];
		vy = uy + diry[val];

		if(cond(vx, vy) && vis[{vx, vy}] == -1 && dist(vx, vy, pf.first, pf.second) < dist(ux, uy, pf.first, pf.second) && vx == pf.first && vy == pf.second){
			vis[{vx, vy}] = vis[{ux, uy}];
			ans = vis[{vx, vy}];
			flag = true;
			break;
		}
		else if(cond(vx, vy) && vis[{vx, vy}] == -1 && dist(vx, vy, pf.first, pf.second) < dist(ux, uy, pf.first, pf.second)){
			vis[{vx, vy}] = vis[{ux, uy}];
			cola.push({vx, vy});
		}
		else{
			for(int i = 0; i < 8; i++){
				vx = dirx[i] + ux;
				vy = diry[i] + uy;
				if(cond(vx, vy) && vis[{vx, vy}] == -1 && vx == pf.first && vy == pf.second){
					vis[{vx, vy}] = vis[{ux, uy}] + 1;
					ans = vis[{vx, vy}];
					flag = true;
					break;
				}
				else if(cond(vx, vy) && vis[{vx, vy}] == -1){
					vis[{vx, vy}] = vis[{ux, uy}] + 1;
					cola.push({vx, vy});
				}
			}
		}
		if(flag)
			break;

		cola.pop();
	}

	return ans;
}

int main(){
	while(cin >> n){
		cin >> m;
		mat = vector <string> ();

		for(int i = 0; i < n; i++){
			cin >> fila;
			mat.push_back(fila);
		}

		cin >> q;

		for(int i = 0; i < q; i++){
			cin >> xi >> yi;
			cin >> xf >> yf;

			if(xi == xf && yi == yf)
				printf("0\n");
			else
				printf("%d\n",(solve({xi - 1, yi - 1}, {xf - 1, yf - 1})));
		}
	}

	return 0;
}