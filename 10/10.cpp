/**
* Grupo DA09, Miguel Romero
*/

#include <iostream>
#include <fstream>
#include "Grafo.h"

using namespace std;

enum tColores{azul, rojo, sin_color};

bool resuelveCaso() {

	int nvertices, naristas, elem_1, elem_2;
	

	cin >> nvertices >> naristas;

	if (cin.fail())
		return false;
	Grafo grafo(nvertices);

	

	for (int i = 0; i < naristas; i++) {
		cin >> elem_1 >> elem_2;
		grafo.ponArista(elem_1, elem_2);
	}

	vector<tColores> coloreado(grafo.V(), sin_color);

	grafo.print();

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while(resuelveCaso());
	
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}