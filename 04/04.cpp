#include <algorithm>
#include <iostream>
#include <fstream>
#include "TreeMap_AVLM.h"

using namespace std;

bool resuelve( int nvalores) {

	bool finLeer;
	map<int, int,std::less<int>> arbol;
	int dato;

	if (nvalores == 0)
		return false;

	for (int i = 0; i < nvalores; i++) {
		cin >> dato;
		arbol.insert(dato);
	}

	int num_busq, elem;
	
	cin >> num_busq;

/*
	map<int, int>::iterator it = arbol.begin();
	for (int i = 1; i <= arbol.size(); i++) {
		cout << (*it).clave << endl;
		++it;
	}
*/

	for (int i = 0; i <  num_busq; i++) {
		cin >> elem;
		map<int, int>::iterator it = arbol.begin();

		if (elem < arbol.size()) {
			for (int i = 1; i < elem; i++)	
				++it;

			cout << (*it).clave << endl; 
		}	
		else 
			cout << "??" << endl;
	}

	cout << "----" << endl;

	return true;
}


int main(int argc, char** args) {

	bool fin;

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int n_valores;

	do {
		cin >> n_valores;
	} while (resuelve(n_valores));


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}