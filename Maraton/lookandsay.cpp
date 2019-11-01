#include <iostream>
#include <string>
#include <cstring>
#include <list>

struct Pareja{
	int num;
	int cont = 0;
} typedef P;

using namespace std;

int main(){
	char x[5];
	int j, i;
	scanf("%s %d %d", x, &i, &j);
	while(1){
		if(strlen(x) == 0 && i == 0 && j == 0)
			break;
		i--;
		char pos1 = x[0];
		P arr[10000];
		list <char> lista;
		string temp = x;
		int indice = 0;

		while(i--){

			for(int k = 0; k < temp.size(); k++){

				if(temp[k] == pos1){
					arr[indice].num = pos1 - '0';
					arr[indice].cont++;			
				}
				
				else{
					pos1 = temp[k];
					indice++;
					arr[indice].num = pos1 - '0';
					arr[indice].cont++;
				}
			}

			temp = "";

			for(int k = 0; k <= indice; k++){
				temp.push_back(arr[k].cont + 48);
				temp.push_back(arr[k].num + 48);
			}

			for(int k = 0; k <= indice; k++){
				arr[k].cont = 0;
				arr[k].num;
			}

			indice = 0;
			pos1 = temp[0];
		}

		lista.push_back(temp[j - 1]);
		auto it = lista.end();
		it--;
		cout << *it << endl;
		scanf("%s %d %d", x, &i, &j);
	}

	return 0;
}