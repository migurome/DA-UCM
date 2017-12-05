/*
* Grupo DA09, Miguel Romero
* Solucion: Los casos de entrada se recogen en una cola de prioridad ordenada por precios, de mayor a menor
* Siempre que haya elementos en la cola se van extrayendo realizando la suma parcial del tercero de ellos y
* y acumulando su valor en la variable ahorro.
* Coste: el coste de incluir los elementos en la cola es de log n  y el de eliminar un elemento de esta también es 
* de log n por lo tanto el coste totál será de 2 (log n)
*/

#include <iostream>
#include <fstream>
#include <queue>
#include "JudgeSolver.h"

using namespace std;

class Ejercicio : public JudgeSolver
{
public:

	/**
	* @brief Constructor
	* Constructor. Crea un objeto encargado de solucionar el problema de calcular el maximo tamanio de una componente conexa
	* Este problema realiza la lectura con el patrón cantidad.
	* Cuando se ejecuta en local desde el fichero "nombreFich".
	*/

	Ejercicio() : JudgeSolver(JudgeSolver::CENTINELA) {}

	/**
	* @brief Constructor
	* Constructor. Crea un objeto encargado de solucionar el problema de calcular el maximo tamanio de una componente conexa
	* Este problema realiza la lectura con el patrón cantidad.
	* Cuando se ejecuta en local desde el fichero "nombreFich".
	* @param nombFich nombre de archivo de casos de prueba
	*/

	Ejercicio(string nombreFich) : JudgeSolver(JudgeSolver::CENTINELA, nombreFich) {}

	/**
	* @brief Metodo encargado de averiguar el numero de componentes conexas
	* Se realiza la lectura de los datos desde "std::cin" y se muestra el resultado a trav�s del "std::cout".
	* @return false ya que no se controla si ha habido un error o no
	*/

	bool resolverCaso() {


		int nlibros, elemento, ahorro = 0;
		cin >> nlibros;


		priority_queue<int> libros;

		if (cin.fail())  // hemos terminado de procesar todos los casos
			return true;

		for (int i = 0; i < nlibros; i++) {
			cin >> elemento;
			libros.push(elemento);
		}

		while (!libros.empty()) {

			libros.pop();
			
			if (!libros.empty()){
				libros.pop();
				if (!libros.empty()) {
					ahorro += libros.top();
					libros.pop();
				}
			}


		}

		cout << ahorro << endl;

		return false;
	}
};

int main() {

	Ejercicio ej("casos.txt");
	ej.ejecutar();
	return 0;
}