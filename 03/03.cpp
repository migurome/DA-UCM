#include <algorithm>
#include <iostream>
#include <fstream>
#include "TreeMap_AVL.h"

using namespace std;

const int CENTINELA = 0;

bool leerDatos(map<int,int> & arbol, int nvalores, int &k1, int &k2) {
	
	bool finLeer;
	
	if (nvalores == 0)
		return true;

	int dato;
	
	for (int i = 0; i < nvalores; i++) {
		cin >> dato;
		arbol.insert(dato);
	}


	cin >> k1;
	cin >> k2;

	return false;
}

void procesarCaso(const map<int, int> & arbol, int k1, int k2) {
			
	
	map<int, int>::const_iterator it = arbol.begin();

	while (it != arbol.end() && (*it).clave < k1)
		++it;

	while (it != arbol.end() && (*it).clave <= k2) { // imprimir elementos entre k1 y k2 y cuando sean mayores que k2 se corta
		cout << (*it).clave;
		++it;
		if (it != arbol.end() && (*it).clave <= k2) // imprimir espacio en todos menos en el ultimo
			cout << " ";
	}

	cout << endl;
}

bool analizarCaso() {

	// ajustes para que cin extraiga directamente de un fichero

	int valores, k1, k2;
	map<int, int> arbol;
	bool finLectura = false;

	cin >> valores;

	finLectura = leerDatos(arbol, valores, k1, k2);

	if (!finLectura) {

		procesarCaso(arbol, k1, k2);
		//mostrarResultadoCaso(sol);
	};

	// para dejar todo como estaba al principio

	

	return finLectura;
}

int main(int argc, char** args) {

	bool fin;

	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	do {
		fin = analizarCaso();
	} while (!fin);

	
	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}