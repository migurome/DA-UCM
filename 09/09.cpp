/**
* Grupo DA09, Miguel Romero
*/

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"

using namespace std;


void resuelveCaso() {

	int tam_grafo, ncasos, elem_1, elem_2, maximo = 1;
	cin >> tam_grafo >> ncasos;
	ConjuntosDisjuntos conjunto(tam_grafo + 1);

	for (int i = 0; i < ncasos; i++) {
		
		cin >> elem_1 >> elem_2;
		conjunto.unir(elem_1, elem_2);

		if (conjunto.size(elem_1) > maximo)
			maximo = conjunto.size(elem_1);
	}

	cout << maximo << endl;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int ncasos;
	cin >> ncasos;
	for (int i = 0; i < ncasos; i++){
		resuelveCaso();
	}
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}