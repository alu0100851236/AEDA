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
		T 	*datos;

	public:
		// CONSTRUCTOR
		Burbuja(int tam);

		// DESTRUCTOR
		~Burbuja();

		// METODOS
		void setDato(T dato, int pos);
		void ordenar ();
		void mostrar ();
};

template <class T>
Burbuja<T>::Burbuja(int tam):
		tam_vec(tam),
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
void Burbuja<T>::ordenar()
{
	// ### Se van comparando pares de elementos hasta que el elemento burbuja no se mueva más,
	// ### después se sigue haciendo comparaciones con el siguiente elemento

	int bur, aux;
	cout << "Impresión del vector original" << endl;
	for (int i = 0; i < tam_vec; i++)
		{
			cout << datos[i] << ", ";
		}
	cout << endl;

	for (int i = 1; i < tam_vec; i++){
		for (int j = tam_vec -1; j >= i; j--){
			bur = datos[j-1];
			if (datos[j] < datos[j-1]) {
				bur = datos[j];
				aux = datos[j-1];
				datos[j-1] = datos[j];
				datos[j] = aux;
			}
			cout << "Vector en el paso i = " << i << " | j = " << j << " | Elemento Burbuja, " << bur << endl;
			for (int t = 0; t < tam_vec; t++)
					{
						cout << datos[t] << ", ";
					}
				cout << endl;
		}
	}
}

template <class T>
void Burbuja<T>::mostrar(){
	cout << "Impresion del vector ordenado" << endl;

	for (int i = 0; i < tam_vec; i++)
	{
		cout << setfill('0') << setw(8) << datos[i] << ", ";
	}
	cout << endl << endl;
}

//#endif /* VO_BURBUJA_HPP_ */
