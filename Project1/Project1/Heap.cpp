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

void Heap::heapifyBubbleUpMax(int i) {//Utilizado para mantener la propirdad de un maxHeap cada vez que se inserta
    int padre = getPadre(i);
    int izq = getHijoIzquierdo(padre);
    int der = getHijoDerecho(padre);
    int mayor = -1;
    if (i > 0) { //El padre siempre es mayor que cero ya que el indice inicia en 1
        (list->getNodo(izq) > list->getNodo(der)) ? mayor = izq : mayor = der;
        //mayor = list->compararMayor(izq, der);//Se busca el mayor entre los hermanos
        if (mayor != -1) {
            (list->getNodo(mayor) > list->getNodo(padre)) ? mayor = mayor : mayor = padre;
            //mayor = lista->compararMayor(mayor, padre);//Se busca el mayor entre el hijo y el padre
            if (mayor != padre) {//Si el mayor es diferente al padre
                list->intercambiaNodos(padre, mayor);
                heapifyBubbleUpMax(padre);//Como hubo un intercambio entre el padre y el hijo, la posicion del antiguo padre cambio con la del hijo
                               //Entonces el que ahora es padre tomo el indice del padre anterior, por eso se repite recursivamente heapify
            }
            return;
        }
        return;
    }
    return;
}