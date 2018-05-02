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
	ABB<DNI> arbolPruebas;
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
//    									char letra = 'a' + rand() % (('z' - 'a') + 1);
//    									string arrayNombres[10] = {"Carlos", "Daniel", "Nacho", "David", "Elena", "Karla", "Paula", "Eloisa", "Fernando", "Yaiza"};
    									srand(time(NULL));
    									if (valor_dni == 0){
    										cout << endl << "  # ARBOL VACÍO" << endl;
    										cout << "  -> Nivel 0: [.]" << endl;
    									}

    									cout << "  ================" << endl;
    									cout << "  # DNI A INSERTAR: ";
    									cin >> dni;
    									valor_dni.setDni(dni);
//    									valor_dni.setDni(dni, letra, arrayNombres[rand() % 10]);
    									arbol.insertar(valor_dni, false);
    									arbol.verArbol();
    									cout << endl;

    									break;
    								}
    							case 2:
    								{
    									cout << "  ================" << endl;
    									cout << "  # DNI A ELIMINAR: ";
    									cin >> dni;
    									valor_dni.setDni(dni);
    									arbol.eliminar(valor_dni);
    									arbol.verArbol();
    									cout << endl;

    									break;
    								}
    						}
    					} while  (opcion != 0);
    					break;
    				}

    				case 2:
    				{
    					int nPruebas, tam_arbol;

    					// ## INCIALIZACIÓN DE VARIABLES PARA LAS ESTADÍSTICAS
    					int max_busqueda	  	= 0, min_busqueda	= 2147483647, suma_busqueda 	= 0, media_busqueda	= 0;
    					int max_insercion	= 0, min_insercion	= 2147483647, suma_insercion	= 0, media_insercion	= 0;

    					cout << endl << "  *" << setfill('=') << setw(24) << "*" << endl;
    					cout << "  ||  MODO ESTADÍSTICA" << setfill(' ') << setw(5) << "||" << endl;
    					cout << "  *" << setfill('=') << setw(24) << "*" << endl;

    					cout << "  # Tamaño del árbol: ";
    					cin >> tam_arbol;

    					cout << "  # Introduce el número de pruebas a realizar: ";
    					cin >> nPruebas;

    					// ## CREACIÓN DEL BANCO DE PRUEBAS
    					DNI* vector_pruebas;
    					vector_pruebas = new DNI[2 * tam_arbol];

    					for (int i = 0; i < (2 * tam_arbol); i++){
    						DNI dni_aux;
    						vector_pruebas[i] = dni_aux;
    					}

    					// ## CREACIÓN DEL ÁRBOL ABB E INSERCIÓN DE LOS N PRIMEROS VALORES
    					for (int i = 0; i < (tam_arbol / 2); i++)
    						arbolPruebas.insertar(vector_pruebas[i], false);

    					// ## ESTADÍSTICAS PARA LA BÚSQUEDA
    					for (int i = 0; i < nPruebas; i++){
    						arbolPruebas.setNumBusqueda(0);
    						int indice_aleatorio = rand() % (tam_arbol / 2);

    						arbolPruebas.buscar(vector_pruebas[indice_aleatorio]);

    						suma_busqueda += arbolPruebas.getNumBusqueda();

    						if (arbolPruebas.getNumBusqueda() < min_busqueda)
    								min_busqueda = arbolPruebas.getNumBusqueda();

    						if (arbolPruebas.getNumBusqueda() > max_busqueda)
    								max_busqueda = arbolPruebas.getNumBusqueda();
    					}

    					// ## ESTADÍSTICAS PARA LA INSERCIÓN
    					for (int i = 0; i < nPruebas; i++){
    						arbolPruebas.setNumInsercion(0);
    						int indice_aleatorio = rand() % (tam_arbol / 2);

    						arbolPruebas.insertar(vector_pruebas[indice_aleatorio], true);

    						suma_insercion += arbolPruebas.getNumInsercion();

    						// ## MÍNIMO
    						if (arbolPruebas.getNumInsercion() < min_insercion)
    								min_insercion = arbolPruebas.getNumInsercion();

    						// ## MÁXIMO
    						if (arbolPruebas.getNumInsercion() > max_insercion)
    								max_insercion = arbolPruebas.getNumInsercion();
    					}

    					// ## CALCULOS DE LAS MEDIAS
    					media_busqueda = suma_busqueda / nPruebas;
    					media_insercion = suma_insercion / nPruebas;

    					// ## MOSTRAR LOS RESULTADOS POR PANTALLA
    					int a_m = 8;

    					cout << endl << endl << setfill(' ') << setw(45) << "--- NÚMERO DE COMPARACIONES ---" << endl;
    					cout << setfill(' ') << setw(15) 				<< "N" << setfill(' ')       << setw(9)   << " | " << setfill(' ') << setw(10)  << "Pruebas" << setfill(' ') << setw(6)   << " | " << setfill(' ') << setw(10)  << "Mínimo" << setfill(' ') 	     << setw(7)   << " | " << setfill(' ') << setw(9)   << "Medio" << setfill(' ')		 << setw(7)	 << " | " << setfill(' ') << setw(10)  << "Máximo" << endl;
    					cout << "INSERCIÓN: " << setfill(' ') << setw(5) << tam_arbol << setfill(' ') << setw(a_m) << " | " << setfill(' ') << setw(a_m) << nPruebas << setfill(' ')  << setw(a_m) << " | " << setfill(' ') << setw(a_m) << min_insercion << setfill(' ') << setw(a_m) << " | " << setfill(' ') << setw(a_m) << media_insercion << setfill(' ') << setw(a_m) << " | " << setfill(' ') << setw(a_m) << max_insercion << endl;
    					cout << "BÚSQUEDA : " << setfill(' ') << setw(5) << tam_arbol << setfill(' ') << setw(a_m) << " | " << setfill(' ') << setw(a_m) << nPruebas << setfill(' ')  << setw(a_m) << " | " << setfill(' ') << setw(a_m) << min_busqueda  << setfill(' ') << setw(a_m) << " | " << setfill(' ') << setw(a_m) << media_busqueda  << setfill(' ') << setw(a_m) << " | " << setfill(' ') << setw(a_m) << max_busqueda  << endl;
    					cout << endl;

    					break;

    				}
    			}
    } while (modo != 0);

}
