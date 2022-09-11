#include <iostream>
#include <string>

using namespace std;

int main(){
	int L;
	
	while(cin >> L){
		string cadena;
		bool hay = false;
		if(L == 0)
			break;
		cin >> cadena;
		int res;
		for(int i = 0; i < cadena.size(); i++){
			if(cadena[i] == 'Z'){
				hay = true;
				cout << 0 << endl;
				break;
			}
		}
		int ind1 = 9999999, ind2 = 9999999, ind3 = 9999999;
		if(hay == false){	
			for(int i = 0; i < cadena.size(); i++){
				if(cadena[i] == 'R')
					ind2 = i;
				if(cadena[i] == 'D')
					ind3 = i;
				if(ind2 != 9999999 && ind3 != 9999999){
					if(ind2 > ind3){
						res = ind2 - ind3;
						if(res < ind1)
							ind1 = res;
					}
					else{
						res = ind3 - ind2;
						if(res < ind1)
							ind1 = res;
					}
				}
			}
			cout << ind1 << endl;
		}
	}

	return 0;
}