
#include <algorithm>
#include <iostream>
#include <fstream>
#include "bintree_eda.h"
// lee un árbol binario de la entrada estándar

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

unsigned int altura(bintree<char> const& arbol) {
	if (arbol.empty())
		return 0;
	else
		return 1 + std::max(altura(arbol.left()), altura(arbol.right()));
}

bool equilibrado(bintree<char> const& arbol) {
	 
	int altura_D, altura_I;


	if (arbol.empty())
		return true;

	if (equilibrado(arbol.left()) && equilibrado(arbol.right())) {

		altura_I = altura(arbol.left());
		altura_D = altura(arbol.right());

		if (std::abs(altura_I - altura_D) <= 1)
			return true;
		else
			return false;
	}
	else
		return false;
	
	
}

// resuelve un caso de prueba
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
	std::cin.ignore(256, '\n');

	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	system("pause");

	return 0;
}