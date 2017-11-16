#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "Worker.h"
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

		int tam_grafo, nelementos;
		cin >> tam_grafo >> nelementos;

		if (cin.fail())  // hemos terminado de procesar todos los casos
			return true;

		int v, w, c;

		GrafoValorado<int> g(tam_grafo);
		for (int i = 0; i < nelementos; ++i) {
			std::cin >> v;
			std::cin >> w;
			std::cin >> c;
			Arista<int> a(v - 1, w - 1, c);
			g.ponArista(a);
		}
	
		Worker barro(g);

		if (barro.getCoste() >= 0)
			cout << barro.getCoste() << endl;
		else
			cout << "Imposible" << endl;
		
		return false;
	}
};

int main() {

	Ejercicio ej("casos.txt");
	ej.ejecutar();
	return 0;
}