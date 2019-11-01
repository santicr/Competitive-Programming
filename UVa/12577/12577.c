#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char palabra[6] = "";
	int casos = 1;
	while(scanf("%s",palabra)){
		if(strcmp(palabra, "Hajj") == 0)
			printf("Case %d: Hajj-e-Akbar\n", casos);
		else if(strcmp(palabra, "Umrah") == 0)
			printf("Case %d: Hajj-e-Asghar\n", casos);
		else
			break;
		casos++;
	}

	return 0;
}