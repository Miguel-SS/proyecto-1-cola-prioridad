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
	void heapify(int);
	void crearHeap(Lista*);

};

