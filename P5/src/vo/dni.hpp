//============================================================================
// Author      	: David Dorta Acosta
// email       	: alu0100851236@ull.edu.es
// Asignatura  	: Algoritmos y Estructura de Datos Avanzadas
// Curso			: 2017-2018
// Práctica 5	: Implementación de métodos de ordenación
//============================================================================

#include "common_types.hpp"

using namespace std;

class DNI{

  private:
    int numero_;

  public:
    // CONSTRUCTOR
    DNI();
    DNI(int num);

    // DESTRUCTOR
    ~DNI();

    // METODOS
    void setDni(int n);
    int getDni();
    bool operator==(DNI& dni);
    bool operator==(int& dni);
    operator int();

};

ostream& operator<<(ostream& os, DNI& dni);
