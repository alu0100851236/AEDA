//============================================================================
// Author      	: David Dorta Acosta
// email       	: alu0100851236@ull.edu.es
// Asignatura  	: Algoritmos y Estructura de Datos Avanzadas
// Curso			: 2017-2018
// Práctica 6	: Implementación de un árbol binario de búsqueda (ABB)
//============================================================================

#include "vo/common_types.hpp"
#include "vo/dni.hpp"
#include "vo/ABB.hpp"

using namespace std;

int main(){
	ABB<DNI> arbol;
	//ABB<DNI> arbolPruebas;
	int modo, opcion, dni;
	DNI valor_dni;
	valor_dni.setDni(0);

	cout << "*" << setfill('-') << setw(62) << "*" << endl;
	cout << "| PRACTICA 6: IMPLEMENTACIÓN DE UN ÁRBOL BINARIO DE BÚSQUEDA" << setfill(' ') << setw(3) << "|" << endl;
	cout << "| Autor: David Dorta Acosta" << setfill(' ') << setw (36) << "|" << endl;
	cout << "| email: alu0100851236@ull.edu.es" << setfill(' ') << setw(30) << "|" << endl;
	cout << "| fecha entrega: 2 mayo 2018" << setfill(' ') << setw(35) << "|" << endl;
	cout << "*" << setfill('-') << setw(62) << "*" << endl << endl;

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
    						cout << "  ||  0. Salir" << setfill(' ') << setw(13) << "||" << endl;
    						cout << "  ||  1. Insertar Clave" << setfill(' ') << setw(4) << "||" << endl;
    						cout << "  ||  2. Eliminar Clave" << setfill(' ') << setw(4) << "||" << endl;
    						cout << "  *" << setfill('=') << setw(24) << "*" << endl;

    						cout << "  Seleccione una opción: ";
    						cin >> opcion;

    						switch(opcion){
    							case 1:
    								{
    									if (valor_dni == 0){
    										cout << endl << "  # ARBOL VACÍO" << endl;
    										cout << "  -> Nivel 0: [.]" << endl;
    									}

    									cout << "  =============" << endl;
    									cout << "  # INSERTAR DNI: ";
    									cin >> dni;
    									valor_dni.setDni(dni);
    									arbol.insertar(valor_dni, false);
    									arbol.verArbol();
    									cout << endl;

    									break;
    								}
    						}
    					} while  (opcion != 0);
    					break;
    				}
    			}
    } while (modo != 0);

}
