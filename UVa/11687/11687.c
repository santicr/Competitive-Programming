#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char* cadena = (char*)malloc(20000 * sizeof(char));
	int i, j, res, temp;
	scanf("%s", cadena);
	while(cadena != "END"){
		res = strlen(cadena);
		temp = 0;
		if(strlen(cadena) == 1){
			temp = cadena[0] - '0';
		}
		printf("%d\n", res1(res, temp));
		scanf("%s", cadena);
	}

	return 0;
}