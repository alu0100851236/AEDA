//===============================================================================
// Author      	: David Dorta Acosta
// email       	: alu0100851236@ull.edu.es
// Asignatura  	: Algoritmos y Estructura de Datos Avanzadas
// Curso			: 2017-2018
// Práctica 7	: Implementación de un árbol binario de búsqueda Balanceado (AVL)
//===============================================================================

#include "common_types.hpp"
#include "nodoAVL.hpp"
#include "queue"
#include <math.h>  // para utilizar la funcion pow

using namespace std;

template <class T>

class ArbolAVL{
	private:
		NodoAVL<T> *raiz_;

		int claveGenerada;
		int numNodos;
		int numBusqueda;
		int numInserciones;

		// METODOS
		void rotacion_II (NodoAVL<T>* &nodo);
		void rotacion_DD (NodoAVL<T>* &nodo);
		void rotacion_ID (NodoAVL<T>* &nodo);
		void rotacion_DI (NodoAVL<T>* &nodo);

	public:
		// CONSTRUCTOR
		ArbolAVL();

		// DESTRUCTOR
		~ArbolAVL();

		// METODOS
		void contarnodos();
		void cuenta(NodoAVL<T>*);
//		NodoAVL<T>* buscar(T clave);
//		NodoAVL<T>* buscarRama (NodoAVL<T>* nodo, T);
		void insertar (T clave_dada, int* numComparaciones);
		void insertar_bal (NodoAVL<T>* &nodo, NodoAVL<T>* nuevo, bool& crece, int* numComparacionesI);
		void insert_re_balancea_izda(NodoAVL<T>* &nodo, bool& crece, int* numComparacionesI);
		void insert_re_balancea_dcha(NodoAVL<T>* &nodo, bool& crece, int* numComparacionesI);
		void eliminar(T);
		void eliminarRama (NodoAVL<T>* &nodo, T clave_dada, bool& decrece);
		void sustituye (NodoAVL<T>* &eliminado, NodoAVL<T>* &sust, bool& decrece);
		void eliminar_re_balancea_izda(NodoAVL<T>* &nodo, bool& decrece);
		void eliminar_re_balancea_dcha(NodoAVL<T>* &nodo, bool& decrece);
		NodoAVL<T>* buscar(T clave, int* numComparacionesB);
		NodoAVL<T>* Buscar(NodoAVL<T>* nodo1, NodoAVL<T>* nodo2, int* numComparacionesB);
		void verArbol();
		void verArbol(NodoAVL<T>* raiz, int n);

		// METODOS PARA LAS ESTADÍSTICAS
		int getNumBusqueda();
		void setNumBusqueda(int valor);

		int getNumInsercion();
		void setNumInsercion(int valor);
};

template <class T>
ArbolAVL<T>::ArbolAVL():
	raiz_(NULL)
	{}

template <class T>
ArbolAVL<T>::~ArbolAVL(){}

template <class T>
void ArbolAVL<T>::contarnodos(){
	numNodos = 0;
	cuenta(raiz_);
}

template <class T>
void ArbolAVL<T>::cuenta(NodoAVL<T> *nodo){
	numNodos++;

	if (nodo->izquierdo_ != NULL)
		cuenta(nodo->izquierdo_);

	if (nodo->derecho_ != NULL)
		cuenta(nodo->derecho_);
}

//template <class T>
//NodoAVL<T>* ArbolAVL<T>::buscar(T clave){
//	return buscarRama(raiz_, clave);
//}
//
//template <class T>
//NodoAVL<T>* ArbolAVL<T>::buscarRama(NodoAVL<T>* nodo, T clave){
//	//  CONTADOR DE ESTADÍSITICAS DE BÚSQUEDA
//	numBusqueda++;
//
//	if (nodo == NULL)
//		return NULL;
//
//	// CLAVE IGUAL QUE LA CLAVE DEL NODO ACTUAL
//	else if (clave == nodo->clave_)
//		return nodo;
//
//	// CLAVE MENOR QUE LA CLAVE DEL NODO ACTUAL BUSCAMOS A LA IZQUIERDA
//	else if (clave < nodo->clave_)
//		return buscarRama(nodo->izquierdo_, clave);
//
//	// CLAVE MENOR QUE LA CLAVE DEL NODO ACTUAL BUSCAMOS A LA DERECHA
//	else
//		return buscarRama(nodo->derecho_, clave);
//}

template <class T>
void ArbolAVL<T>::insertar(T clave, int* numComparaciones){
	NodoAVL<T> *nuevo = new NodoAVL<T>(clave);
	bool crece = false;
	insertar_bal (raiz_, nuevo, crece, numComparaciones);
}

template <class T>
void ArbolAVL<T>::insertar_bal (NodoAVL<T>* &nodo, NodoAVL<T>* nuevo, bool& crece, int* numComparacionesI){

	if (nodo == NULL){
		*numComparacionesI += 1;
		nodo = nuevo;
		crece = true;
	}
	else if (nuevo->clave_ < nodo->clave_){
		*numComparacionesI += 1;
		insertar_bal (nodo->izquierdo_, nuevo, crece, numComparacionesI);
		if (crece)
			insert_re_balancea_izda(nodo, crece, numComparacionesI);
	}
	else{
		*numComparacionesI += 1;
		insertar_bal (nodo->derecho_, nuevo, crece, numComparacionesI);
		if (crece)
			insert_re_balancea_dcha(nodo, crece, numComparacionesI);
	}
}

template <class T>
void ArbolAVL<T>::insert_re_balancea_izda (NodoAVL<T>* &nodo, bool& crece, int* numComparacionesI){
	switch(nodo->bal){
		case -1:
			nodo->bal = 0;
			crece = false;
			break;

		case 0:
			nodo->bal = 1;
			break;

		case 1:
			NodoAVL<T>* nodo1 = nodo->izquierdo_;
			if (nodo1->bal == 1)
				rotacion_II(nodo);
			else
				rotacion_ID(nodo);
			crece = false;
			break;
	}
}

template <class T>
void ArbolAVL<T>::insert_re_balancea_dcha (NodoAVL<T>* &nodo, bool& crece, int* numComparacionesI){
	switch(nodo->bal){
		case 1:
			nodo->bal = 0;
			crece = false;
			break;

		case 0:
			nodo->bal = -1;
			break;

		case -1:
			NodoAVL<T>* nodo1 = nodo->derecho_;
			if (nodo1->bal == -1)
				rotacion_DD(nodo);
			else
				rotacion_DI(nodo);
			crece = false;
			break;
	}
}

template <class T>
void ArbolAVL<T>::eliminar(T clave_dada){
	bool decrece = false;
	eliminarRama(raiz_, clave_dada, decrece);
}

template <class T>
void ArbolAVL<T>::eliminarRama(NodoAVL<T>* &nodo, T clave_dada, bool& decrece){
	if (nodo == NULL)
		return;

	if (clave_dada < nodo->clave_){
		eliminarRama(nodo->izquierdo_, clave_dada, decrece);
		if (decrece)
			eliminar_re_balancea_izda(nodo, decrece);
	}
	else if (clave_dada > nodo->clave_){
		eliminarRama(nodo->derecho_, clave_dada, decrece);
		if (decrece)
			eliminar_re_balancea_dcha(nodo, decrece);
	}
	else {  // NODO->CLAVE == CLAVE_DADA (ENCONTRADO)
		NodoAVL<T>* Eliminado = nodo;
		if (nodo->izquierdo_ == NULL){
			nodo = nodo->izquierdo_;
			decrece = true;
		}
		else{
			sustituye(Eliminado, nodo->izquierdo_, decrece);
			if (decrece)
				eliminar_re_balancea_izda(nodo, decrece);
		}
		delete Eliminado;
	}
}

template <class T>
void ArbolAVL<T>::sustituye(NodoAVL<T>* &eliminado, NodoAVL<T>* &sust, bool& decrece){
	if (sust->derecho_ != NULL){
		sustituye(eliminado, sust->derecho_, decrece);
		if (decrece)
			eliminar_re_balancea_dcha(sust, decrece);
	}
	else{
		eliminado->clave_ = sust->clave_;
		eliminado = sust;
		sust = sust->izquierdo_;
		decrece = true;
	}
}

template <class T>
void ArbolAVL<T>::eliminar_re_balancea_izda(NodoAVL<T>* &nodo, bool& decrece){
	switch (nodo->bal){
		case -1:
		{
			NodoAVL<T>* nodo1 = nodo->derecho_;
			if (nodo1->bal > 0)
				rotacion_DI(nodo);
			else{
				if (nodo1->bal == 0)
					decrece = false;
				rotacion_DD(nodo);
			}
			break;
		}

		case 0:
		{
			nodo->bal = -1;
			decrece = false;
			break;
		}

		case 1:
			nodo->bal = 0;
			break;
	}
}

template <class T>
void ArbolAVL<T>::eliminar_re_balancea_dcha(NodoAVL<T>* &nodo, bool& decrece){
	switch (nodo->bal){
		case 1:
		{
			NodoAVL<T>* nodo1 = nodo->izquierdo_;
			if (nodo1->bal < 0)
				rotacion_ID(nodo);
			else{
				if (nodo1->bal == 0)
					decrece = false;
				rotacion_II(nodo);
			}
			break;
		}

		case 0:
		{
			nodo->bal = 1;
			decrece = false;
			break;
		}

		case -1:
			nodo->bal = 0;
			break;
	}
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::buscar(T clave, int* numComparacionesB){
	NodoAVL<T>* nodo2;
	nodo2 = new ArbolAVL<T>(clave);
	return buscarRama(raiz_, nodo2, numComparacionesB);
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::Buscar(NodoAVL<T>* nodo1, NodoAVL<T>* nodo2, int* numComparacionesB){
	if (nodo1 == NULL){
		*numComparacionesB += 1;
		return NULL;
	}
	else if (nodo2->clave_ == nodo1->clave_){
		*numComparacionesB += 1;
		return nodo1;
	}
	else if (nodo2->clave_ < nodo1->clave_){
		*numComparacionesB += 1;
		return Buscar(nodo1->izquierdo_, nodo2, numComparacionesB);
	}
	else{
		*numComparacionesB += 1;
		return Buscar(nodo1->derecho_, nodo2, numComparacionesB);
	}
}

template <class T>
int ArbolAVL<T>::getNumBusqueda(){
	return numBusqueda;
}

template <class T>
void ArbolAVL<T>::setNumBusqueda(int valor){
	numBusqueda = valor;
}

template <class T>
int ArbolAVL<T>::getNumInsercion(){
	return numInserciones;
}

template <class T>
void ArbolAVL<T>:: setNumInsercion(int valor){
	numInserciones = valor;
}

template <class T>
void ArbolAVL<T>::verArbol(){
	verArbol(raiz_, 0);
}

template <class T>
void ArbolAVL<T>::verArbol(NodoAVL<T>* raiz, int n){
	queue<NodoAVL<T>*> cola;

	if(raiz_ != NULL){
		cola.push(raiz_);
    }
    else
    	cout << "[.]";

    int i = 1;
    int niv = 1;

    NodoAVL<T>* aux;
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

// ### MÉTODOS PRIVADOS ###

template <class T>
void ArbolAVL<T>::rotacion_II(NodoAVL<T>* &nodo){
	NodoAVL<T>* nodo1 = nodo->izquierdo_;

	// ROTACION
	nodo->izquierdo_ = nodo1->derecho_;
	nodo1->derecho_ = nodo;

	// CORRECCIÓN DE BALANCEOS
	if (nodo1->bal == 1){
		nodo->bal = 0;
		nodo1->bal = 0;
	}
	else{   // SI NODO1->BAL == 0
		nodo->bal = 1;
		nodo1->bal = 1;
	}
	nodo = nodo1;
}

template <class T>
void ArbolAVL<T>::rotacion_DD(NodoAVL<T>* &nodo){
	NodoAVL<T>* nodo1 = nodo->derecho_;

	// ROTACION
	nodo->derecho_ = nodo1->izquierdo_;
	nodo1->izquierdo_ = nodo;

	// CORRECCIÓN DE BALANCEOS
	if (nodo1->bal == -1){
		nodo->bal = 0;
		nodo1->bal = 0;
	}
	else{   // SI NODO1->BAL == 0
		nodo->bal = -1;
		nodo1->bal = 1;
	}
	nodo = nodo1;
}

template <class T>
void ArbolAVL<T>::rotacion_ID(NodoAVL<T>* &nodo){
	NodoAVL<T>* nodo1 = nodo->izquierdo_;
	NodoAVL<T>* nodo2 = nodo->derecho_;

	// ROTACION
	nodo->izquierdo_ = nodo2->derecho_;
	nodo2->derecho_ = nodo;
	nodo1->derecho_ = nodo2->izquierdo_;
	nodo2->izquierdo_ = nodo1;

	// CORRECCIÓN DE BALANCEOS
	if (nodo2->bal == -1)
		nodo1->bal = 0;
	else
		nodo1->bal = 1;

	if (nodo2->bal == 1)
		nodo->bal = -1;
	else
		nodo->bal = 0;

	nodo2->bal = 0;
	nodo = nodo2;
}

template <class T>
void ArbolAVL<T>::rotacion_DI(NodoAVL<T>* &nodo){
	NodoAVL<T>* nodo1 = nodo->derecho_;
	NodoAVL<T>* nodo2 = nodo->izquierdo_;

	// ROTACION
	nodo->derecho_ = nodo2->izquierdo_;
	nodo2->izquierdo_ = nodo;
	nodo1->izquierdo_ = nodo2->derecho_;
	nodo2->derecho_ = nodo1;

	// CORRECCIÓN DE BALANCEOS
	if (nodo2->bal == 1)
		nodo1->bal = -1;
	else
		nodo1->bal = 0;

	if (nodo2->bal == -1)
		nodo->bal = 1;
	else
		nodo->bal = 0;

	nodo2->bal = 0;
	nodo = nodo2;
}
