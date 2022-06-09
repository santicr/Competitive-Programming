#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> p;
int n, k, p1, p2, ob1, ob2;
map <p, int> visited;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int bfs(p nodo, p dir){
	queue <p> q;
	p u, v;
	int x, y, ans = 1;
	q.push(nodo);

	while(!q.empty()){
		u = q.front();

		x = dir.first + u.first;
		y =	dir.second + u.second;
		v = {x, y};

		if(x >= 0 && x < n && y >= 0 && y < n && !visited[{x, y}]){
			q.push(v);
			visited[{x, y}] = 1;
			ans++;
		}

		q.pop();
	}

	return ans;
}

int main(){
	while(cin >> n){
		cin >> k;
		cin >> p1 >> p2;

		int ans = 0;
		p1 = abs(p1 - n);
		p2--;
		visited = map <p, int> ();

		for(int i = 0; i < k; i++){
			cin >> ob1 >> ob2;
			ob1 = abs(ob1 - n);
			ob2--;
			visited[{ob1, ob2}] = 1;
		}

		for(int i = 0; i < 8; i++){
			int x = p1 + dx[i], y = p2 + dy[i];
			if(x >= 0 && x < n && y >= 0 && y < n && !visited[{x, y}]){
				visited[{x, y}] = 1;
				ans += bfs({x, y}, {dx[i], dy[i]});
			}
		}

		cout << ans << endl;
	}


	return 0;
}