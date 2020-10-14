#pragma once
#include "Lista.h"

template <class T>
class Heap
{
private:
	Lista<T> *list;
	int tipo;
public:
	Heap(int=0);
	Heap(Heap<T>*);
	Heap(Lista<T>*);
	~Heap();
	void insertar(T*);
	void eliminar(T*);
	void heapify(int);
	void heapiMax(int);
	void heapiMin(int);
	void crearHeap(Lista<T>*);

	T* getPriority();

	Lista<T>* getLista();

	int getPadre(int);
	int getHijoDerecho(int);
	int getHijoIzquierdo(int);
	int getTam() { return list->getTam(); }
	std::string toString() { return list->toString(); }
};


// ************ Definicion ******************

template <class T>
Heap<T>::Heap(int t) {
    list = new Lista<T>();
    tipo = t;
}

template <class T>
Heap<T>::Heap(Heap<T>* nuevo) {



}

template <class T>
Heap<T>::Heap(Lista<T>* l2) {

    crearHeap(l2);
}

template <class T>
Heap<T>::~Heap() {}

template <class T>
void Heap<T>::insertar(T* n) {
    list->insertarFinal(n);
    heapify(list->getTam() - 1);
}

template <class T>
void Heap<T>::eliminar(T* n) {
    int i = list->eliminar(n) * 2 + 1;
    heapify(i);
    heapify(list->getTam() - 1);
}

template <class T>
void Heap<T>::heapify(int pos) {
    (tipo == 0) ? heapiMax(pos) : heapiMin(pos);
}

template <class T>
void Heap<T>::heapiMax(int pos)
{
    int max;

    // Obtenemos el padre y los hijos izquierdo y derecho a partir de la posición dada
    int padre = getPadre(pos);
    int izq = getHijoIzquierdo(padre);
    int der = getHijoDerecho(padre);

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
}

template <class T>
void Heap<T>::heapiMin(int pos)
{
    int min;

    // Obtenemos el padre y los hijos izquierdo y derecho a partir de la posición dada
    int padre = getPadre(pos);
    int izq = getHijoIzquierdo(padre);
    int der = getHijoDerecho(padre);

    // Calculamos el elemento minimo para la posición
    if (izq != -1 && list->getNodo(izq)->value < list->getNodo(padre)->value)
        min = izq;
    else
        min = padre;
    if (der != -1 && list->getNodo(der)->value < list->getNodo(min)->value)
        min = der;

    // Si el elemento menor del heap es diferente al indicado
    // en la posición, intercambiamos
    if (min != padre) {
        list->intercambiaNodos(padre, min);
        heapify(padre);
    }
}

template <class T>
void Heap<T>::crearHeap(Lista<T>* L2) {
    if (list->getInicio() != NULL) {
        list->borrarLista();
    }

    int x = 0;
    while (x < L2->getTam()) {
        insertar(L2->getValores(x));
        x++;
    }

}

template <class T>
T* Heap<T>::getPriority()
{
    return list->getNodo(0)->value;
}

template <class T>
Lista<T>* Heap<T>::getLista()
{
    return list;
}

template <class T>
int Heap<T>::getHijoIzquierdo(int pos) {
    int izq = pos * 2 + 1;
    if (izq >= list->getTam())
        return -1;
    return izq;
}

template <class T>
int Heap<T>::getPadre(int pos) {
    if (pos < 0 || pos >= list->getTam())
        return -1;
    return (pos - 1) / 2;
}

// Retorna la posición del hijo derecho
template <class T>
int Heap<T>::getHijoDerecho(int pos) {
    int der = pos * 2 + 2;
    if (der >= list->getTam())
        return -1;
    return der;
}