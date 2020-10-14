#include "ColaPrioridad.h"

ColaPrioridad::ColaPrioridad(){
	cola = new Heap();
	tam = cola->getTam();
}

ColaPrioridad::ColaPrioridad(ColaPrioridad* nueva){

	cola = new Heap();


	if (nueva->cola->getMax() != NULL) {

		cola->crearHeap(nueva->cola->getLista());

	}

	tam = cola->getTam();
}

ColaPrioridad::ColaPrioridad(Lista* lista){

	cola = new Heap();
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