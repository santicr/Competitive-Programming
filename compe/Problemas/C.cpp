#include <bits/stdc++.h>

#define vi vector<int>
#define vvi  map<pair<int, int>, int>
#define endl '\n'

using namespace std;

int phi(int i,int c,vvi &mem, vi &lista){
	int ans = 0;
	if(mem.find(make_pair(i,c)) != mem.end()) ans = mem[make_pair(i, c)];
	else{
		if(i == 0) ans = 0;
		else if(lista[i-1] > c) ans = 1 + phi(i-1, c, mem, lista);
		else ans = min(phi(i-1, c - lista[i-1], mem, lista), 1 + phi(i-1, c, mem, lista));
		mem[make_pair(i, c)] = ans;
	}
	return ans;
}

int main(){
	int n, m;
	cin >> n >> m;
	vi lista(n), val(n);
	vvi mem;
	for(int i = 0; i < n; ++i) cin >> lista[i];
	for(int i = 0; i < n; ++i) val[i] = phi(i, m - lista[i], mem, lista);

	cout << val[0];
	for(int i = 1; i < n; ++i) cout << " " << val[i];
	cout << endl;
	return 0;
}