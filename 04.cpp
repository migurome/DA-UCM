#include <algorithm>
#include <iostream>
#include <fstream>
#include "TreeMap_AVL.h"

using namespace std;

bool resuelve( int nvalores) {

	bool finLeer;
	map<int, int> arbol;

	if (nvalores == 0)
		return false;

	int dato;

	for (int i = 0; i < nvalores; i++) {
		cin >> dato;
		arbol.insert(dato);
	}

	int num_busq, elem;
	map<int, int>::iterator it = arbol.begin();

	cin >> num_busq;

	for (int i = 0; i < num_busq; i++) {
		cin >> elem;
		it = arbol.begin();

		if (elem > arbol.size())
			cout << "??" << endl;
		else {
			int j = 0;
			while (j < elem - 1){
				j++;
				++it;
			}
			cout << (*it).clave << endl;
		}

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