#include "Heap.h"

Heap::Heap()
{
	list = new Lista();
}

Heap::~Heap()
{
}

void Heap::insertar(int n)
{
	list->insertarFinal(n);
    heapify(0);
}

void Heap::eliminar(int n)
{
	list->eliminar(n);
}

void Heap::heapify(int pos)
{
    
    int max;

    // Obtenemos los hijos izquierdo y derecho a partir de la posición dada
    int izq = getHijoIzquierdo(pos);
    int der = getHijoDerecho(pos);

    // Calculamos el elemento máximo para la posición
    if (izq != -1 && list->getNodo(izq)->value > list->getNodo(pos)->value)
        max = izq;
    else
        max = pos;
    if (der != -1 && list->getNodo(der)->value > list->getNodo(max)->value)
        max = der;

    // Si el elemento mayor del heap es diferente al indicado
    // en la posición, intercambiamos
    if (max != pos) {
        list->intercambiaNodos(pos, max);
        heapify(max);
    }
}

void Heap::crearHeap(Lista *heapiList)
{
	list = heapiList;
	//heapify();
}


int Heap::getHijoIzquierdo(int pos) {
    int izq = pos * 2 + 1;
    if (izq >= list->getTam())
        return -1;
    return izq;
}

// Retorna la posición del hijo derecho
int Heap::getHijoDerecho(int pos) {
    int der = pos * 2 + 2;
    if (der >= list->getTam())
        return -1;
    return der;
}