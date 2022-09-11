#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>

using namespace std;

int main(){
	int casos;
	cin >> casos;
	while(casos--){
		vector <char> signos;
		vector <long long int> numeros, maximo, minimo;
		long long int max = 1, j = 0, min = 0;
		int indice_sig = 0, indice_num = 0, indice_temp = 0;
		string cadena;
		cin >> cadena;
		for(int i = 0; i < cadena.size(); i++){
			if(cadena[i] == '+' || cadena[i] == '*'){
				signos.push_back(cadena[i]);
				string temp = cadena.substr(indice_temp, i - indice_temp);
				numeros.push_back(atoi(temp.c_str()));
				indice_temp = i + 1;
			}
		}
		string temp = cadena.substr(indice_temp, cadena.size());
		numeros.push_back(atoi(temp.c_str()));
		long long int aux_a = numeros[0], suma, aux_b;
		for(int i = 1; i < numeros.size(); i++){
			aux_b = numeros[i];
			if(signos[i - 1] == '+'){
				suma = aux_a + aux_b;
				aux_a = suma;
			}
			else{
				maximo.push_back(aux_a);
				aux_a = aux_b;
			}
		}
		maximo.push_back(aux_a);
		suma = 0;
		aux_b = 0;
		for(int i = 0; i < maximo.size(); i++)
			max *= maximo[i];
		aux_a = numeros[0];
		for(int i = 1; i < numeros.size(); i++){
			aux_b = numeros[i];
			if(signos[i - 1] == '*'){
				suma = aux_a * aux_b;
				aux_a = suma;
			}
			else{
				minimo.push_back(aux_a);
				aux_a = aux_b;
			}
		}
		minimo.push_back(aux_a);
		for(int i = 0; i < minimo.size(); i++)
			min += minimo[i];
		cout << "The maximum and minimum are " << max << " and " << min << "." << endl;
	}
	return 0;
}