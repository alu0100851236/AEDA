//============================================================================
// Author      	: David Dorta Acosta
// email       	: alu0100851236@ull.edu.es
// Asignatura  	: Algoritmos y Estructura de Datos Avanzadas
// Curso			: 2017-2018
// Práctica 5	: Implementación de métodos de ordenación
//============================================================================


#include "dni.hpp"
#include <ctime>

DNI::DNI():
numero_(00000000 + rand() % (99999999 + 1)),
letra_('a' + rand() % (('z' - 'a') + 1)),
//letra_('a'),
nombre_("david")
{}

DNI::DNI(int num){
	numero_ = num;
}

DNI::DNI(int num, char letra, string nombre){
	numero_ = num;
	letra_ = letra;
	nombre_ = nombre;
}


DNI::~DNI(){}

void DNI::setDni(int n){
	numero_ = n;
}

void DNI::setDni(int n, char letra, string nombre){
	numero_ = n;
	letra_ = letra;
	nombre_ = nombre;
}

int DNI::getDni(){
	return numero_;
}

char DNI::getDniLetra(){
	return letra_;
}
string DNI::getDniNombre(){
	return nombre_;
}

bool DNI::operator == (DNI& dni){
	if(getDni() == dni.getDni()){
		if(int(getDniLetra()) < int(dni.getDniLetra()))
			return true;
		else
			return false;
	}
	else{
		return false;
  }
}

bool DNI::operator < (DNI& dni){
	if(getDni() < dni.getDni()){
		if(getDni() == dni.getDni())
			if(int(getDniLetra()) < int(dni.getDniLetra()))
				return true;
			else
				return false;
		return true;
	}
	else{
		return false;
  }
}

bool DNI::operator > (DNI& dni){
	if(getDni() > dni.getDni()){
		if(getDni() == dni.getDni())
			if(int(getDniLetra()) < int(dni.getDniLetra()))
				return true;
			else
				return false;
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
//	os << dni.getDni();
	os << dni.getDni() << "-" << dni.getDniLetra() <<" "<< dni.getDniNombre() ;
	return os;
}


