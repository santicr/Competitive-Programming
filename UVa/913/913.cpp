#include <iostream>
#include <math.h>

using namespace std;

long long int sumatoria(int N){
	long long int otro = N/2;
	long long int pot = otro * otro;
	long long int sum = pot + (2 * otro);
	sum -= 1;
	return sum;
}

long long int funcion(long long int N){
	long long int sum = (2 * N + 1) * 3;
	return sum;
}

int main(){
	int N;
	while(cin >> N){
		long long int Ni = sumatoria(N);
		cout << funcion(Ni) << endl;
	}
	return 0;
}