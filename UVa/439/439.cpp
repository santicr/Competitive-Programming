#include <iostream>

using namespace std;

int main(){

	for(char a = 'a'; a < 'i'; a++){
		for(int i = 1; i <= 8; i++){
			printf("%c%d ", a, i);
		}
		printf("\n");
	}
	printf("\n");
	for(int a = 1; a <= 8; a++){
		for(char i = 'a'; i < 'i'; i++){
			printf("%c%d ", i, a);
		}
		printf("\n");
	}

	return 0;
}