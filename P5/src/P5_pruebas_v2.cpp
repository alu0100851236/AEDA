//============================================================================
// Name        : P5_pruebas_v2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "vo/common_types.hpp"
#include "vo/dni.hpp"
#include "vo/insercion.hpp"
#include "vo/burbuja.hpp"
#include "vo/heap_sort.hpp"

using namespace std;

int main() {
	int opcion = 0, tam_vec = 0;

	cout << "*" << setfill('-') << setw(57) << "*" << endl;
	cout << "| PRACTICA 5: IMPLEMENTACIÓN DE MÉTODOS DE ORDENACIÓN" << setfill(' ') << setw(5) << "|" << endl;
	cout << "| Autor: David Dorta Acosta" << setfill(' ') << setw (31) << "|" << endl;
	cout << "| email: alu0100851236@ull.edu.es" << setfill(' ') << setw(25) << "|" << endl;
	cout << "| fecha entrega: 18 abril 2018" << setfill(' ') << setw(28) << "|" << endl;
	cout << "*" << setfill('-') << setw(57) << "*" << endl << endl;

	cout << "Tamaño para generar vector: ";
    cin >> tam_vec;
    cout << endl;

    // # CREACIÓN DE LOS VECTORES SEGÚN LA MÉTODO DE ORDENACIÓN

    Insercion<DNI> vector_insercion(tam_vec);
    Burbuja<DNI> vector_burbuja(tam_vec);
    Heap_Sort<DNI> vector_heap_sort(tam_vec);

	do{
		cout << "Métodos de ordenacion:" << endl;
		cout << "-----------------------" << endl;
		cout << "1. Inserción" << endl;
		cout << "2. Burbuja" << endl;
		cout << "3. Heap Sort" << endl;
		cout << "0. Salir" << endl;
		cin >> opcion;

		switch(opcion){

			case 1:
				{
//					cout << "Entro en el case" << endl;
					for(int i = 0 ; i < tam_vec ; i++)
						{
							DNI tmp_dni;
							vector_insercion.setDato(tmp_dni.getDni(), i);
						}

					vector_insercion.ordenar();
					vector_insercion.mostrar();
					break;
				}

			case 2:
				{
					for(int i = 0 ; i < tam_vec ; i++)
						{
							DNI tmp_dni;
							vector_burbuja.setDato(tmp_dni.getDni(), i);
						}

					vector_burbuja.ordenar();
					vector_burbuja.mostrar();
					break;
				}

			case 3:
				{
					for(int i = 0 ; i < tam_vec ; i++)
						{
							DNI tmp_dni;
							vector_heap_sort.setDato(tmp_dni.getDni(), i);
						}

					cout << "Vector original: " << endl;
					vector_heap_sort.mostrar();
					vector_heap_sort.ordenar();

					cout << "Vector ordenado: " << endl;
					vector_heap_sort.mostrar();
					break;
				}
		}
	} while (opcion != 0);



	return 0;
}
