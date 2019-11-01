#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

unsigned long long H(long long int n){
	unsigned long long res = 0, i = 1, j = 1, cont = 0;
	int iterador = sqrt(n);
	bool igual = false;
	vector <int> v;

	if(n <= 0)
		return 0;

	for(; i <= iterador + 1; i++){
		if(n/i != iterador)
			res += n/i;
		v.push_back(n/i);
		if(n/i == iterador && i != iterador + 1)
			igual = true;
	}

	if(igual == false){
		while(j <= iterador){
			res += (j * (v[cont] - v[cont + 1]));
			j++;
			cont++;
		}
	}

	else{
		while(j <= iterador){
			res += (j * (v[cont] - v[cont + 1]));
			j++;
			cont++;
		}
		res -= v.back();
	}

	return res;
}

int main(){
	int casos;
	cin >> casos;
	
	for(int i = 0; i < casos; i++){
		unsigned long long int n, este = 21;
		cin >> n;
		cout << H(n) << endl;
	}

	return 0;
}