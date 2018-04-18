//============================================================================
// Author      	: David Dorta Acosta
// email       	: alu0100851236@ull.edu.es
// Asignatura  	: Algoritmos y Estructura de Datos Avanzadas
// Curso			: 2017-2018
// Práctica 5	: Implementación de métodos de ordenación
//============================================================================

#include "common_types.hpp"
//#include "dni.hpp"
using namespace std;

template <class T>
class Insercion{
	private:
		int tam_vec;
		int comparaciones;
		T 	*datos;

	public:
		// CONSTRUCTOR
		Insercion(int tam);

		// DESTRUCTOR
		~Insercion();

		// METODOS
		void setDato(T dato, int pos);
		void ordenar (bool imprimir);
		void mostrar ();
		int getComparaciones ();
};

template <class T>
Insercion<T>::Insercion(int tam):
		tam_vec(tam),
		comparaciones(0),
		datos(new T[tam_vec])
		{}

template <class T>
Insercion<T>::~Insercion(){}

template <class T>
void Insercion<T>::setDato(T dato, int pos)
{
	datos[pos] = dato;
}

template <class T>
void Insercion<T>::ordenar(bool imprimir)
{
	int pos;

	for (int i = 0; i < tam_vec; i++){
		pos = i;
		T aux = datos[i];
		while ((pos > 0) && (aux < datos[pos-1]))
		{
			datos[pos] = datos[pos-1];
			pos--;

			// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
			comparaciones++;
		}
		datos[pos] = aux;

		// ## MOSTRAR TRAZA PARA EL MODO DEMOSTRACIÓN
		if (imprimir == true)
		{
			cout << endl << "  # Iteración: " << i << endl;
			mostrar();
			cout << "  # Pulsar enter para continar" << endl;
			string t;
			getline(cin,t);
		}
		// ## FIN DE TRAZA
	}
}

template <class T>
void Insercion<T>::mostrar(){
	cout << "  # " ;
	for (int i = 0; i < tam_vec; i++)
	{
		cout << setfill('0') << setw(8) << datos[i] << ", ";
	}
	cout << endl;
}

template <class T>
int Insercion<T>::getComparaciones()
{
	return comparaciones;
}
