#include <stdio.h>

int main(){
	int array[13], size, i, j, k, l, m, n;
	scanf("%d", &size);
	while(size != 0){
		for(i = 0; i < size; i++)
			scanf("%d", &array[i]);

		for(i = 0; i < size; i++)
			for(j = i + 1; j < size; j++)
				for(k = j + 1; k < size; k++)
					for(l = k + 1; l < size; l++)
						for(m = l + 1; m < size; m++)
							for(n = m + 1; n < size; n++)
								printf("%d %d %d %d %d %d\n", array[i], array[j],
									array[k], array[l], array[m], array[n]);

		scanf("%d", &size);
		if(size > 0)
			printf("\n");
	}
	return 0;
}