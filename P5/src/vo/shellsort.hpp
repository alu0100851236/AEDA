/*
 * burbuja.hpp
 *
 *  Created on: 14 abr. 2018
 *      Author: david
 */

//#ifndef VO_ShellSort_HPP_
//#define VO_ShellSort_HPP_

#include "common_types.hpp"

using namespace std;

template <class T>
class ShellSort{
	private:
		int tam_vec;
		T* datos;

	public:
		// CONSTRUCTOR
		ShellSort(int tam);

		// DESTRUCTOR
		~ShellSort();

		// METODOS
		void setDato(T dato, int pos);
		void baja (int pos, int n);
		void ordenar (double alfa);
		void deltasort(int delta);
		void mostrar ();
};

template <class T>
ShellSort<T>::ShellSort(int tam):
		tam_vec(tam),
		datos(new T[tam_vec])
		{}

template <class T>
ShellSort<T>::~ShellSort(){}

template <class T>
void ShellSort<T>::setDato(T dato, int pos)
{
	datos[pos] = dato;
}

template <class T>
void ShellSort<T>::ordenar(double alfa)
{
	int delta = alfa * tam_vec;

	while (delta >= 1)
	{
//		cout << "@ Ordenar, delta, " << delta << endl << endl;
		deltasort(delta);
//		cout << "@ Despues de deltasort, delta, " << delta << endl << endl;
		delta = delta / 2;

	}
}

template <class T>
void ShellSort<T>::deltasort(int delta)
{
	mostrar();
	for (int i = delta; i < tam_vec; i++)
	{
		int x = datos[i];
		int j = i;
//		cout << "datos[i]: " << datos[i] << " | datos[j - delta]: " << datos[j - delta] << " | en delta, " << delta << " | con j, " << j << endl;
		while ((j >= delta) && (x < datos[j - delta]))
		{
//			cout << "## ENTRO EN EL WHILE ##" << endl;
//			cout << "## - datos[j]: " << datos[j] << endl;
//			cout << "## - datos[i]: " << datos[i] << endl;
			datos[j] = datos[j - delta];
//			cout << "## - datos[j - delta]: " << datos[j - delta] << " | en [j - delta], " << j - delta << endl;
			j = j - delta;
//			cout << "## - j = " << j  << endl << endl;
		}

		datos[j] = x;
	}
}

template <class T>
void ShellSort<T>::mostrar(){
//	cout << "Impresion del vector ordenado" << endl;

	for (int i = 0; i < tam_vec; i++)
	{
		if (tam_vec > 10)
		{
			cout << i + 1 << ".\t";
			for (int j = 1; j <= 10; j++)
				cout << setfill('0') << setw(8) << datos[i] << ", ";
			cout << endl;
		}
		else
			cout << setfill('0') << setw(8) << datos[i] << ", ";
	}
	cout << endl << endl;
}

//#endif /* VO_ShellSort_HPP_ */
