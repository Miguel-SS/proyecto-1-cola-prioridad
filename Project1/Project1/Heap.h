#pragma once
#include "Lista.h"
#include <iostream>
#include <sstream>

class Heap : public Lista
{
public:
	typedef Nodo* iterador;


	Heap() { inicio = nullptr; }
	Heap(const Heap&);
	~Heap() {}
	void insertar(int);
	void eliminar(int);
	void heapify();
	void crearHeap();

};

