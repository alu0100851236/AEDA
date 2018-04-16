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
#include "vo/quicksort.hpp"
#include "vo/shellsort.hpp"

using namespace std;

int main() {
	int opcion = 0, tam_vec = 0, modo = 0;
	double alfa = 0.0;

	cout << "*" << setfill('-') << setw(57) << "*" << endl;
	cout << "| PRACTICA 5: IMPLEMENTACIÓN DE MÉTODOS DE ORDENACIÓN" << setfill(' ') << setw(5) << "|" << endl;
	cout << "| Autor: David Dorta Acosta" << setfill(' ') << setw (31) << "|" << endl;
	cout << "| email: alu0100851236@ull.edu.es" << setfill(' ') << setw(25) << "|" << endl;
	cout << "| fecha entrega: 18 abril 2018" << setfill(' ') << setw(28) << "|" << endl;
	cout << "*" << setfill('-') << setw(57) << "*" << endl << endl;

	cout << "Tamaño para generar vector: ";
    cin >> tam_vec;

    // # CREACIÓN DE LOS VECTORES SEGÚN LA MÉTODO DE ORDENACIÓN

    Insercion<DNI> vector_insercion(tam_vec);
    Burbuja<DNI> vector_burbuja(tam_vec);
    Heap_Sort<DNI> vector_heap_sort(tam_vec);
    QuickSort<DNI> vector_quicksort(tam_vec);
    ShellSort<DNI> vector_shellsort(tam_vec);

    do{
    		cout << endl << "*" << setfill('-') << setw(26) << "*" << endl;
    		cout << "|  MODOS DE UTILIZACIÓN" << setfill(' ') << setw (4) << "|" << endl;
    		cout << "| ----------------------- |" << endl;
    		cout << "|  1. Modo Demostración" << setfill(' ') << setw (4) << "|" << endl;
    		cout << "|  2. Modo Estadística" << setfill(' ') << setw (5) << "|" << endl;
    		cout << "|  0. Salir" << setfill(' ') << setw (16) << "|" << endl;
    		cout << "*" << setfill('-') << setw(26) << "*" << endl;

    		cout << "Seleccione un modo de utilización: ";
    		cin >> modo;

    			switch(modo){

    				case 1:
    				{
    					do{
    						cout << endl << "  *" << setfill('=') << setw(24) << "*" << endl;
    						cout << "  ||  MODO DEMOSTRACIÓN" << setfill(' ') << setw(4) << "||" << endl;
    						cout << "  || ------------------- ||" << endl;
    						cout << "  ||  1. Inserción" << setfill(' ') << setw(9) << "||" << endl;
    						cout << "  ||  2. Burbuja" << setfill(' ') << setw(11) << "||" << endl;
    						cout << "  ||  3. Heap Sort" << setfill(' ') << setw(9) << "||" << endl;
    						cout << "  ||  4. QuickSort" << setfill(' ') << setw(9) << "||" << endl;
    						cout << "  ||  5. ShellSort" << setfill(' ') << setw(9) << "||" << endl;
    						cout << "  ||  0. Salir" << setfill(' ') << setw(13) << "||" << endl;
    						cout << "  *" << setfill('=') << setw(24) << "*" << endl;

    						cout << "  Seleccione una opción: ";
    						cin >> opcion;

    						switch(opcion){
    							case 1:
    								{
    									// ## LLENO EL VECTOR CON EL TDATO DNI
    									for(int i = 0 ; i < tam_vec ; i++)
    										{
    											DNI tmp_dni;
    											vector_insercion.setDato(tmp_dni.getDni(), i);
    										}
    									cout << endl << "  |" << setfill('=') << setw((tam_vec * 10) / 2) << " INSERCIÓN " << setfill('=') << setw((tam_vec * 10) / 2) << "=|" << endl;
    									cout << "  | VECTOR GENERADO:" << endl;
    									vector_insercion.mostrar();

    									cout << "  |" << setfill('-') << setw(tam_vec * 10) << "-|" << endl;
    									vector_insercion.ordenar(true);
    									cout << "  |" << setfill('-') << setw(tam_vec * 10) << "-|" << endl;

    									cout << "  | VECTOR ORDENADO:" << endl;
    									vector_insercion.mostrar();
    									break;
    								}

    							case 2:
    								{
    									// ## LLENO EL VECTOR CON EL TDATO DNI
    									for(int i = 0 ; i < tam_vec ; i++)
    										{
    											DNI tmp_dni;
    											vector_burbuja.setDato(tmp_dni.getDni(), i);
    										}

    									cout << endl << "  |" << setfill('=') << setw((tam_vec * 10) / 2) << " BURBUJA " << setfill('=') << setw((tam_vec * 10) / 2) << "=|" << endl;
    									cout << "  | VECTOR GENERADO:" << endl;
    									vector_burbuja.mostrar();

    									cout << "  |" << setfill('-') << setw(tam_vec * 10) << "-|" << endl;
    									vector_burbuja.ordenar(true);
    									cout << "  |" << setfill('-') << setw(tam_vec * 10) << "-|" << endl;

    									cout << "  | VECTOR ORDENADO:" << endl;
    									vector_burbuja.mostrar();
    									break;
    								}

    							case 3:
    								{
    									// ## LLENO EL VECTOR CON EL TDATO DNI
    									for(int i = 0 ; i < tam_vec ; i++)
    										{
    											DNI tmp_dni;
    											vector_heap_sort.setDato(tmp_dni.getDni(), i);
    										}

    									cout << endl << "  |" << setfill('=') << setw((tam_vec * 10) / 2) << " HEAP SORT " << setfill('=') << setw((tam_vec * 10) / 2) << "=|" << endl;
    									cout << "  | VECTOR GENERADO:" << endl;
    									vector_heap_sort.mostrar();

    									cout << "  |" << setfill('-') << setw(tam_vec * 10) << "-|" << endl;
    									vector_heap_sort.ordenar(true);
    									cout << "  |" << setfill('-') << setw(tam_vec * 10) << "-|" << endl;

    									cout << "  | VECTOR ORDENADO:" << endl;
    									vector_heap_sort.mostrar();
    									break;
    								}

    							case 4:
    								{
    									// ## LLENO EL VECTOR CON EL TDATO DNI
    									for(int i = 0 ; i < tam_vec ; i++)
    										{
    											DNI tmp_dni;
    											vector_quicksort.setDato(tmp_dni.getDni(), i);
    										}

    									cout << endl << "  |" << setfill('=') << setw((tam_vec * 10) / 2) << " QUICKSORT " << setfill('=') << setw((tam_vec * 10) / 2) << "=|" << endl;
    									cout << "  | VECTOR GENERADO:" << endl;
    									vector_quicksort.mostrar();

    									cout << "  |" << setfill('-') << setw(tam_vec * 10) << "-|" << endl;
    									vector_quicksort.ordenar(0, tam_vec - 1, true);
    									cout << "  |" << setfill('-') << setw(tam_vec * 10) << "-|" << endl;

    									cout << "  | VECTOR ORDENADO:" << endl;
    									vector_quicksort.mostrar();
    									break;
    								}

    							case 5:
    								{
    									// ## LLENO EL VECTOR CON EL TDATO DNI
    									cout << "# Introduzca el valor de alfa (0 < alfa < 1)" << endl;
    									cin >> alfa;

    									for(int i = 0 ; i < tam_vec ; i++)
    										{
    											DNI tmp_dni;
    											vector_shellsort.setDato(tmp_dni.getDni(), i);
    										}

    									cout << endl << "  |" << setfill('=') << setw((tam_vec * 10) / 2) << " SHELLSORT " << setfill('=') << setw((tam_vec * 10) / 2) << "=|" << endl;
    									cout << "  | VECTOR GENERADO:" << endl;
    									vector_shellsort.mostrar();

    									cout << "  |" << setfill('-') << setw(tam_vec * 10) << "-|" << endl;
    									vector_shellsort.ordenar(alfa, true);
    									cout << "  |" << setfill('-') << setw(tam_vec * 10) << "-|" << endl;

    									cout << "  | VECTOR ORDENADO:" << endl;
    									vector_shellsort.mostrar();
    									break;
    								}
    						}
    					} while (opcion != 0);
    					break;
    				}

    				case 2:
    				{
					cout << endl << "  *" << setfill('=') << setw(24) << "*" << endl;
    					cout << "  ||  MODO ESTADÍSTICA" << setfill(' ') << setw(5) << "||" << endl;
    					cout << "  *" << setfill('=') << setw(24) << "*" << endl;

    					break;
    				}
    			}
    } while (modo != 0);




	return 0;
}
