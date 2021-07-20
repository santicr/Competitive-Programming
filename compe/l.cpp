#include <bits/stdc++.h>

using namespace std;

vector <int> vec;

int bin_lower(int x){
	int low = 0, high = vec.size();
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
	int act, minutes, start, end, temp, act2;

	cin >> act >> minutes;

	while(act--){
		cin >> start >> end;
		vec.push_back(start);
		vec.push_back(start + end);
	}

	sort(vec.begin(), vec.end());

	auto it = vec.end();
	it--;

	int minInd = INT_MAX, minVal = INT_MAX;

	for(int i = 0; i <= 480; i++){
		temp = i;
		act2 = 0;
		while(temp <= *it){
			int ind = bin_lower(temp);

			if(ind % 2 == 0){
				if(ind == 0 && temp >= vec[ind])
					act2++;
				else if(temp >= vec[ind] && temp <= vec[ind + 1])
					act2++;
			}
			else{
				if(ind == 0 && vec[ind] >= temp)
					act2++;
				else if(temp <= vec[ind] && temp >= vec[ind - 1])
					act2++;
			}
			temp += minutes;
		}

		if(act2 < minVal){
			minVal = act2;
			minInd = i;
			if(minVal == 0)
				break;
		}
	}

	cout << minInd << " " << minVal << endl;

	return 0;
}