/**
* Grupo DA09, Miguel Romero
*/

#include <iostream>
#include <fstream>
#include <string>
#include "JudgeSolver.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

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
		
		return false;
	}
};

/*!
Prueba de ejecuci�n de la soluci�n de mi ejercicio.
Se crea un objeto ejercicio con el tipo adecuado y se ejecuta.
*/
int main() {
	//Para leer del fichero por defecto "casos.txt" se puede utilizar el constructor por defecto Ejercicio ej();
	Ejercicio ej("casos.txt");
	ej.ejecutar();
	return 0;
}