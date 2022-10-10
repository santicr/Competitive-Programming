#include <bits/stdc++.h>

using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz";
map <string, vector<string>> words;
int abc_size = abc.size();

int bfs(string start, string end){
	queue <string> q;
	map <string, int> vis;
	string u, v;

	q.push(start);
	vis[start] = 1;

	while(!q.empty()){
		u = q.front();
		q.pop();

		for(int i = 0; i < words[u].size(); i++){
			v = words[u][i];
			if(!vis[v]){
				q.push(v);
				vis[v] = vis[u] + 1;
			}
		}
	}

	return vis[end] - 1;
}

int main(){
	int cases;
	string word, start, end;

	cin >> cases;

	while(cases--){
		vector <string> wds;
		int wds_size;
		cin >> word;
		while(word != "*"){
			wds.push_back(word);
			cin >> word;
		}

		wds_size = wds.size();

		cin.ignore();

		for(int i = 0; i < wds_size; i++){
			for(int j = i + 1; j < wds_size; j++){
				if(wds[i].size() == wds[j].size()){
					int diff = 0;
					for(int k = 0; k < wds[i].size(); k++){
						if(wds[i][k] != wds[j][k])
							diff++;
					}
					if(diff == 1){
						words[wds[i]].push_back(wds[j]);
						words[wds[j]].push_back(wds[i]);
					}
				}
			}
		}

		while(getline(cin, word) && word != ""){
			for(int i = 0; i < word.size(); i++){
				if(word[i] == ' '){
					start = word.substr(0, i);
					end = word.substr(i + 1, word.size() - i);
					break;
				}
			}
			cout << start << " " << end << " " << bfs(start, end) << endl;
		}

		if(cases)
			cout << endl;
	}

	return 0;
}