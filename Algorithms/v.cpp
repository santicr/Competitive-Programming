#include <iostream>
#include <map>

using namespace std;

int main(){
	map <int, int> mapa;
	int i = 0;
	mapa[i]++;
	auto it = mapa.begin();
	for(; it != mapa.end(); it++)
		cout << it -> first << " " << it -> second << endl;

	return 0;
}