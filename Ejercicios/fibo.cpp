#include <iostream>

using namespace std;

int fibo(int n){
	int ant1 = 0, ant2 = 1, res = 0;
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	for(int i = 2; i <= n; i++){
		res = ant1 + ant2;
		ant1 = ant2;
		ant2 = res;
	}
	return res;
}

int main(){
	printf("%d\n", fibo(14));
}