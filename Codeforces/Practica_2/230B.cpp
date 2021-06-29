//Accepted
#include <bits/stdc++.h>

using namespace std;

bool esPrimo(int numero) {
	for(int i = 2; i <= sqrt(numero); i++){
		if(numero % i == 0)
			return false;
	}
	return true;
}

int main(){
	int n;
	long long int number, num;
	cin >> n;

	while(n--){
		bool flag = false;

		cin >> number;
		num = sqrt(number);

		if(number == 1)
			cout << "NO" << endl;
		else if(num * num == number && esPrimo(num))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

	return 0;
}