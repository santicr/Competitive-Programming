#include <string.h>
#include <stdio.h>

int matrix[12][4] = {{0, 0, 0, 0},{1, 1, 1, 1},{2, 4, 8, 6},
					 {3, 9, 7, 1},{4, 6, 4, 6},{5, 5, 5, 5},{6, 6, 6, 6},
					 {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1, 9, 1}, {0, 0, 0, 0}};

int main(){
	char str1[110], str2[110];
	scanf("%s %s", str1, str2);
	while(1){
		if(strcmp(str1, "0") == 0 && strcmp(str2, "0") == 0)
			break;
		int temp1 = str1[strlen(str1) - 1] - '0', temp2, i, indice = 0;
		if(strlen(str2) > 1){
			temp2 = ((str2[strlen(str2) - 2] - '0') * 10) + str2[strlen(str2) - 1] - '0';
			temp2 = (temp2 == 0) ? temp2 = 100 : temp2;
		}
		else
			temp2 = str2[0] - '0';

		if(temp1 == 0)
			printf("0\n");
		else if(temp1 == 1 || temp2 == 0 && strlen(str2) == 1)
			printf("1\n");
		else{
			for(i = 0; i < temp2; i++, indice++)
				indice = (indice == 4) ? indice = 0: indice;

			printf("%d\n", matrix[temp1][indice - 1]);
		}

		scanf("%s %s", str1, str2);
	}

	return 0;
}