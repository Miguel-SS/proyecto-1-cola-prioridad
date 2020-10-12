#pragma once
#include <iostream>
#include<sstream>
#include <string>

using namespace std;

class Persona{
private:

	string nombre;
	int id;

public:

	Persona() { nombre = ""; id = 0; };
	Persona(string n, int i);

	string getNombre();
	int getId();
	void setNombre(string n);
	void setId(int i);

	string tostring();
};

