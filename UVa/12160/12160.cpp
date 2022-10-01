#include <bits/stdc++.h>

using namespace std;

int bfs(int start, int end, vector <int> buttons){
	queue <int> q;
	int u, v;
	int vis[10001] = {0};
	int p[10001] = {0};

	q.push(start);
	vis[start] = 1;
	p[start] = 0;

	while(!q.empty()){
		u = q.front();
		if(u == end)
			return p[u];

		for(int i = 0; i < buttons.size(); i++){
			v = (u + buttons[i]) % 10000;

			if(!vis[v]){
				vis[v] = 1;
				q.push(v);
				p[v] = p[u] + 1;
			}
		}

		q.pop();
	}

	return -1;
}

int main(){
	int l, u, r, num, i = 1, ans;

	cin >> l >> u >> r;

	while(l || u || r){
		vector <int> buttons;

		while(r--){
			cin >> num;
			buttons.push_back(num);
		}

		ans = bfs(l, u, buttons);

		printf("Case %d: ", i++);

		if(ans != -1)
			cout << ans << endl;
		else
			printf("Permanently Locked\n");

		cin >> l >> u >> r;
	}

	return 0;
}