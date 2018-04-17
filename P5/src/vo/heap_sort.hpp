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
class Heap_Sort{
	private:
		int tam_vec;
		int comparaciones;
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
		int getComparaciones();
};

template <class T>
Heap_Sort<T>::Heap_Sort(int tam):
		tam_vec(tam),
		comparaciones(0),
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
		if (h1 == n)
		{
			h = h1;

			// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
			comparaciones++;
		}
		else if (datos[h1] > datos[h2])
		{
			h = h1;

			// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
			comparaciones++;
		}
		else
		{
			h = h2;

			// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
			comparaciones++;
		}

		if (datos[h] <= x)
		{
			// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
			comparaciones++;

			break;
		}
		else
		{
			datos[pos] = datos[h];
			datos[h] = x;
			pos = h;

			// ## CONTADOR DE LAS COMPARACIONES PARA LAS ESTADÍSTICAS
			comparaciones++;
		}
	}
}

template <class T>
void Heap_Sort<T>::ordenar(bool imprimir)
{
	for (int i = (tam_vec / 2) - 1; i >= 0; i--)
	{
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

template <class T>
int Heap_Sort<T>::getComparaciones()
{
	return comparaciones;
}
