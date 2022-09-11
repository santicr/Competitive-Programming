#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

/* La complejidad de este ejercicio es de O(n^2), es aceptado debido a que no sobrepasa los límites
	de UVa en donde su complejidad es hasta 10^9*/

int main(){
	int casos;
	string cadena;
	cin >> casos;
	cin.ignore();
	getline(cin, cadena);

	for(int i = 0; i < casos; i++){
		int contador = 0;
		map <string, float> Mapa;

		while(getline(cin, cadena) && cadena != ""){
			contador++;

			if(Mapa.count(cadena) == 0){
				Mapa.insert({cadena , 1});
			}
			else if(Mapa.count(cadena) == 1){
				Mapa[cadena]++;
			}
		}

		for(map<string, float> :: iterator it = Mapa.begin(); it != Mapa.end(); ++it){
			printf("%s %.4f\n", (it -> first).c_str(), ((it -> second)*100/contador));
		}

		Mapa.clear();
		if(i != casos-1)
			cout << endl;
	}

	return 0;
}