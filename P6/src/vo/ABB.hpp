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
		void verArbol(NodoBB<T>* raiz, int n);

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
	verArbol(raiz_, 0);
}

template <class T>
void ABB<T>::verArbol(NodoBB<T>* raiz, int n){
	queue<NodoBB<T>*> cola;

	if(raiz_ != NULL){
		cola.push(raiz_);
    }
    else
    	cout << "[.]";

    int i = 1;
    int niv = 1;

    NodoBB<T>* aux;
    while (!cola.empty()){
    	cout << "  -> Nivel " << niv++ << ": ";
    	for (int c = 0; c < i; c++){
    		if (cola.empty())
    			break;

    		cout << " ";
    		aux = cola.front();
    		cola.pop();

    		if (aux == NULL)
    			cout << "[.]";
    		else{
    			cout << "[" << aux->clave_ << "]";
    			cola.push(aux->izquierdo_);
    			cola.push(aux->derecho_);
    		}
    	}

    	i = cola.size();
    	cout << endl;
    }

}
