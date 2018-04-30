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
	if (estadisticas){
		// numInsercciones++;

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
				aux = aux->derecno_;

			eliminado->clave_ = aux->clave_;
			eliminarRama(aux, aux->clave_);
		}
	}
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

		while (k < numNodos && !lista.empty()){
			if (lista.front() != NULL){
				if (aux == 0){
					cout << "Nivel: " << niv << ":";
					aux = 1;
				}

				lista.push (lista.front()->izquierdo_);
				lista.push (lista.front()->derecho_);
			}
			else{
				if (aux == 0){
					cout << "Nivel: " << niv << ":";
					aux = 1;
				}

				lista.push(NULL);
				lista.push(NULL);
			}

			if (lista.front() != NULL){
				cout << " [" << lista.front()->clave_ << "]";
			}
			else{
				cout << " [.]";
				k--;
			}

			lista.pop();

			// CONTROLAMOS LAS POTENCIAS DE DOS PARA SABER SI SALTO AL SIGUIENTE NIVEL
//			cout << endl << "## i: " << i << endl;
//			cout << "## pow(2,niv): " << pow(2,niv) << endl;
			if (i == pow(2,niv)){
				niv++;
				aux = 0;
				i = 0;
				cout << endl;
			}

			i++;
			k++;
		}
	}
	else{
		cout << "Árbol vacío" << endl;
	}
	cout << endl;
}
