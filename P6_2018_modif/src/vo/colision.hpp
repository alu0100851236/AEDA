//============================================================================
// Author      	: David Dorta Acosta
// email       	: alu0100851236@ull.edu.es
// Asignatura  	: Algoritmos y Estructura de Datos Avanzadas
// Curso			: 2017-2018
// Práctica 6	: Implementación de un árbol binario de búsqueda (ABB)
//============================================================================

#include "common_types.hpp"

using namespace std;

class Colision{
	private:
		int c_;

	public:
		// CONSTRUCTOR
		Colision();

		int getColision();
		void setColision(int c);

};

Colision::Colision():
	c_ (0)
	{}

int Colision::getColision(){
	return (c_);
}

void Colision::setColision(int c){
	c_ += c;
}
