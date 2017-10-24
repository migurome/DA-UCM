/**
* Grupo DA09, Miguel Romero
*/

#include <iostream>
#include <fstream>
#include "Grafo.h"
#include "ConjuntosDisjuntos.h"

using namespace std;


bool resuelveCaso() {

	int tam_grafo, naristas, elem_1, elem_2;
	
	

	cin >> tam_grafo >> naristas;

	if (cin.fail())
		return false;

	ConjuntosDisjuntos conjunto(tam_grafo);

	for (int i = 0; i < naristas; i++) {
		cin >> elem_1 >> elem_2;
		conjunto.unir(elem_1, elem_2);
	}

	if (conjunto.count() > 1 || naristas %2 == 0)
		cout << "NO" << endl;
	else
		cout << "SI" << endl;

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