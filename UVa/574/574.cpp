#include <iostream>
#include <vector>

using namespace std;

int main(){
	int number, size, i, j;
	scanf("%d %d", &number, &size);
	while(size != 0){
		vector <int> vec, res;
		int combinaciones = 0;
		int temp;
		for(i = 0; i < size; i++){
			cin >> temp;
			vec.push_back(temp);
		}
		for(i = 0; i < size; i++){
			res.push_back(i);
			int temp = vec[i];
			for(j = i + 1; j < size; j++){
				temp += vec[j];
				if(temp > number){
					auto it = vec.begin() + i;
					vec.erase(it);
					res.clear();
					break;
				}
				if(temp < number)
					res.push_back(j);
				if(temp == number){
					auto it = vec.begin() + i;
					vec.erase(it);
					res.push_back(j);
					combinaciones++;
					break;
				}
			}
		}
		cout << combinaciones << endl;
		for(i = 0; i < res.size(); i++)
			cout << vec[res[i]] << " " << endl;
		scanf("%d %d", &number, &size);
	}


	return 0;
}