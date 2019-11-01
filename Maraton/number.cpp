#include <iostream>
#include <vector>

using namespace std;

int function(int n){
	int  sum = 0;
	while(n){
		sum += ((n % 10) * (n % 10));
		n /= 10;
	}
	return sum;
}

int main(){

	int res;
	int temp;
	int number;

	while(cin >> number){

		res = function(number);
		while(res != 1 && res != 4){
			res = function(res);
		}
		if(res == 4){
			cout << "UNHAPPY" << endl;
		}
		else{
			cout << "HAPPY" << endl;
		}
	}
	return 0;
}