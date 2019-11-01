#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
	string str;
	while(getline(cin, str)){
		for(int i = 0; i < str.size(); i++){
			if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'){
				string temp;
				bool vowel = false;
				if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
					str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I'
					|| str[i] == 'U' || str[i] == 'O')
					vowel = true;
				if(vowel)
					temp.push_back(str[i]);
				int j = i;
				i++;
				for(; i < str.size(); i++){
					if(!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
						break;
					temp.push_back(str[i]);
				}
				i--;
				if(!vowel)
					temp.push_back(str[j]);
				temp.push_back('a');
				temp.push_back('y');
				cout << temp;
			}
			if(!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
				cout << str[i];
		}
		cout << endl;
	}

	return 0;
}