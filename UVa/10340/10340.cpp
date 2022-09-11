#include <iostream>
#include <string>

using namespace std;

int main(){
	string a, b;
	while(cin >> a){
		int indice = 0;
		cin >> b;

		for(int i = 0; i < b.size(); i++)
			indice = (a[indice] == b[i]) ? indice += 1 : indice;

		if(indice == a.size())
			printf("Yes\n");
		else
			printf("No\n");
	}


	return 0;
}