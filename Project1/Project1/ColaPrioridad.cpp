#include "ColaPrioridad.h"
/**
template <class T>
ColaPrioridad<T>::ColaPrioridad(){
	cola = new Heap();
}

template <class T>
ColaPrioridad<T>::ColaPrioridad(ColaPrioridad<T>* nueva){

	cola = new Heap();


	if (getPriority() != NULL) {

		cola->crearHeap(nueva->cola->getLista());

	}

}

template <class T>
ColaPrioridad<T>::ColaPrioridad(Lista<T>* lista){

	cola = new Heap();
	cola->crearHeap(lista);
}

template <class T>
void ColaPrioridad<T>::Agregar(T* i){

	cola->insertar(i);

}

template <class T>
void ColaPrioridad<T>::ExtraerMax(){

	cola->eliminar(getPriority());
	
}

template <class T>
bool ColaPrioridad<T>::Compara(T* objA, T* objB){

	return(objA > objB) ? true : false;
}

template <class T>
T* ColaPrioridad<T>::getPriority()
{
	if (cola->getTam() > 0) {
		return cola->getPriority();
	}
	return -1;
}

template <class T>
int ColaPrioridad<T>::getTam(){

	return cola->getTam();
}
/**/