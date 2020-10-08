#pragma once
#include <iostream>
#include <sstream>

class Lista {
private:
	struct Nodo {
		int value;
		struct Nodo* next;
		struct Nodo* prev;
		Nodo(int v = 0, Nodo* p = nullptr, Nodo* n = nullptr)
			: value{ v }, prev{ p }, next{ n } {}
	};
	Nodo* inicio;
	int tam;

public:
	typedef Nodo* iterador;


	Lista() { inicio = nullptr; tam = 0; }
	Lista(const Lista&);
	~Lista() { borrarLista(); }
	void insertarFinal(int);
	void eliminar(int);
	void eliminarPrimero();
	void borrarLista();
	bool isVacia();
	void intercambiaNodos(int, int);
	Nodo* getNodo(int);
	Nodo* getInicio();
	int getTam();
	std::string toString();

};