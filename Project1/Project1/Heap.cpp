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
    heapify(list->getTam()-1);
    //heapifyBubbleUpMax(list->getTam()-1);
}

void Heap::eliminar(int n)
{
    int i = list->eliminar(n) * 2 + 1;
	heapify(i);
    heapify(list->getTam()-1);
}

void Heap::heapify(int pos)
{
    int max;
        

    // Obtenemos el padre y los hijos izquierdo y derecho a partir de la posición dada
    int padre = getPadre(pos);
    int izq = getHijoIzquierdo(padre);
    int der = getHijoDerecho(padre);

    /**/
    // Calculamos el elemento máximo para la posición
    if (izq != -1 && list->getNodo(izq)->value > list->getNodo(padre)->value)
        max = izq;
    else
        max = padre;
    if (der != -1 && list->getNodo(der)->value > list->getNodo(max)->value)
        max = der;

    // Si el elemento mayor del heap es diferente al indicado
    // en la posición, intercambiamos
    if (max != padre) {
        list->intercambiaNodos(padre, max);
        heapify(padre);
    }

    /**/
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

int Heap::getPadre(int pos)
{
    if (pos < 0 || pos >= list->getTam())
        return -1;
    return (pos - 1) / 2;
}

// Retorna la posición del hijo derecho
int Heap::getHijoDerecho(int pos) {
    int der = pos * 2 + 2;
    if (der >= list->getTam())
        return -1;
    return der;
}