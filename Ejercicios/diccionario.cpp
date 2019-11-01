#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

map <char, list <string>> crearDiccionario(list <string> l){
	map <char, list <string>> mapa;
	list <string> :: iterator it = l.begin();
	for(; it != l.end(); it++){
		string temp = *it;
		char a = temp[0];
		mapa[a].push_back(temp);
	}
	return mapa;
}
void printMap(map <char, list<string>> diccionario){
	for(auto it = diccionario.begin(); it != diccionario.end(); it++){
		cout << it -> first << " -> ";
		for(auto itt = (it -> second).begin(); itt != (it -> second).end(); itt++){
			cout << *itt << " ";
		}
		cout << endl;
	}
}

int main(){
	list <string> l;
	l.push_back("hola");
	l.push_back("mundo");
	l.push_back("hehe");
	l.push_back("cruel");

	map <char, list<string>> diccionario = crearDiccionario(l);
	printMap(diccionario);

	return 0;
}