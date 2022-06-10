#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> adj(101);
int visited[102] = {0};

void bfs(int nodo){
	queue <int> q;
	q.push(nodo);
	int u, v;

	while(!q.empty()){
		u = q.front();
	
		for(int i = 0; i < adj[u].size(); i++){
			v = adj[u][i];

			if(!visited[v]){
				visited[v] = 1;
				q.push(v);
			}
		}

		q.pop();
	}
}

int main(){
	int n, u, v, q, s, res;
	cin >> n;

	while(n != 0){
		cin >> u;
		vector <int> ans;
		for(int i = 0; i < n; i++)
			visited[i] = 0;
		adj = vector <vector <int>> (101);

		while(u != 0){
			cin >> v;

			while(v != 0){
				adj[u - 1].push_back(v - 1);
				cin >> v;
			}

			cin >> u;
		}

		cin >> q;

		while(q--){
			cin >> s;
			for(int i = 0; i < n; i++)
				visited[i] = 0;
			res = 0;
			ans = vector <int> ();
			bfs(s - 1);

			for(int i = 0; i < n; i++){
				if(!visited[i]){
					ans.push_back(i + 1);
					res++;
				}
			}

			printf("%d", res);
			
			for(int i = 0; i < ans.size(); i++)
				printf(" %d", ans[i]);

			printf("\n");
		}

		cin >> n;
	}


	return 0;
}