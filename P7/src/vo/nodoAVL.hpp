//===============================================================================
// Author      	: David Dorta Acosta
// email       	: alu0100851236@ull.edu.es
// Asignatura  	: Algoritmos y Estructura de Datos Avanzadas
// Curso			: 2017-2018
// Práctica 7	: Implementación de un árbol binario de búsqueda Balanceado (AVL)
//===============================================================================

#include "common_types.hpp"

using namespace std;

template <class T>

class NodoAVL{

	public:
		// CONSTRUCTOR
//		NodoAVL(T dato, T clave);
		NodoAVL(T clave);

		// DESTRUCTOR
		~NodoAVL();

		// MIEMBROS
		T dato_;
		T clave_;
		int bal;
		NodoAVL *izquierdo_;
		NodoAVL *derecho_;

		void imprimir();
};


template <class T>
NodoAVL<T>::NodoAVL(T clave):
//NodoAVL<T>::NodoAVL(T dato, T clave):
//	dato_(dato),
	clave_(clave),
	bal(0),
	izquierdo_(NULL),
	derecho_(NULL)
	{}

template <class T>
NodoAVL<T>::~NodoAVL(){};

template <class T>
void NodoAVL<T>::imprimir(){
	cout << "[" << clave_ << "]";
}
