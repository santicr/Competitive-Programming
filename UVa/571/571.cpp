#include <bits/stdc++.h>

using namespace std;

int ca, cb, n, a, b;
vector <string> stepsA = {"fill A", "empty A", "pour A B", "fill B", "empty B", "pour B A"};

void solve(int sa, int sb, vector <int> sol){
	if(sb == n)
		sol.push_back(sol);
	else{
		for(int i = 0; i < 6; i++){
			if(sol[sol.size() - 1] != i + 1){
				sol.push_back(i + 1);
				if(i + 1 == 1){
					sa = a;
					solve(sa, sb, sol);
				}
				else if(i + 1 == 2){
					sa = 0;
					solve(sa, sb, sol);
				}
				else if(i + 1 == 2){
					sb += sa;
					if(b - sb <= 0){
						sa = (sb - b);
					}
					else{
						
					}
				}
				sol.pop_back();

			}
		}
	}
}

vector <int> bfs(int sa, int sb){

}

int main(){

	while(cin >> a){
		cin >> b >> n;
		ca = 0;
		cb = 0;
		pair <int, int> p;
		p = make_pair(ca, cb);
		solve(0, 0, )
	}

	return 0;
}