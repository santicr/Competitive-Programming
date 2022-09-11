#include <stdlib.h>
#include <stdio.h>
/*
Author: Santiago Caicedo Rojas
Github: https://github.com/santicr
UVa profile: https://uhunt.onlinejudge.org/id/1033486
*/
int problems[14];

int main(){
	int acum, i, cases = 1, t;
	scanf("%d", &acum);
	problems[0] = acum;

	while(problems[0] >= 0){
		acum = 0;
		printf("Case %d:\n", cases++);

		for(i = 1; i <= 12; i++)
			scanf("%d", &problems[i]);

		for(i = 0; i < 12; i++){
			scanf("%d", &t);
			acum += problems[i];

			if(acum >= t){
				acum -= t;
				printf("No problem! :D\n");
			}
			else
				printf("No problem. :(\n");
		}

		scanf("%d", &acum);
		problems[0] = acum;
	}

	return 0;
}