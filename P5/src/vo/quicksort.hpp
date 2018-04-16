/*
 * burbuja.hpp
 *
 *  Created on: 14 abr. 2018
 *      Author: david
 */

//#ifndef VO_QuickSort_HPP_
//#define VO_QuickSort_HPP_

#include "common_types.hpp"

using namespace std;

template <class T>
class QuickSort{
	private:
		int tam_vec;
		T* datos;

	public:
		// CONSTRUCTOR
		QuickSort(int tam);

		// DESTRUCTOR
		~QuickSort();

		// METODOS
		void setDato(T dato, int pos);
		void baja (int pos, int n);
		void ordenar (int i, int f, bool imprimir);
		void mostrar ();
};

template <class T>
QuickSort<T>::QuickSort(int tam):
		tam_vec(tam),
		datos(new T[tam_vec])
		{}

template <class T>
QuickSort<T>::~QuickSort(){}

template <class T>
void QuickSort<T>::setDato(T dato, int pos)
{
	datos[pos] = dato;
}

template <class T>
void QuickSort<T>::ordenar(int i, int f, bool imprimir)
{
	int ini = i, fin = f;
	int piv = datos[(ini + fin) / 2];
//	cout << "ini: " << ini << " | fin: " << fin << " | piv: " << piv << endl;
	while (ini <= fin)
	{
		while (datos[ini] < piv)
			ini++;

		while (datos[fin] > piv)
			fin--;

		if (ini <= fin)
		{
			int x = datos[ini];
			datos[ini] = datos[fin];
			datos[fin] = x;
			ini++;
			fin--;

			// ## MOSTRAR TRAZA PARA EL MODO DEMOSTRACIÓN
			if (imprimir == true)
			{
				cout << endl << "  # El pivote es: " << piv << endl;
				mostrar();
				cout << "  # Pulsar enter para continar" << endl;
				string t;
				getline(cin,t);
			}
		}
	}

	if (i < fin)
		ordenar(i, fin, imprimir);

	if (ini < f)
		ordenar(ini, f, imprimir);
}

template <class T>
void QuickSort<T>::mostrar(){
	cout << "  # " ;
	for (int i = 0; i < tam_vec; i++)
	{
		cout << setfill('0') << setw(8) << datos[i] << ", ";
	}
	cout << endl;
}

//#endif /* VO_QuickSort_HPP_ */
