//============================================================================
// Author      	: David Dorta Acosta
// email       	: alu0100851236@ull.edu.es
// Asignatura  	: Algoritmos y Estructura de Datos Avanzadas
// Curso			: 2017-2018
// Práctica 5	: Implementación de métodos de ordenación
//============================================================================

#include "common_types.hpp"

using namespace std;

template <class T>
class QuickSort{
	private:
		int tam_vec;
		int comparaciones;
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
		int getComparaciones();
};

template <class T>
QuickSort<T>::QuickSort(int tam):
		tam_vec(tam),
		comparaciones(0),
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
	while (ini <= fin)
	{
		while (datos[ini] < piv)
		{
			ini++;

			// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
			comparaciones++;
		}

		while (datos[fin] > piv)
		{
			fin--;

			// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
			comparaciones++;
		}

		if (ini <= fin)
		{
			int x = datos[ini];
			datos[ini] = datos[fin];
			datos[fin] = x;
			ini++;
			fin--;

			// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
			comparaciones++;

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
	{
		ordenar(i, fin, imprimir);

		// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
		comparaciones++;
	}

	if (ini < f)
	{
		ordenar(ini, f, imprimir);

		// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
		comparaciones++;
	}
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

template <class T>
int QuickSort<T>::getComparaciones()
{
	return comparaciones;
}
