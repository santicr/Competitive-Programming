#include <iostream>
#include <string>
#include <vector>

using namespace std;

string code(string str){
	string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?'!/()&:;=+-_";
	symbols.push_back('"');
	symbols.push_back('@');
	string ans;
	bool estuvo = false;
	int index = 0, paso = 0, paso2 = 0;
	vector <string> sub;
	vector <string> code = {".-", "-...", "-.-.", "-..", ".", "..-.",
	"--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", 
	".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
	"-.--", "--..", "-----", ".----", "..---", "...--", "....-", 
	".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", 
	"..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", 
	".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", 
	".-..-.", ".--.-."};

	for(int i = 0; i < str.size(); i++){
		if(str[i] == ' ' && str[i + 1] == ' ' && paso >= 1){
			if(estuvo == false)
				ans.push_back(' ');
			estuvo = true;
		}
		else if(str[i] != ' '){
			index = i;
			for(int j = index; j < str.size(); j++){
				if(str[j] == ' '){
					i = j - 1;
					for(int k = 0; k < code.size(); k++){
						if(code[k] == str.substr(index, j - index)){
							ans.push_back(symbols[k]);
							break;
						}
					}
					break;
				}
			}
			paso++;
			estuvo = false;
		}
		if(i == str.size() - 1){
			for(int j = str.size() - 1; j >= 0; j--){
				if(str[j] != ' ' && str[j - 1] == ' '){
					index = j;
					break;
				}
			}
			for(int j = 0; j < code.size(); j++){
				if(code[j] == str.substr(index, str.size() - index)){
					ans.push_back(symbols[j]);
					break;
				}
			}
		}
	}

	return ans;
}

int main(){
	int cases, i = 1;
	cin >> cases;
	string str;
	while(i <= cases){
		cin >> ws;
		getline(cin, str);
		cout << "Message #" << i << endl;
		cout << code(str) << endl;
		if(i != cases)
			cout << endl;
		i++;
	}

	return 0;
}