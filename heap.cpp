#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	vector <int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
	make_heap(v1.begin(), v1.end());
	cout << v1.front() << endl;
	bool paso = false;
	int k = 1;
	for(int i = 1; i < v1.size(); ){
		int j;
		if(i == 1)
			j = i * 2;
		else{
			j = (i - k) * 2;
			k *= 2;
		}
		while(j--){
			cout << v1[i] << " ";
			i++;
		}
		if(paso)
			break;

		cout << endl;
	}
	return 0;
}