/*
 * insercion.hpp
 *
 *  Created on: 14 abr. 2018
 *      Author: david
 */

//#ifndef VO_INSERCION_HPP_
//#define VO_INSERCION_HPP_

#include "common_types.hpp"

using namespace std;

template <class T>
class Insercion{
	private:
		int tam_vec;
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
};

template <class T>
Insercion<T>::Insercion(int tam):
		tam_vec(tam),
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
	int pos, aux;

	for (int i = 0; i < tam_vec; i++){
		pos = i;
		aux = datos[i];
//		cout << "pos, " << pos << " | aux, " << aux << " | datos[pos-1],  " << datos[pos-1] << endl;
		while ((pos > 0) && (aux < datos[pos-1]))
		{
//			cout << "Entro en el while en la iteración i, " << i << " y la posicion pos, " << pos << endl;
			datos[pos] = datos[pos-1];
			pos--;
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
//		cout << "i = " << i << " , datos[" << pos << "] = " << datos[pos] << endl << endl;
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
//	cout << "  # " ;
//	for (int i = 0; i < tam_vec; i++)
//	{
//		if (tam_vec > 10)
//		{
//			cout << "  # " << i + 1 << ".\t";
//			for (int j = 0; j < 10; j++)
//				cout << setfill('0') << setw(8) << datos[i + j] << ", ";
//			cout << endl;
//		}
//		else
//			cout << setfill('0') << setw(8) << datos[i] << ", ";
//	}
//	cout << endl;

}

//#endif /* VO_INSERCION_HPP_ */
