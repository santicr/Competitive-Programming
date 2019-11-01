#include <iostream>
#include <string>

using namespace std;

int main(){
	string cadena;
	while(getline(cin, cadena)){
		int indice = 0;
		string cadena2;
		double num1 = 0, num2 = 0;
		while(indice != 2){
			getline(cin, cadena2);
			if(indice == 0){
				for(int i = 0; i < cadena.size(); i++){
					if(cadena[i] >= 'a' && cadena[i] <= 'Z')
						num1 += cadena[i] - '0';
				}
			}
			if(indice == 1){
				for(int i = 0; i < cadena2.size(); i++){
					if(cadena2[i] >= 'a' && cadena2[i] <= 'Z')
						num2 += cadena2[i] - '0';
				}
			}
			indice++;
		}
		double res = num1 / num2;
		printf("%.2f\n", res);
	}

	return 0;
}