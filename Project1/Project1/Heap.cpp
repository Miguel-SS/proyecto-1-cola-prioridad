#include "Heap.h"

Heap::Heap()
{
}

Heap::~Heap()
{
}

void Heap::insertar(int n)
{
	list->insertarFinal(n);
}

void Heap::eliminar(int n)
{
	list->eliminar(n);
}

void Heap::heapify()
{
}

void Heap::crearHeap(Lista *heapiList)
{
}
