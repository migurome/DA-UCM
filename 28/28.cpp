/*
* Grupo DA09, Miguel Romero
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "JudgeSolver.h"
#include "Matriz.h"
#include <algorithm>

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

		int valor, botella ,cofres, p, o;
		
		cin >> botella >> cofres;

		if (cin.fail())
			return true;

		vector<int> profundidad(cofres + 1);
		vector<int> oro(cofres + 1);

		for (int i = 1; i <= cofres; i++) {
			cin >> p >> o;
			profundidad[i] = 3 * p;
			oro[i] = o;
		}

		Matriz<int> tesoros(cofres + 1, botella + 1, 0);
		//Rellenar la matriz
		for (int i = 1; i <= cofres; ++i) {
			for (int j = 1; j <= botella; ++j) {
				if (profundidad[i] > j)
					tesoros[i][j] = tesoros[i - 1][j];
				else
					tesoros[i][j] = max(tesoros[i - 1][j], tesoros[i - 1][j - profundidad[i]] + oro[i]);
			}
		}

		valor = tesoros[cofres][botella];
		cout << valor << endl;

		//Cálculo de los cofres que nos llevamos
		int resto = botella, cont = 0;
		vector<bool> cogidos(cofres + 1);
		for (int i = cofres; i >= 1; --i) {
			if (tesoros[i][resto] == tesoros[i - 1][resto]) {
				// No cogemos el cofre i
				cogidos[i] = false;
			}
			else { 
				//Sí cogemos el cofre i
				cogidos[i] = true;
				cont++;
				resto = resto - profundidad[i];
			}
		}
		cout << cont << endl;
		for (int i = 1; i <= cofres; i++)
			if (cogidos[i])
				cout << profundidad[i] / 3 << " " << oro[i] << endl;

		cout << "----" << endl;

		

		return false;
	}
};

int main() {

	Ejercicio ej("casos.txt");
	ej.ejecutar();
	return 0;
}