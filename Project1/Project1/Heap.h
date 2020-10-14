#pragma once
#include "Lista.h"

class Heap
{
private:
	Lista *list;
	 int tipo;
public:
	Heap(int=0);
	Heap(Heap*);
	Heap(Lista*);
	~Heap();
	void insertar(int);
	void eliminar(int);
	void heapify(int);
	void heapiMax(int);
	void heapiMin(int);
	void crearHeap(Lista*);

	int getPriority();

	Lista* getLista();

	int getPadre(int);
	int getHijoDerecho(int);
	int getHijoIzquierdo(int);
	int getTam() { return list->getTam(); }
	std::string toString() { return list->toString(); }
};

