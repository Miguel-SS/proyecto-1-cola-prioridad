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
}

void Heap::eliminar(int n)
{
	list->eliminar(n);
}

void Heap::heapify(int pos)
{
    /*
    int max;

    // Obtenemos los hijos izquierdo y derecho a partir de la posición dada
    int izq = GetHijoIzquierdo(pos);
    int der = GetHijoDerecho(pos);

    // Calculamos el elemento máximo para la posición
    if (izq != -1 && v[izq] > v[pos])
        max = izq;
    else
        max = pos;
    if (der != -1 && v[der] > v[max])
        max = der;

    // Si el elemento mayor del heap es diferente al indicado
    // en la posición, intercambiamos
    if (max != pos) {
        int tmp = v[pos];
        v[pos] = v[max];
        v[max] = tmp;
        Heapify(max);
    }
    */
}

void Heap::crearHeap(Lista *heapiList)
{
	list = heapiList;
	//heapify();
}
