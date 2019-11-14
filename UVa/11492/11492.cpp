#include <iostream>
#include <string>
#include <vector>

struct trio{
	string s1, s2, s3;
};

int main(){
	int cases;
	string str1, str2, str3, str4, str5;
	while(cin >> cases){
		vector <trio> vec;
		cin >> str1 >> str2;
		for(int i = 0; i < cases; i++){
			cin >> str3 >> str4 >> str5;
			trio temp;
			temp.s1 = str3;
			temp.s2 = str4;
			temp.s3 = str5;
			vec.push_back(temp);
		}
		for(int i = 0; i < vec.size(); i++){
			if(vec[i].s1 == str1){
				
			}
		}
	}

	return 0;
}