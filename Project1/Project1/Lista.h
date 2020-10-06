#pragma once
#include <iostream>
#include <sstream>

class Lista {
private:
	struct Nodo {
		int value;
		int index;
		struct Nodo* next;
		struct Nodo* prev;
		Nodo(int v = 0, Nodo* p = nullptr, Nodo* n = nullptr)
			: value{ v }, prev{ p }, next{ n } {}
	};
	Nodo* inicio;

public:
	typedef Nodo* iterador;


	Lista() { inicio = nullptr; }
	Lista(const Lista&);
	~Lista() { borrarLista(); }
	void insertarFinal(int);
	void eliminar(int);
	void eliminarPrimero();
	void borrarLista();
	bool isVacia();
	Nodo* getInicio();
	std::string toString();

};