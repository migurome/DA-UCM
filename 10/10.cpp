/**
* Grupo DA09, Miguel Romero
*/

#include <iostream>
#include <fstream>
#include "JudgeSolver.h"
#include "Grafo.h"

using namespace std;

typedef enum {naranja,azul,no_coloreado} color;
bool esNaranjaYBipartito(const Grafo &grafo, int v, vector<color>& coloreado);
bool esAzulYBipartito(const Grafo &grafo, int v, vector<color>& coloreado); 
bool esBipartito(const Grafo &grafo);

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

		int tam_grafo, nelementos, elem_1, elem_2, maximo = 1;
		cin >> tam_grafo >> nelementos;

		if (cin.fail())  // hemos terminado de procesar todos los casos
			return true;

		Grafo grafo(tam_grafo + 1);

		for (int i = 0; i < nelementos; i++){
			cin >> elem_1 >> elem_2;
			grafo.ponArista(elem_1, elem_2);
		}

		if (esBipartito(grafo))
			cout << "SI" << endl;
		else
			cout << "NO" << endl;

		return false;
	}
};

/**
* Prueba de ejecución de la solución de mi ejercicio.
* Se crea un objeto ejercicio con el tipo adecuado y se ejecuta.
*/

bool esNaranjaYBipartito(const Grafo &grafo, int v, vector<color> &coloreado) {

	coloreado[v] = naranja;

	for (int w : grafo.adj(v)) {
		if (coloreado[w] != azul) {
			if (coloreado[w] == naranja || !esAzulYBipartito(grafo, w, coloreado))
				return false;
		}
	}

	return true;
}

bool esAzulYBipartito(const Grafo &grafo, int v, vector<color> &coloreado) {

	coloreado[v] = azul;

	for (int w : grafo.adj(v)) {
		if (coloreado[w] != naranja) {
			if (coloreado[w] == azul || !esNaranjaYBipartito(grafo, w, coloreado) )
				return false;
		}
	}

	return true;
}

bool esBipartito(const Grafo &grafo) {

	vector<color> coloreado(grafo.V(), no_coloreado);
	bool bipartito = true;
	// colorearemos el grafo en dos colores: azul y naranja
	for (int i = 0; i < grafo.V() && bipartito; i++) {
		if (coloreado[i] == no_coloreado)
			bipartito = esAzulYBipartito(grafo, i, coloreado);
	}

	return bipartito;
}

int main() {

	Ejercicio ej("casos.txt");
	ej.ejecutar();
	return 0;
}