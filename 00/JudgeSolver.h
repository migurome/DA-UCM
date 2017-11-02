/*!
\file JudgeSolver.h
\class JudgeSolver
\brief Clase abstracta JudgeSolver que servirá para resolver cualquier problema del juez
de forma general. Es decir, contendrá el código común a cualquier solución.

Clase abstracta de la que heredará cada solución de un ejercicio con el correspondiente
código de los patrones para el juez.

Para utilizarlo será necesario crear una clase que herede de ella e implementar la función
"bool resolverCaso()". En la actualizadad esta clase soluciona los problemas del juez que encajan
en los patrones "CENTINELA" o "CANTIDAD". Una vez construida la clase que hereda de esta se debe crear
un objeto de ella y utilizar el método público "ejecutar()" para solucionar dicho ejercicio.

Recordemos que aunque el constructor permite introducir el nombre del fichero de los casos de prueba,
el fichero sólo se utilizará cuando se esté ejecutando de forma local,
ya que al enviarlo al juez este sólo leerá del "std::cin", en vez del fichero.
Esto se debe al uso de las directivas de compilación "#ifndef DOMJUDGE" que nos permite diferenciar en
que modo estamos. Por tanto, no es necesario cambiar el código. Si no se pudiera hacer con directivas
habría que utilizar un booleano y sería conveniente tener dos constructores uno sin nombre de fichero
y otro con el nombre del fichero. El correspondiente sin nombre del fichero debería leer desde "std::cin"
y el otro desde el fichero. De esta forma no sería necesario cambiar el código de la clase virtual.

\author Código de los patrones de patronCENTINELA.cpp y patronCANTIDAD.cpp de Alberto de la Encina Vara
\author Clase: Martín Bárez, modificado por el profesor Alberto de la Encina Vara
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::string;

class JudgeSolver
{
public:

	/*!
	Tipos de patrón que soluciona esta clase
	*/
	enum Tipo { CANTIDAD, CENTINELA };

	/*!
	\brief Constructor
	Constructor. Crea un objeto JudgeSolver con el tipo de patrón que aparezca en "t"
	En este caso si se ejecuta de forma local se utilizará por defecto el archivo "casos.txt".

	\param t Tipo de patrón
	*/
	JudgeSolver(Tipo t) {
		_tipo = t;
		_fichCasos = "casos.txt";
	}
	/* Otra forma de codificar este constructor que  en C++ es más eficiente y
	* que sólo inicializa los campos de la clase:
	JudgeSolver(Tipo t) : _tipo(t), _fichCasos("casos.txt"){};
	// Otra opción usando el otro constructor y de esta forma sólo programar uno:
	JudgeSolver(Tipo t):JudgeSolver(t, "casos.txt") {};
	*/

	/*!
	\brief Constructor

	Constructor. Crea un objeto JudgeSolver con el tipo de patrón y
	el archivo de entrada para los casos de prueba en ejecución local.

	\param t Tipo de patrón
	\param nombFich nombre de archivo de casos de prueba
	*/
	JudgeSolver(Tipo t, string nombFich) {
		_tipo = t;
		_fichCasos = nombFich;
	}

	/*!
	\brief Ejecuta el código del patrón.
	Ejecuta el código del patrón y llama a la función
	resolverCaso que ha debido ser sobreescrita por el
	ejercicio.
	*/
	void ejecutar() {
		run();
	}

	/*!
	\brief Función que solucionará el caso.

	Esta función abstracta será sobreescrita por cada ejercicio.
	Es la encargada de leer un caso de prueba desde el "std::cin" y
	mostrar la solución al caso en el "std::cout".

	En caso de que no pueda realizar la lectura o produzca algún error a lo largo de la resolución
	deberá devolver "true". De esta forma el patrón terminará de ejecutarse.

	\return devuelve el booleno "true" en el caso de que sea el centinela o
	se ha producido algún error en la lectura o en el procesamiento del caso y
	"false" si todo ha ido correctamente.
	*/
	virtual bool resolverCaso() = 0;

private:

	/*!
	\brief Ejecuta el código del patrón
	Ejecuta el código del patrón correspondiente a la variable _tipo y llama a la función
	resolverCaso que ha debido ser sobreescrita por el ejercicio.
	*/
	void run() {
#ifndef DOMJUDGE
		std::ifstream in(_fichCasos);
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

		switch (_tipo) {
		case CANTIDAD: runCantidad(); break;
		case CENTINELA: runCentinela(); break;
		default: runCantidad();
		}

#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
#endif
	}
	/*!
	\brief Ejecuta el código del patrón CANTIDAD
	Ejecuta el código del patrón cantidad y llama a la función
	resolverCaso que ha debido ser sobreescrita por el ejercicio.
	*/
	void runCantidad() {
		unsigned int numCasos;
		bool fallo = false;

		std::cin >> numCasos;
		std::cin.ignore(256, '\n');

		for (unsigned int i = 0; i < numCasos && !fallo; i++) {
			fallo = resolverCaso();
		}
	}

	/*!
	\brief Ejecuta el código del patrón CENTINELA
	Ejecuta el código del patrón centinela y llama a la función
	resolverCaso que ha debido ser sobreescrita por el ejercicio.
	*/
	void runCentinela() {
		bool fin;
		do {
			fin = resolverCaso();
		} while (!fin);
	}

	/*! Tipo actual del patrón */
	Tipo _tipo;
	/*! Nombre del archivo del que leer los casos en caso de estar en modo local*/
	string _fichCasos;
};