#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(pair<int, int> a, pair<int, int> b){
	if(a.second != b.second){
		return a.second > b.second;
	}
	return false;
}


int main(){
	int roads;
	int neighbors;
	while(cin >> neighbors){
		cin >> roads;
		int indice, indice2;
		map <int, int> mapa;
		while(roads--){
			scanf("%d %d", &indice, &indice2);
			mapa[indice]++;
			mapa[indice2]++;
		}

		vector<pair<int, int>> mapVector;

		for (auto iterator = mapa.begin(); iterator != mapa.end(); ++iterator) {
			mapVector.push_back(*iterator);
		}
		sort(mapVector.begin(), mapVector.end(), compare);


		int temp = -1;
		int res = 0;
		for(int i = 0; i < neighbors; i++){
			if(mapVector[i].second != temp){
				temp = mapVector[i].second;
				res++;
			}
		}

		cout << res << endl;

	}

	return 0;
}