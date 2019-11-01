#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, s;
	while(cin >> n){
		vector <int> vec;
		cin >> s;
		int num, k = 1, l = 1, temp;
		for(int i = 0; i < n; i++){
			cin >> num;
			vec.push_back(num);
		}
		int res = 0, res2 = 999999999;
		bool paso = false;
		for(int i = 0; i < n; i++){
			res = vec[i];
			for(int j = i + 1; j < n; j++){
				res += vec[j];
				l++;
				if(res >= s){
					paso = true;
					res = 0;
					if(l < res2)
						res2 = l;
					break;
				}
			}
			l = 1;
		}
		for(int i = 0; i < n; i++)
			if(vec[i] >= s)
				res2 = 1;
		if(paso)
			cout << res2 << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}