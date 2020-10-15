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
	return (this->edad == p.edad);
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