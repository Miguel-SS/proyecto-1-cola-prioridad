#include "Persona.h"

Persona::Persona(string n, int i) {

	nombre = n;
	id = i;
}

string Persona::getNombre() {
	return nombre;
}

int Persona::getId() {
	return id;
}

void Persona::setNombre(string n) {
	nombre = n;
}

void Persona::setId(int i) {
	id = i;
}

string Persona::tostring() {

	stringstream s;
	s << "Nombre :" << nombre << endl;
	s << "Identificacion: " << id << endl;
	return s.str();
}
