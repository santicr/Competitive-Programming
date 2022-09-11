/* Nivel 0 */
#include <stdio.h>
#include <stdlib.h>

int main(){
	int casos, i;
	scanf("%d", &casos);
	for(i = 0; i < casos; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if(((x > z) && (x < y)) || ((x < z) && (x > y)))
			printf("Case %d: %d\n", i + 1, x);
		else if(((y > z) && (y < x)) || ((y < z) && (y > x)))
			printf("Case %d: %d\n", i + 1, y);
		else
			printf("Case %d: %d\n", i + 1, z);
	}

	return 0;
}