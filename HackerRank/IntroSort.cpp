#include <iostream>
#include <vector>

using namespace std;

vector <int> vec(1002);
int n;

int bin_lower(int x){
	int low = 0, high = n;
	while(low + 1 < high){
		int mid = (low + high) / 2;
		if(vec[mid] > x)
			high = mid;
		else
			low = mid;
	}
	return low;
}

int main(){
	int v;

	cin >> v >> n;

	for(int i = 0; i < n; i++)
		cin >> vec[i];

	cout << bin_lower(v) << endl;

	return 0;
}