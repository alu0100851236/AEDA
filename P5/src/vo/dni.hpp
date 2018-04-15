/*
 * dni.hpp
 *
 *  Created on: 26 mar. 2018
 */

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
    // operator unsingned long() const {
    //   usingned long tmp = (unsingned long)numero_;
    //   return tmp;} 
    operator int();

};

ostream& operator<<(ostream& os, DNI& dni);
