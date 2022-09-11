#include <bits/stdc++.h>

using namespace std;

int main(){
	string linea;
	int cases;
	cin >> cases;
	while(cases--){
		vector <string> res;
		string temp = "";
		cin >> linea;
		int indice = 0;

		for(int i = linea.size() - 1; i >= 0; i--){
			if(linea[i] == linea[indice]){
				temp.insert(temp.begin(), linea[i]);
				indice++;
			}
			else{
				indice = 0;
				res.push_back(temp);
				temp = "";
			}
		}
		
		string respuesta;
		int max = -1;

		for(int i = 0; i < res.size(); i++){
			int size = res[i].size();
			if(size > max){
				max = res[i].size();
				respuesta = res[i];
			}
		}

		if(respuesta.size() > 0 && respuesta.size() > temp.size())
			cout << respuesta << endl;
		else
			cout << temp <<  endl;

		res.clear();
	}
	return 0;
}