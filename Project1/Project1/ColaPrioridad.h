#pragma once
#include "Heap.h"

template <class T>
class ColaPrioridad{

private:

	Heap<T>* cola;

public:

	ColaPrioridad();
	ColaPrioridad(ColaPrioridad<T>*);
	ColaPrioridad(Lista<T>*);

	void BorrarDatos();
	void CambiaTipo(int);
	void Agregar(T*);
	void ExtraerMax();
	bool Compara(T* objA, T* objB);

	T* getPriority();
	int getTam();

	std::string toString() { return cola->toString(); }
	
};

template <class T>
ColaPrioridad<T>::ColaPrioridad() {
	cola = new Heap<T>();
}

template <class T>
ColaPrioridad<T>::ColaPrioridad(ColaPrioridad<T>* nueva) {

	cola = new Heap<T>();


	if (getPriority() != NULL) {

		cola->crearHeap(nueva->cola->getLista());

	}

}

template <class T>
ColaPrioridad<T>::ColaPrioridad(Lista<T>* lista) {

	cola = new Heap<T>();
	cola->crearHeap(lista);
}

template<class T>
inline void ColaPrioridad<T>::BorrarDatos(){

	cola->vaciaLista();
}

template<class T>
inline void ColaPrioridad<T>::CambiaTipo(int x){

	cola->setTipo(x);
}

template <class T>
void ColaPrioridad<T>::Agregar(T* i) {

	cola->insertar(i);

}

template <class T>
void ColaPrioridad<T>::ExtraerMax() {

	cola->eliminar(getPriority());

}

template <class T>
bool ColaPrioridad<T>::Compara(T* objA, T* objB) {

	return(objA > objB) ? true : false;
}

template <class T>
T* ColaPrioridad<T>::getPriority()
{
	if (cola->getTam() > 0) {
		return cola->getPriority();
	}
	return nullptr;
}

template <class T>
int ColaPrioridad<T>::getTam() {

	return cola->getTam();
}