#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.second != b.second){
		return a.second < b.second;
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
		map <int, vector<int> > mapaCiudad;

		while(roads--){
			scanf("%d %d", &indice, &indice2);
			mapa[indice]++;
			mapa[indice2]++;
			mapaCiudad[indice].push_back(indice2);
			mapaCiudad[indice2].push_back(indice);
		}

		vector<pair<int, int>> mapVector;

		for (auto iterator = mapa.begin(); iterator != mapa.end(); ++iterator) {
			mapVector.push_back(*iterator);
		}
		sort(mapVector.begin(), mapVector.end(), compare);

		int temp = -1;
		int temp2 = -1;
		int res = 1;

		for(int i = 0; i < neighbors; i++){

				temp = mapVector[i].second;	
				temp2 = mapVector[i].first;

				vector<int>::iterator it2 = find(mapaCiudad[temp2].begin(), mapaCiudad[temp2].end(), mapVector[i + 1].first); 
				
				vector<int>::iterator it = mapaCiudad[temp2].end();

				if(it2 != it){
					res++;
				}
				else if(it2 == it){
					res = 1;
				}
		
		}

		cout << res << endl;

	}

	return 0;
}