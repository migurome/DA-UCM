/*
* Grupo DA09, Miguel Romero
* Solución: una función recursiva que recorre el árbol comprobando que está ordenadoy que está balanceado
*
*  */

#include <algorithm>
#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

/**
* @brief Lee un árbol binario de la entrada estándar
*/

bintree<int> leerArbol() {

	int raiz;
	cin >> raiz;

	if (raiz == -1) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos

		auto iz = leerArbol();
		auto dr = leerArbol();
		return { iz, raiz, dr };
	}
}


/**
* @brief Función principal. Si la raiz es vacía el arbol es AVL. En otro caso,
* comprobamos que la raiz está entre el valor mínimo y máximo y si es así se comprueba que
* comprobamos que la diferencia de alturas de las dos ramas cumple la condición para ser balanceado.
* En caso de que alguna de estas condiciones no se cumpla, el árbol no es AVL.
* Complejidad O(n) siendo n el número de nodos.
* @param arbol que se quiere analizar
* @param altura altura maxima de las ramas del arbol
* @param min valor mínimo entre  el que se tiene que encontrar la raiz
* @param max valor maximo entre  el que se tiene que encontrar la raiz
* @return determina si el arbol es AVL
*/


bool resuelve(bintree<int> const &arbol, int &altura, int min, int max) {

	if (arbol.empty()) {
		return true;
	}
	else {
		if (arbol.root() < max && arbol.root() > min) {
			int auxI, auxD;
			auxI = altura;
			auxD = altura;

			if (!resuelve(arbol.left(), auxI, min, arbol.root()))
				return false;
			if (!resuelve(arbol.right(), auxD, arbol.root(), max))
				return false;

			if (abs(auxI - auxD) <= 1) {
				altura = 1 + std::max(auxI, auxD);
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
}

/**
* @brief Resuelve un caso de prueba
*/

void resuelveCaso() {

	auto arbol = leerArbol();

	int a = 0;
	if (resuelve(arbol, a, INT16_MIN, INT16_MAX))
		cout << "SI" << endl;
	else
		cout << "NO" << endl;

}

int main(int argc, char* argv[]) {

#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	system("pause");

	return 0;
}