// Grupo DA09, Miguel Romero Martínez

#include <algorithm>
#include <iostream>
#include <fstream>
#include "bintree_eda.h"

/**
 * Lee un árbol binario de la entrada estándar
 */

template <typename T>
bintree<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;

	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos

		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return { iz, raiz, dr };
	}
}

/**
 * Función secundaria.
 * Complejidad O(n) siendo n el número de nodos.
 * @param arbol que se quiere analizar
 * @return  altura maxima de las ramas del arbol
 */

unsigned int altura(bintree<char> const& arbol) {
	if (arbol.empty())
		return 0;
	else
		return 1 + std::max(altura(arbol.left()), altura(arbol.right()));
}

/**
 * Función principal. Si la raiz es vacía no hay nada que hacer. En otro caso,
 * comprobamos que la raiz está entre el valor mínimo y máximo (inicializados como el máximo  y mínimo 
 * valor posible de una variable int), y si es así comprobamos que la diferencia de alturas de las dos ramas
 * cumple la condición para ser balanceado. En caso de que alguna de estas condiciones no se cumpla, 
 * sabemos que el árbol no es AVL.  Complejidad O(n) siendo n el número de nodos.
 * @param arbol que se quiere analizar
 * @return si el arbol es equilibrado o no
 */

bool equilibrado(bintree<char> const& arbol) {
	 
	int altura_D, altura_I;


	if (arbol.empty())
		return true;

	if (equilibrado(arbol.left()) && equilibrado(arbol.right())) {

		altura_I = altura(arbol.left());
		altura_D = altura(arbol.right());

		return std::abs(altura_I - altura_D) <= 1;

	}
	else
		return false;	
}

/**
 * Resuelve un caso de prueba
 */

void resuelveCaso() {
		
	auto arbol = leerArbol('.');

	if (equilibrado(arbol))
		std::cout << "SI" << "\n";
	else
		std::cout << "NO" << "\n";

}

int main(int argc, char* argv[]) {

	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	system("pause");

	return 0;
}