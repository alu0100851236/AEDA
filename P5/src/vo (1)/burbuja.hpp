/*
 * burbuja.hpp
 *
 *  Created on: 14 abr. 2018
 *      Author: david
 */

//#ifndef VO_BURBUJA_HPP_
//#define VO_BURBUJA_HPP_

#include "common_types.hpp"

using namespace std;

template <class T>
class Burbuja{
	private:
		int tam_vec;
		int comparaciones;
		T 	*datos;

	public:
		// CONSTRUCTOR
		Burbuja(int tam);

		// DESTRUCTOR
		~Burbuja();

		// METODOS
		void setDato(T dato, int pos);
		void ordenar (bool imprimir);
		void mostrar ();
		int getComparaciones ();
};

template <class T>
Burbuja<T>::Burbuja(int tam):
		tam_vec(tam),
		comparaciones(0),
		datos(new T[tam_vec])
		{}

template <class T>
Burbuja<T>::~Burbuja(){}

template <class T>
void Burbuja<T>::setDato(T dato, int pos)
{
	datos[pos] = dato;
}

template <class T>
void Burbuja<T>::ordenar(bool imprimir)
{
	// ### Se van comparando pares de elementos hasta que el elemento burbuja no se mueva más,
	// ### después se sigue haciendo comparaciones con el siguiente elemento

	int bur, aux;

	for (int i = 1; i < tam_vec; i++){
		for (int j = tam_vec -1; j >= i; j--){
			bur = datos[j-1];
			if (datos[j] < datos[j-1]) {
				bur = datos[j];
				aux = datos[j-1];
				datos[j-1] = datos[j];
				datos[j] = aux;

				// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
				comparaciones++;

				// ## MOSTRAR TRAZA PARA EL MODO DEMOSTRACIÓN
				if (imprimir == true)
				{
					cout << endl << "  # Iteración: " << i << endl;
					cout << "  # Elemento Burbuja, " << bur << " se cambia por " << aux << endl;
					mostrar();
					cout << "  # Pulsar enter para continar" << endl;
					string t;
					getline(cin,t);
				}
				// ## FIN DE TRAZA
			}
		}
	}
}

template <class T>
void Burbuja<T>::mostrar(){
	cout << "  # " ;
	for (int i = 0; i < tam_vec; i++)
	{
		cout << setfill('0') << setw(8) << datos[i] << ", ";
	}
	cout << endl;
}

template <class T>
int Burbuja<T>::getComparaciones()
{
	return comparaciones;
}

//#endif /* VO_BURBUJA_HPP_ */
