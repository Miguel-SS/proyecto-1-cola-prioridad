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

	int getHijoDerecho(int);
	int getHijoIzquierdo(int);
	int getTam() { return list->getTam(); }
	std::string toString() { return list->toString(); }
};

