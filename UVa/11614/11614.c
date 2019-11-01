#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		long long int n;
		scanf("%lld", &n);
		double raiz = sqrt(1 + (8 * n));
		double min = -1 + raiz;
		min /= 2;
		double respuesta = min;
		int res = respuesta;
		printf("%d\n", res);
	}
}