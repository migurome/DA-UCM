/**
* Grupo DA09, Miguel Romero
* Solucion: Los datos se almacenan en dos colas de prioridad, los puntos de nuestro equipo se almacenan
* de mayor a menor y las de los equipos rivales de menor a mayor. En cada iteración, y siempre que los 
* puntos de nuestro equipo sean superiores a los del los rivales se calcula la diferencia de estos y 
* se acumulan en una variable.
* Coste: la inclusion de las dos colas es de O(log n) y la de extracción de datos es también de O (log n)
* por lo que en el caso peor, el cual supone que nuestro equipo siempre ha obtenido mayor número de puntos 
* que todos sus rivales es de 4 O (log n)
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

	struct compare {
		bool operator()(const int& l, const int& r) { return l > r; }
	};


	bool resolverCaso() {


		int nelementos, elemento, diferencia = 0;
		cin >> nelementos;


		priority_queue<int> broncos;
		priority_queue<int, vector<int>, compare> rivales;


		if (nelementos == 0)  // hemos terminado de procesar todos los casos
			return true;

		for (int i = 0; i < nelementos; i++) {
			cin >> elemento;
			rivales.push(elemento);
		}

		for (int i = 0; i < nelementos; i++) {
			cin >> elemento;
			broncos.push(elemento);
		}

	
		while( broncos.top() > rivales.top() && (!broncos.empty()) ){
			diferencia += broncos.top() - rivales.top();
			broncos.pop();
			rivales.pop();
		}

		cout << diferencia << endl;
	
		return false;
	}
};

int main() {

	Ejercicio ej("casos.txt");
	ej.ejecutar();
	return 0;
}