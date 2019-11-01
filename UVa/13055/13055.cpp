#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	int n;
	string name, ignore;
	stack <string> pilita;
	cin >> n;
	while(n--){
		cin >> ignore;
		if(ignore == "Sleep")
			cin >> name;
		if(ignore == "Sleep")
			pilita.push(name);
		else if(ignore == "Kick"){
			if(!pilita.empty())
				pilita.pop();
		}
		else if(ignore == "Test"){
			if(pilita.empty())
				cout << "Not in a dream" << endl;
			else
				cout << pilita.top() << endl;
		}
	}

	return 0;
}