//============================================================================
// Author      	: David Dorta Acosta
// email       	: alu0100851236@ull.edu.es
// Asignatura  	: Algoritmos y Estructura de Datos Avanzadas
// Curso			: 2017-2018
// Práctica 6	: Implementación de un árbol binario de búsqueda (ABB)
//============================================================================

#include "common_types.hpp"

using namespace std;

template <class T>

class NodoBB{

	public:
		// CONSTRUCTOR
//		NodoBB(T dato, T clave, NodoBB* izquierdo = NULL, NodoBB* derecho = NULL);
		NodoBB(T dato, T clave);

		// DESTRUCTOR
		~NodoBB();

		// MIEMBROS
		T dato_;
		T clave_;
		NodoBB *izquierdo_;
		NodoBB *derecho_;
};


//template <class T>
//NodoBB<T>::NodoBB(T dato, T clave, NodoBB* izquierdo = NULL, NodoBB* derecho = NULL):
template <class T>
NodoBB<T>::NodoBB(T dato, T clave):
	dato_(dato),
	clave_(clave),
//	izquierdo_(izquierdo),
//	derecho_(derecho)
	izquierdo_(NULL),
	derecho_(NULL)
	{}

template <class T>
NodoBB<T>::~NodoBB(){};
