#include <iostream>
#include <string>

using namespace std;

int res1(int n, int m){
	if(m == 1)
		return 1;
	if(n == 1)
		return 2;
	if(n <= 9)
		return 3;
	if(n >= 10)
		return 4;
	return 0;
}

int main(){
	string cadena;
	int i, j, res, temp;
	cin >> cadena;
	while(cadena != "END"){
		res = cadena.size();
		temp = 0;
		if(cadena.size() == 1){
			temp = cadena[0] - '0';
		}
		printf("%d\n", res1(res, temp));
		cin >> cadena;
	}

	return 0;
}