#include <bits/stdc++.h>

using namespace std;

int vis[10][10][10][10];

int bfs(vector <int> start, vector <int> end){
	vector <int> u, v;
	queue <vector<int>> q;
	int p[10][10][10][10] = {0};
	int u1, u2, u3, u4, v1, v2, v3, v4;
	vector <vector<int>> mat = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

	vis[start[0]][start[1]][start[2]][start[3]] = 1;
	p[start[0]][start[1]][start[2]][start[3]] = 0;
	q.push(start);

	while(!q.empty()){
		u = q.front();
		u1 = u[0], u2 = u[1], u3 = u[2], u4 = u[3];

		if(u1 == end[0] && u2 == end[1] && u3 == end[2] && u4 == end[3])
			return p[u1][u2][u3][u4];

		for(int i = 0; i < 4; i++){
			v1 = (u[0] + mat[i][0]) % 10, v2 = (u[1] + mat[i][1]) % 10, v3 = (u[2] + mat[i][2]) % 10;
			v4 = (u[3] + mat[i][3]) % 10;

			if(!vis[v1][v2][v3][v4]){
				vis[v1][v2][v3][v4] = 1;
				p[v1][v2][v3][v4] = p[u1][u2][u3][u4] + 1;
				q.push({v1, v2, v3, v4});
			}

			v1 = (u[0] - mat[i][0]), v2 = (u[1] - mat[i][1]), v3 = (u[2] - mat[i][2]), v4 = (u[3] - mat[i][3]);
			v1 = v1 == -1 ? 9: v1;
			v2 = v2 == -1 ? 9: v2;
			v3 = v3 == -1 ? 9: v3;
			v4 = v4 == -1 ? 9: v4;

			if(!vis[v1][v2][v3][v4]){
				vis[v1][v2][v3][v4] = 1;
				p[v1][v2][v3][v4] = p[u1][u2][u3][u4] + 1;
				q.push({v1, v2, v3, v4});
			}
		}

		q.pop();
	}

	return -1;
}

int main(){
	int cases, n, num;

	cin >> cases;

	while(cases--){
		int n1, n2, n3, n4;
		vector <int> start, end;

		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
				for(int l = 0; l < 10; l++)
					for(int k = 0; k < 10; k++)
						vis[i][j][l][k] = 0;

		for(int i = 0; i < 4; i++){
			cin >> n;
			start.push_back(n);
		}

		for(int i = 0; i < 4; i++){
			cin >> n;
			end.push_back(n);
		}

		cin >> n;

		for(int i = 0; i < n; i++){
			vector <int> temp;

			for(int i = 0; i < 4; i++){
				cin >> num;
				temp.push_back(num);
			}

			n1 = temp[0];
			n2 = temp[1];
			n3 = temp[2];
			n4 = temp[3];
			vis[n1][n2][n3][n4] = 1;
		}

		cout << bfs(start, end) << endl;
	}

	return 0;
}