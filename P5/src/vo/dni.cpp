/*
 * dni.cpp
 *
 *  Created on: 26 mar. 2018
 */

#include "dni.hpp"
#include <ctime>

DNI::DNI():
numero_(00000000 + rand() % (99999999 + 1))
{}

DNI::DNI(int num){
	numero_ = num;
}

DNI::~DNI(){}

void DNI::setDni(int n){
	numero_ = n;
}

int DNI::getDni(){
	return numero_;
}

bool DNI::operator==(DNI& dni){
	if(getDni() == dni.getDni()){
		return true;
	}
	else{
		return false;
  }
}

bool DNI::operator==(int& dni){

  if(getDni() == dni){
    return true;
  }
  else{
    return false;
  }
}


DNI::operator int(){
	return numero_;
}

ostream& operator<<(ostream& os, DNI& dni){
	os << dni.getDni();
	return os;
}


