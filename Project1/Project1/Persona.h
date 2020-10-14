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

