/* Nivel 1 */
#include <stdio.h>
#include <stdlib.h>

int main(){
	int este = 1;
	while(este){
		int casos, i;
		scanf("%d", &casos);
		if(casos == 0)
			break;
		int centro1, centro2;
		scanf("%d %d", &centro1, &centro2);
		for(i = 0; i < casos; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			if(x == centro1 || y == centro2)
				printf("divisa\n");
			else if(x < centro1 && y < centro2)
				printf("SO\n");
			else if(x > centro1 && y > centro2)
				printf("NE\n");
			else if(x < centro1 && y > centro2)
				printf("NO\n");
			else
				printf("SE\n");
		}

	}

	return 0;
}