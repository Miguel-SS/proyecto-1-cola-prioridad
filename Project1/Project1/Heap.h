#pragma once
#include "Lista.h"

class Heap
{
private:
	Lista *list;
public:
	Heap();
	~Heap();
	void insertar(int);
	void eliminar(int);
	void heapify();
	void crearHeap(Lista*);

};

