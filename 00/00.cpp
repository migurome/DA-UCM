/*!
\file Ej01.cpp
\class Ejercicio
\brief Clase que resuelve el problema inicial.

Clase de ejemplo de uso de la clase virtual JudgeSolver para resolver el ejercicio que calculaba la
altura de un �rbol.
Esta clase hereda el comportamiento de la clase JudgeSolver y codifica la funci�n "bool resolverCaso()".

El ejercicio del calculo de la altura de un �rbol utiliza el patr�n cantidad.

\author Mart�n B�rez
*/

#include <algorithm>
#include <iostream>
#include "JudgeSolver.h"
#include "bintree_eda.h"


class Ejercicio : public JudgeSolver
{
public:

	/*!
	\brief Constructor
	Constructor. Crea un objeto encargado de solucionar el problema del ejercicio de la altura de un �rbol.
	Este problema realiza la lectura con el patr�n cantidad.
	En este caso este constructor utiliza por defecto el archivo "casos.txt".
	*/

	Ejercicio() : JudgeSolver(JudgeSolver::CANTIDAD) {}

	/*!
	\brief Constructor
	Constructor. Crea un objeto encargado de solucionar el problema del ejercicio de la altura de un �rbol.
	Este problema realiza la lectura con el patr�n cantidad.
	Cuando se ejecuta en local desde el fichero "nombreFich".

	\param nombFich nombre de archivo de casos de prueba
	*/
	Ejercicio(string nombreFich) : JudgeSolver(JudgeSolver::CANTIDAD, nombreFich) {}

	/*!
	\brief M�todo encargado de resolver el caso de la altura de un �rbol.
	Se realiza la lectura de los datos desde "std::cin" y se muestra el resultado a trav�s del "std::cout".

	\return false ya que no se controla si ha habido un error o no
	*/
	bool resolverCaso() {
		auto arbol = leerArbol('.');
		int sol = altura(arbol);
		std::cout << sol << "\n";
		return false;
}

private:

	// lee un �rbol binario de la entrada est�ndar en el formato indicado en el ejercicio.
	// Este m�todo deber�a encontrarse en la clase bintree_eda
	// vacio representa el valor que indica que est� vac�o.
	template < typename T> bintree<T> leerArbol(T vacio)
	{
		T raiz;
		std::cin >> raiz;
		if (raiz == vacio) { // es un �rbol vac�o
			return {};
		}
		else { // leer recursivamente los hijos
			auto iz = leerArbol(vacio);
			auto dr = leerArbol(vacio);
			return { iz, raiz, dr };
		}
	}
	// dado un �rbol binario, calcula su altura
	// lineal en el n�mero N de nodos del �rbol, O(N)
	unsigned int altura(bintree<char> const& arbol)
	{
		if (arbol.empty())
			return 0;
		else
			return 1 + std::max(altura(arbol.left()), altura(arbol.right()));
	}

};

/*!
Prueba de ejecuci�n de la soluci�n de mi ejercicio.
Se crea un objeto ejercicio con el tipo adecuado y se ejecuta.
*/
int main() {
	//Para leer del fichero por defecto "casos.txt" se puede utilizar el constructor por defecto Ejercicio ej();
	Ejercicio ej(CANTIDAD,"casos.txt");
	ej.ejecutar();
	return 0;
}