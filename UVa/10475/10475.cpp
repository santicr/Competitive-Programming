#include <bits/stdc++.h>

using namespace std;

map <string, vector <string>> restrictions;
vector <string> vec;
vector <vector <string>> sols;
int numWords, words, pairs;

bool c(string p1, string p2){
	if (p1.size() != p2.size())
		return p1.size() > p2.size();
	return p1 < p2;
}

bool rest(vector <string> sol, string b){
	for(int i = 0; i < sol.size(); i++){
		string a = sol[i];
		for(int j = 0; j < restrictions[a].size(); j++)
			if(restrictions[a][j] == b)
				return false;
	}

	return true;
}

void solve(vector <string> sol, int index){
	if(sol.size() == numWords)
		sols.push_back(sol);
	else{
		vector <string> sc;
		for(int i = index; i < words; i++){
			if(rest(sol, vec[i])){
				sc = sol;
				sc.push_back(vec[i]);
				solve(sc, i + 1);
			}
		}
	}
}

int main(){
	int cases, idx = 0, idx2 = 0, idx3 = 0;
	string word, p1, p2;

	cin >> cases;

	while(idx < cases){
		cin >> words >> pairs >> numWords;

		printf("Set %d:\n", (idx++) + 1);

		while(idx2 < words){
			cin >> word;
			transform(word.begin(), word.end(), word.begin(), ::toupper);
			vec.push_back(word);
			idx2++;
		}

		sort(vec.begin(), vec.end(), c);

		while(idx3 < pairs){
			cin >> p1 >> p2;
			transform(p1.begin(), p1.end(), p1.begin(), ::toupper);
			transform(p2.begin(), p2.end(), p2.begin(), ::toupper);
			restrictions[p1].push_back(p2);
			restrictions[p2].push_back(p1);
			idx3++;
		}

		for(int i = 0; i < words; i++)
			solve({vec[i]}, i + 1);

		for(int i = 0; i < sols.size(); i++){
			cout << sols[i][0];
			for(int j = 1; j < sols[i].size(); j++)
				cout << " " << sols[i][j];
			cout << endl;	
		}

		printf("\n");

		sols = vector <vector <string>> ();
		restrictions = map <string, vector <string>> ();
		vec = vector <string> ();
		idx2 = 0;
		idx3 = 0;
	}

	return 0;
}