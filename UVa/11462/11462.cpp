#include <iostream>

using namespace std;

int main(){
	int cases;
	cin >> cases;
	while(cases != 0){
		int num, arr[101], index = 0;
		for(int i = 0; i < 100; i++)
			arr[i] = 0;
		for(int i = 0; i < cases; i++){
			cin >> num;
			arr[num]++;
		}
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < arr[i]; j++){
				if(index == 0){
					index++;
					printf("%d", i);
				}
				else
					printf(" %d", i);
			}
		}
		printf("\n");
		cin >> cases;
	}

	return 0;
}