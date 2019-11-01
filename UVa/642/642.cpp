#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){
	string str;
	int next = 0;
	list <string> dictionary, scramble_words;
	while(cin >> str){
		if(str == "XXXXXX")
			next++;

		if(next == 2)
			break;

		if(next == 0)
			dictionary.push_back(str);

		else if(next == 1 && str != "XXXXXX")
			scramble_words.push_back(str);
	}

	for(auto it = scramble_words.begin(); it != scramble_words.end(); it++){
		int hay = 0;
		list <string> unscramble;
		for(auto itt = dictionary.begin(); itt != dictionary.end(); itt++){
			int same = 0, arr[6] = {0, 0, 0, 0, 0, 0};
			for(int i = 0; i < it -> size(); i++){
				for(int j = 0; j < itt -> size(); j++){
					if(it -> at(i) == itt -> at(j)){
						if(arr[j] == 0){
							arr[j]++;
							same++;
							break;
						}
					}
				}
			}
			if(same == itt -> size() && same == it -> size()){
				unscramble.push_back(*itt);
				hay++;
				same = 0;
			}
		}
		if(hay > 0){
			unscramble.sort();
			for(auto it2 = unscramble.begin(); it2 != unscramble.end(); it2++)
				cout << *it2 << endl;
			unscramble.clear();
		}
		else if(hay == 0)
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}

	return 0;
}