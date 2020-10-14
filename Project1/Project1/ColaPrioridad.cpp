#include "ColaPrioridad.h"

ColaPrioridad::ColaPrioridad(){
	cola = new Heap();
	tam = cola->getTam();
}

ColaPrioridad::ColaPrioridad(ColaPrioridad& nueva){

	//cola = new Heap(nueva.cola->getLista());

	// utilizar constructor de copia de heap o lista

}

ColaPrioridad::ColaPrioridad(Lista* lista){

	cola->crearHeap(lista);
	tam = cola->getTam();
}

void ColaPrioridad::Agregar(int i){

	cola->insertar(i);

}

void ColaPrioridad::ExtraerMax(){

	cola->eliminar(getPriority());
	
}

bool ColaPrioridad::Compara(int objA, int objB){

	return(objA > objB) ? true : false;
}

int ColaPrioridad::getPriority()
{
	if (cola->getTam() > 0) {
		return cola->getPriority();
	}
	return -1;
}

int ColaPrioridad::getTam(){

	return cola->getTam();
}