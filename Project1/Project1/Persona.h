#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Persona{
private:

	string nombre;
	int id;
	int edad;

public:

	Persona(string="INDEF", int=0, int=0);

	string getNombre();
	int getId();
	int getEdad();
	void setNombre(string);
	void setId(int);
	void setEdad(int);
	string toString();

	// Operadores
	Persona& operator=(Persona*);
	bool operator==(const Persona&);
	bool operator<(const Persona&);
	bool operator>(const Persona&);
	friend ostream& operator<<(ostream&, Persona&);
};

/**
#include "Persona.h"

Persona::Persona(string n, int i, int e) {
	nombre = n;
	id = i;
	edad = e;
}

string Persona::getNombre() { return nombre; }

int Persona::getId() { return id; }

int Persona::getEdad() { return edad; }

void Persona::setNombre(string n) { nombre = n; }

void Persona::setId(int i) { id = i; }

void Persona::setEdad(int e) { edad = e; }

string Persona::toString() {

	stringstream s;
	s << "Identificacion: " << id << endl;
	s << "Nombre: " << nombre << endl;
	s << "Edad: " << edad << endl;
	return s.str();
}

Persona& Persona::operator=(Persona* p)
{
	if (p != nullptr) {
		if (this != p) {
			if (this->id != p->id) this->id = p->id;
			if (this->nombre != p->nombre) this->nombre = p->nombre;
			if (this->edad != p->edad) this->edad = p->edad;
		}
	}
	return *p;
}

bool Persona::operator==(const Persona& p)
{
	return (this->edad == p.edad) ? true : false;
}

bool Persona::operator<(const Persona& p)
{
	return (this->edad < p.edad);
}

bool Persona::operator>(const Persona& p)
{
	return (this->edad > p.edad);
}

ostream& operator<<(ostream& os, Persona& p)
{
	os << p.toString();
	return os;
}
*/