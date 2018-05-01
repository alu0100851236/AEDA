//============================================================================
// Author      	: David Dorta Acosta
// email       	: alu0100851236@ull.edu.es
// Asignatura  	: Algoritmos y Estructura de Datos Avanzadas
// Curso			: 2017-2018
// Práctica 6	: Implementación de un árbol binario de búsqueda (ABB)
//============================================================================

#include "common_types.hpp"
#include "nodoBB.hpp"
#include "queue"
#include <math.h>  // para utilizar la funcion pow

using namespace std;

template <class T>

class ABB{
	private:
		NodoBB<T> *raiz_;

		int claveGenerada;
		int numNodos;
		int numBusqueda;
		int numInserciones;

	public:
		// CONSTRUCTOR
		ABB();

		// DESTRUCTOR
		~ABB();

		// METODOS
		void contarnodos();
		void cuenta(NodoBB<T>*);
		NodoBB<T>* buscar(T clave);
		NodoBB<T>* buscarRama (NodoBB<T>* nodo, T);
		void insertar (T clave, bool);
		void insertarRama (NodoBB<T>* &, T, bool);
		void eliminar(T);
		void eliminarRama (NodoBB<T>* &, T);
		void verArbol();

		// METODOS PARA LAS ESTADÍSTICAS
		int getNumBusqueda();
		void setNumBusqueda(int valor);

		int getNumInsercion();
		void setNumInsercion(int valor);
};

template <class T>
ABB<T>::ABB():
	raiz_(NULL)
	{}

template <class T>
ABB<T>::~ABB(){}

template <class T>
void ABB<T>::contarnodos(){
	numNodos = 0;
	cuenta(raiz_);
}

template <class T>
void ABB<T>::cuenta(NodoBB<T> *nodo){
	numNodos++;

	if (nodo->izquierdo_ != NULL)
		cuenta(nodo->izquierdo_);

	if (nodo->derecho_ != NULL)
		cuenta(nodo->derecho_);
}

template <class T>
NodoBB<T>* ABB<T>::buscar(T clave){
	return buscarRama(raiz_, clave);
}

template <class T>
NodoBB<T>* ABB<T>::buscarRama(NodoBB<T>* nodo, T clave){
	//  CONTADOR DE ESTADÍSITICAS DE BÚSQUEDA
	numBusqueda++;

	if (nodo == NULL)
		return NULL;

	// CLAVE IGUAL QUE LA CLAVE DEL NODO ACTUAL
	else if (clave == nodo->clave_)
		return nodo;

	// CLAVE MENOR QUE LA CLAVE DEL NODO ACTUAL BUSCAMOS A LA IZQUIERDA
	else if (clave < nodo->clave_)
		return buscarRama(nodo->izquierdo_, clave);

	// CLAVE MENOR QUE LA CLAVE DEL NODO ACTUAL BUSCAMOS A LA DERECHA
	else
		return buscarRama(nodo->derecho_, clave);
}

template <class T>
void ABB<T>::insertar(T clave, bool estadisticas){
	insertarRama(raiz_, clave, estadisticas);
}

template <class T>
void ABB<T>::insertarRama(NodoBB<T>* &nodo, T clave, bool estadisticas){

	// MOSTRAMOS LAS ESTADÍSTICAS EN CASO DE QUE SEA TRUE
	if (estadisticas){
		//  CONTADOR DE ESTADÍSITICAS DE INSERCIÓN
		numInserciones++;

		if (nodo != NULL){
			if (clave < nodo->clave_)
				insertarRama(nodo->izquierdo_, clave, estadisticas);
			else
				insertarRama(nodo->derecho_, clave, estadisticas);
		}
	}
	else{
		if (nodo == NULL)
			nodo = new NodoBB<T>(clave, clave);
		else if (clave < nodo->clave_)
			insertarRama(nodo->izquierdo_, clave, estadisticas);
		else
			insertarRama(nodo->derecho_, clave, estadisticas);
	}
}

template <class T>
void ABB<T>::eliminar(T clave){
	eliminarRama(raiz_, clave);
}

template <class T>
void ABB<T>::eliminarRama(NodoBB<T>* &nodo, T clave){
	if (clave < nodo->clave_)
		eliminarRama(nodo->izquierdo_, clave);
	else if (clave > nodo->clave_)
		eliminarRama(nodo->derecho_, clave);
	else{
		NodoBB<T>* eliminado = nodo;

		if (nodo->derecho_ == NULL){
			nodo = nodo->izquierdo_;
			delete(eliminado);
		}
		else if (nodo->izquierdo_ == NULL){
			nodo = nodo->derecho_;
			delete(eliminado);
		}
		else{
			NodoBB<T>* aux = nodo->izquierdo_;
			while (aux->derecho_ != NULL)
				aux = aux->derecho_;

			eliminado->clave_ = aux->clave_;
			eliminarRama(aux, aux->clave_);
		}
	}
}

template <class T>
int ABB<T>::getNumBusqueda(){
	return numBusqueda;
}

template <class T>
void ABB<T>::setNumBusqueda(int valor){
	numBusqueda = valor;
}

template <class T>
int ABB<T>::getNumInsercion(){
	return numInserciones;
}

template <class T>
void ABB<T>:: setNumInsercion(int valor){
	numInserciones = valor;
}

template <class T>
void ABB<T>::verArbol(){
	if (raiz_ != NULL){
		queue<NodoBB<T>*> lista;
		lista.push(raiz_);
		int niv = 0;
		int i = 1;
		int k = 0;
		int aux = 0;
		contarnodos();

		cout << endl << "## El número de nodos es, " << numNodos << endl;

		while (k < numNodos && !lista.empty()){
			if (lista.front() != NULL){
//				cout << endl << "Entra en el if (lista.front() != NULL)" << endl;
//				cout << "aux, " << aux << endl;
				cout << endl << " ------------------------------------------" << endl;
				cout << " = NIV: " << niv << endl;
				cout << " = aux: " << aux << endl;
				cout << "Raiz_->clave: " << raiz_->clave_ << endl;
				cout << "Raiz_->izquierdo: " << raiz_->izquierdo_ << endl;
				cout << "Raiz_->derecho: " << raiz_->derecho_ << endl;
				cout << " = lista.front()->clave_: " << lista.front()->clave_ << endl;
				cout << " = lista.front()->izquierdo_" << lista.front()->izquierdo_ << endl;
				cout << " = lista.front()->derecho_" << lista.front()->derecho_ << endl;
				cout << " ------------------------------------------" << endl << endl;
				if (aux == 0){
//					cout << endl << "ENTRA EN EL AUX == 0" << endl;
//				if (aux == 0 && niv == 0){
					cout << "  -> Nivel " << niv << ": [" << lista.front()->clave_ << "] [dcho]";

					if (k == numNodos - 1){
						cout << endl << "  -> Nivel " << niv+1 << ":";
						for (int n = 0; n <= i*2 ; n++)
							cout << " [.]";
					}

					aux = 1;
//
//					if (lista.front()->izquierdo_ == NULL){
//						cout << endl << "  -> Nivel " << niv+1 << ": [izq]";
//						if (lista.front()->derecho_ == NULL)
//							cout << " [dcho]";
//						else
//							cout << " [" << lista.front()->clave_ << "]";
//					}
//					else{
//						cout << endl << "  -> Nivel " << niv << ": [" << lista.front()->clave_ << "]";
//						if (lista.front()->derecho_ == NULL)
//							cout << " [dcho]";
//						else
//							cout << " [" << lista.front()->clave_ << "]";
//					}
//
//					if (lista.front()->derecho_ == NULL)
//						cout << " [dcho]";

//					aux = 1;
				}

//				if (aux == 0 && niv > 0){
//					cout << "Entra en el if (niv > 0)" << endl;
//					cout << endl << "  -> Nivel " << niv << ": [" << lista.front()->clave_ << "]";
//					if (lista.front()->izquierdo_ == NULL)
//						cout << endl << "  -> Nivel " << niv << ": [izq]";
//					else
//						cout << endl << "  -> Nivel " << niv << ": [" << lista.front()->clave_ << "]";
//
//					if (lista.front()->derecho_ == NULL)
//						cout << " [dcho]";
//					else
//						cout << " [" << lista.front()->clave_ << "]";
//					aux = 1;
//				}

				// AUX == 1 RAMA DERECHA
				else if (aux == 1){
					cout << "  -> Nivel " << niv << ": [" << lista.front()->clave_ << "]";

					if (k == numNodos - 1){
						cout << endl << "  -> Nivel " << niv+1 << ":";
						for (int n = 0; n <= i*2 ; n++)
							cout << " [.]";
					}
				}
				lista.push (lista.front()->izquierdo_);
				lista.push (lista.front()->derecho_);

//				cout << endl << " ------------------------------------------" << endl;
//				cout << " = NIV: " << niv << endl;
//				cout << " = aux: " << aux << endl;
//				cout << "Raiz_->clave: " << raiz_->clave_ << endl;
////				cout << "Raiz_->dato: " << raiz_->izquierdo_ << endl;
//				cout << " = lista.front()->clave_: " << lista.front()->clave_ << endl;
//				cout << " = lista.front()->izquierdo_" << lista.front()->izquierdo_ << endl;
//				cout << " = lista.front()->derecho_" << lista.front()->derecho_ << endl;
//				cout << " ------------------------------------------" << endl << endl;
//
//				if (niv == 0){
//					if ((lista.front()->izquierdo_ == NULL) && (lista.front()->derecho_ == NULL)){
//						cout << "  -> Nivel " << niv << ": [" << lista.front()->clave_ << "]";
//						cout << endl << "  -> Nivel " << niv+1 << ": [izq] [dcho]";
//					}
//					else{
//						cout << "  -> Nivel " << niv << ": [" << lista.front()->clave_ << "]";
//					}
//
////					if (lista.front()->derecho_ == NULL)
////						cout << " [dcho]";
////					else
////						cout << " [ d: " << lista.front()->derecho_ << "]";
//				}
//				else if ((lista.front()->izquierdo_ == NULL) && (lista.front()->derecho_ == NULL) && (niv > 0)){
//					cout << "  -> Nivel " << niv << ": [" << lista.front()->clave_ << "]";
//					cout << endl << "  -> Nivel " << niv+1 << ": [izq] [dcho]";
//				}
//				else if ((lista.front()->izquierdo_ != NULL) && (lista.front()->derecho_ == NULL) && (niv > 0)){
//					cout << endl << "  -> Nivel " << niv << ": [" << lista.front()->clave_ << "] [dcho]";
////					cout << endl << "  -> Nivel " << niv+1 << ": [" << lista.front()->clave_ << "] [dcho]";
////					if (lista.front()->derecho_ == NULL)
////						cout << " [dcho]";
////					else
////						cout << " [ i: " << lista.front()->clave_ << "]";
//				}
//				else if ((lista.front()->izquierdo_ == NULL) && (lista.front()->derecho_ != NULL) && (niv > 0))
//					cout << endl << "  -> Nivel " << niv << ": [izq] [" << lista.front()->clave_ << "]";
////					cout << endl << "  -> Nivel " << niv+1 << ": [izq] [" << lista.front()->clave_ << "]";
//
//				else if ((lista.front()->izquierdo_ != NULL) && (lista.front()->derecho_ != NULL) && (niv > 0))
//					cout << endl << "  -> Nivel " << niv+1 << ": [" << lista.front()->clave_ << "] [" << lista.front()->clave_ << "]";

//				}
//				else if (niv > 0 ){
//					cout << endl << "  -> Nivel- " << niv << ": [" << lista.front()->clave_ << "]";
//					if (lista.front()->derecho_ == NULL)
//						cout << " [dcho]";
//					else
//						cout << " [ i: " << lista.front()->clave_ << "]";
//				}


			}
			else{
				cout << endl << " ------------------------------------------" << endl;
				cout << " = NIV: " << niv << endl;
				cout << " = k: " << k << endl;
				cout << "Raiz_->clave: " << raiz_->clave_ << endl;
				cout << "Raiz_->izq: " << raiz_->izquierdo_ << endl;
//				cout << " = lista.front()->clave_: " << lista.front()->clave_ << endl;
//				cout << " = lista.front()->izquierdo_" << lista.front()->izquierdo_ << endl;
//				cout << " = lista.front()->derecho_" << lista.front()->derecho_ << endl;
				cout << " ------------------------------------------" << endl << endl;

				if (aux == 0){
					cout << "  -> Nivel " << niv << ": [izq]";
					aux = 1;
					k--;
				}
//				lista.push(NULL);
//				lista.push(NULL);
			}

//			if (k == numNodos - 1){
//				if (lista.front()->izquierdo_ == NULL)
//					cout << endl << "  -> Nivel " << niv+1 << ": [izq]";
//				if (lista.front()->derecho_ == NULL)
//					cout << " [dcho]";
//			}

//			if (lista.front() != NULL){
//				cout << " [" << lista.front()->clave_ << "]";
//			}
//			else{
//				cout << " [.]";
//				k--;
//			}

//			cout << endl << " == antes del pop, " << lista.front()->clave_ << endl;
			lista.pop();


			// CONTROLAMOS LAS POTENCIAS DE DOS PARA SABER SI SALTO AL SIGUIENTE NIVEL
//			cout << endl << "## i: " << i << endl;
//			cout << "## pow(2,niv): " << pow(2,niv) << endl;
			if (i == pow(2,niv)){
				cout << endl << endl << "==========================" << endl;
				cout << "Se produce un salto de nivel" << endl;
				niv++;
				aux = 0;
				i = 0;
				cout << endl;
			}

			cout << endl << "i: " << i << endl;
			i++;
			k++;
		}
	}
	else{
		cout << "Árbol vacío" << endl;
	}
	cout << endl;
}
