#include <bits/stdc++.h>

using namespace std;

map <char, vector <char>> graph;
map <char, int> visited;
string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int transform(char c){
	for(int i = 0; i < letters.size(); i++)
		if(letters[i] == c)
			return i + 1;
	return -1;
}

void BFS(char c){
	queue <char> q;
	visited[c] = 1;
	q.push(c);
	char f;

	while(!q.empty()){
		f = q.front();
		q.pop();

		for(int i = 0; i < graph[f].size(); i++){
			if(!visited[graph[f][i]]){
				visited[graph[f][i]] = 1;
				q.push(graph[f][i]);
			}
		}
	}
}

int main(){
	char c, c1, c2;
	int cases, res = 0;
	string str, blank;
	map <char, vector <char>> :: iterator it;
	
	scanf("%d\n\n", &cases);

	for(int i = 0; i < cases; i++){
		getline(cin, str);

		for(int j = 0; j < transform(str[0]); j++)
			graph[letters[j]] = vector <char> ();

		while(getline(cin, str) && str.size()){
			c1 = str[0];
			c2 = str[1];
			graph[c1].push_back(c2);
			graph[c2].push_back(c1);
		}

		it = graph.begin();

		for(; it != graph.end(); it++)
			visited[it -> first] = 0;

		it = graph.begin();

		for(; it != graph.end(); it++){
			if(!visited[it -> first]){
				res++;
				BFS(it -> first);
			}
		}

		if(i > 0)
			cout << endl;

		cout << res << endl;

		res = 0;
		graph = map <char, vector <char>> ();

	}

	return 0;
}