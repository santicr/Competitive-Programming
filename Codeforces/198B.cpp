#include <bits/stdc++.h>

using namespace std;

int n, k;
string a, b;
vector <string> mat;

bool BFS(vector <vector<int>> &valores){
	bool ans = false;
	queue <pair<int, int>> cola;
	int dy[] = {k}, x, y;
	int dx[] = {1, -1};
	pair <int, int> q, v;
	cola.push({0, 0});
	valores[0][0] = -1;

	while(!cola.empty() && !ans){
		q = cola.front();
		y = q.first;
		x = q.second;

		if(y == 0){
			if((x + 1) >= 0 && (x + 1) < n && mat[y][x + 1] != 'X' && (x + 1) > valores[y][x] + 1 && valores[y][x + 1] == -2){
				cola.push({y, x + 1});
				valores[y][x + 1] = valores[y][x] + 1;
			}
			if((x + 1) >= 0 && (x + 1) >= n)
				ans = true;
			if((x - 1) >= 0 && (x - 1) < n && mat[y][x - 1] != 'X' && (x - 1) > valores[y][x] + 1 && valores[y][x - 1] == -2){
				cola.push({y, x - 1});
				valores[y][x - 1] = valores[y][x] + 1;
			}
			if((x + k) >= 0 && (x + k) < n && mat[y + 1][x + k] != 'X' && (x + k) > valores[y][x] + 1 && valores[y + 1][x + k] == -2){
				cola.push({y + 1, x + k});
				valores[y + 1][x + k] = valores[y][x] + 1;
			}
			if((x + k) >= 0 && (x + k) >= n)
				ans = true;
		}

		if(y == 1){
			if((x + 1) >= 0 && (x + 1) < n && mat[y][x + 1] != 'X' && (x + 1) > valores[y][x] + 1 && valores[y][x + 1] == -2){
				cola.push({y, x + 1});
				valores[y][x + 1] = valores[y][x] + 1;
			}
			if((x + 1) >= 0 && (x + 1) >= n)
				ans = true;
			if((x - 1) >= 0 && (x - 1) < n && mat[y][x - 1] != 'X' && (x - 1) > valores[y][x] + 1 && valores[y][x - 1] == -2){
				cola.push({y, x - 1});
				valores[y][x - 1] = valores[y][x] + 1;
			}
			if((x + k) >= 0 && (x + k) < n && mat[y - 1][x + k] != 'X' && (x + k) > valores[y][x] + 1 && valores[y - 1][x + k] == -2){
				cola.push({y - 1, x + k});
				valores[y - 1][x + k] = valores[y][x] + 1;
			}
			if((x + k) >= 0 && (x + k) >= n)
				ans = true;
		}
		cola.pop();
	}

	return ans;
}

int main(){
	string ans = "NO";

	cin >> n >> k;
	cin >> a;
	cin >> b;
	vector <vector<int>> valores(2,vector<int>(n, -2));

	mat.push_back(a);
	mat.push_back(b);

	ans = BFS(valores) ? ans = "YES": ans;

	cout << ans << endl;

	return 0;
}