#include <algorithm>
#include <iostream>
#include <fstream>
#include "TreeMap_AVL.h"

using namespace std;

bool leerCaso(map<int, int> &arbol){
	
	int dato, nvalores;

	cin >> nvalores;

	if (nvalores == 0)
		return false;

	for (int i = 0; i < nvalores; i++) {
		cin >> dato;
		arbol.insert(dato);
	}

	return true;

}

bool resuelve() {

	map<int, int> arbol;
	int num_busq, elem, kesimo;

	if (leerCaso(arbol)) {
		cin >> num_busq;

		for (int i = 0; i < num_busq; i++) {
			cin >> elem;
			kesimo = arbol.nKesimo(elem);
			if (kesimo != -1)
				cout << kesimo << endl;
			else
				cout << "??" << endl;
		}

		cout << "----" << endl;

		return true;
	}
	else
		return false;
}


int main(int argc, char** args) {
	
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	while(resuelve());


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}