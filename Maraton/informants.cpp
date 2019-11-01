#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	int a,i,r[21];
	scanf("%d %d",&i,&a);
	while(i != 0 && a != 0){
		int x,y,k,sum = 0;
		while(a--){
			scanf("%d %d",&x, &y);

			if(y > 0 && r[y] != -1){
				r[y] = 1;
			}
			else if(y < 0){
				r[abs(y)] = -1;
			}

		}
			for (k= 1; k < i+1; ++k){
				if(r[k] == 1){
					sum += 1;
				}
			}
		printf("%d\n",sum );
		scanf("%d %d", &i, &a);
	}
	return 0;
}