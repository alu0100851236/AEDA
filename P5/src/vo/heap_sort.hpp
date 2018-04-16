/*
 * burbuja.hpp
 *
 *  Created on: 14 abr. 2018
 *      Author: david
 */

//#ifndef VO_HEAP_SORT_HPP_
//#define VO_HEAP_SORT_HPP_

#include "common_types.hpp"

using namespace std;

template <class T>
class Heap_Sort{
	private:
		int tam_vec;
		T* datos;

	public:
		// CONSTRUCTOR
		Heap_Sort(int tam);

		// DESTRUCTOR
		~Heap_Sort();

		// METODOS
		void setDato(T dato, int pos);
		void baja (int pos, int n);
		void ordenar (bool imprimir);
		void mostrar ();
};

template <class T>
Heap_Sort<T>::Heap_Sort(int tam):
		tam_vec(tam),
		datos(new T[tam_vec])
		{}

template <class T>
Heap_Sort<T>::~Heap_Sort(){}

template <class T>
void Heap_Sort<T>::setDato(T dato, int pos)
{
	datos[pos] = dato;
}

template <class T>
void Heap_Sort<T>::baja (int pos, int n)
{
	int x = 0, h = 0;
	x = datos[pos];
	while (2 * pos <= n)
	{
		int h1 = 2 * pos;
		int h2 = h1 +1;
//		cout << "## h1: " << h1 << endl;
//		cout << "## h2: " << h2 << endl;
		if (h1 == n)
			h = h1;
		else if (datos[h1] > datos[h2])
		{
//			cout << "## datos[h1] = " << datos[h1] << endl;
//			cout << "## datos[h2] = " << datos[h2] << endl;
			h = h1;
		}
		else
			h = h2;

//		cout << "## datos[h] = " << datos[h] << endl;
//		cout << "## x = " << x << endl;
		if (datos[h] <= x)
		{
//			mostrar();
			break;
		}
		else
		{
//			cout << "## datos[pos] = " << datos[pos] << endl;
//			cout << "## datos[h] = " << datos[h] << endl;
			datos[pos] = datos[h];
			datos[h] = x;
			pos = h;
//			cout << "pos = h = " << pos << endl;
		}
//		mostrar();
	}
}

template <class T>
void Heap_Sort<T>::ordenar(bool imprimir)
{
	for (int i = (tam_vec / 2) - 1; i >= 0; i--)
	{
//		cout << "i = pos = " << i << endl;
		baja(i, tam_vec);

		// ## MOSTRAR TRAZA PARA EL MODO DEMOSTRACIÓN
		if (imprimir == true)
		{
			cout << endl << "  # INSERCIONES: ";
			cout << endl << "  # Iteración: " << i << endl;
			mostrar();
			cout << "  # Pulsar enter para continar" << endl;
			string t;
			getline(cin,t);
		}
		// ## FIN DE TRAZA
	}

	for (int i = tam_vec - 1; i > 0; i--)
	{
//		cout << "i = n = " << i << endl;
		int x = datos[0];
		datos[0] = datos[i];
		datos[i] = x;
		baja(0, i-1);

		if (imprimir == true)
		{
			cout << endl << "  # EXTRACCIONES: ";
			cout << endl << "  # Iteración: " << i << endl;
			mostrar();
			cout << "  # Pulsar enter para continar" << endl;
			string t;
			getline(cin,t);
		}
	}
}

template <class T>
void Heap_Sort<T>::mostrar(){
	cout << "  # " ;
	for (int i = 0; i < tam_vec; i++)
	{
		cout << setfill('0') << setw(8) << datos[i] << ", ";
	}
	cout << endl;
}

//#endif /* VO_HEAP_SORT_HPP_ */
