#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> funcion(string cadena, int n){
	vector <string> vec;
	int multi = cadena.size() / n, i, j;
	int indice = 0;
	string temp, temp2;

	for(i = multi; i <= cadena.size(); i += multi){
		temp = cadena.substr(indice, i - indice);
		indice = i;

		for(j = temp.size() - 1; j >= 0; j--)
			temp2.push_back(temp[j]);

		vec.push_back(temp2);

		temp2.clear();
	}

	return vec;
}

int main(){
	string cadena;
	int n, i, indice = 0;
	scanf("%d", &n);
	while(n != 0){
		if(indice == 0)
			cin >> cadena;
		indice = 1;
		vector <string> vec = funcion(cadena, n);

		for(i = 0; i < vec.size(); i++)
			cout << vec[i];

		cout << endl;

		cin >> n;
		
		if(n != 0)
			cin >> cadena;


	}
	return 0;
}