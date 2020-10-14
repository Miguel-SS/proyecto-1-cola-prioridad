#include "Heap.h"

Heap::Heap(int t){
	list = new Lista();
    tipo = t;
}

Heap::Heap(Heap* nuevo){



}

Heap::Heap(Lista* l2){

    crearHeap(l2);
}

Heap::~Heap(){}

void Heap::insertar(int n){
	list->insertarFinal(n);
    heapify(list->getTam()-1);
}

void Heap::eliminar(int n){
    int i = list->eliminar(n) * 2 + 1;
	heapify(i);
    heapify(list->getTam()-1);
}

void Heap::heapify(int pos) {
    (tipo == 0) ? heapiMax(pos) : heapiMin(pos);
}

void Heap::heapiMax(int pos)
{
    int max;

    // Obtenemos el padre y los hijos izquierdo y derecho a partir de la posici�n dada
    int padre = getPadre(pos);
    int izq = getHijoIzquierdo(padre);
    int der = getHijoDerecho(padre);

    // Calculamos el elemento m�ximo para la posici�n
    if (izq != -1 && list->getNodo(izq)->value > list->getNodo(padre)->value)
        max = izq;
    else
        max = padre;
    if (der != -1 && list->getNodo(der)->value > list->getNodo(max)->value)
        max = der;

    // Si el elemento mayor del heap es diferente al indicado
    // en la posici�n, intercambiamos
    if (max != padre) {
        list->intercambiaNodos(padre, max);
        heapify(padre);
    }
}

void Heap::heapiMin(int pos)
{
    int min;

    // Obtenemos el padre y los hijos izquierdo y derecho a partir de la posici�n dada
    int padre = getPadre(pos);
    int izq = getHijoIzquierdo(padre);
    int der = getHijoDerecho(padre);

    // Calculamos el elemento minimo para la posici�n
    if (izq != -1 && list->getNodo(izq)->value < list->getNodo(padre)->value)
        min = izq;
    else
        min = padre;
    if (der != -1 && list->getNodo(der)->value < list->getNodo(min)->value)
        min = der;

    // Si el elemento menor del heap es diferente al indicado
    // en la posici�n, intercambiamos
    if (min != padre) {
        list->intercambiaNodos(padre, min);
        heapify(padre);
    }
}

void Heap::crearHeap(Lista *L2){
    if (list->getInicio() != NULL) {
        list->borrarLista();
    }
    
    int x = 0;
    while (x < L2->getTam()) {
        insertar(L2->getValores(x));
        x++;
    }

}

int Heap::getPriority()
{
    return list->getNodo(0)->value;
}

Lista* Heap::getLista()
{
    return list;
}

int Heap::getHijoIzquierdo(int pos) {
    int izq = pos * 2 + 1;
    if (izq >= list->getTam())
        return -1;
    return izq;
}

int Heap::getPadre(int pos){
    if (pos < 0 || pos >= list->getTam())
        return -1;
    return (pos - 1) / 2;
}

// Retorna la posici�n del hijo derecho
int Heap::getHijoDerecho(int pos) {
    int der = pos * 2 + 2;
    if (der >= list->getTam())
        return -1;
    return der;
}