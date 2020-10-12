#include "ColaPrioridad.h"

ColaPrioridad::ColaPrioridad(){
	cola = new Heap();
	tam = cola->getTam();
}

ColaPrioridad::ColaPrioridad(ColaPrioridad& nueva) :cola( nullptr ), tam(nueva.tam) {

	//cola = new Heap(nueva.cola->getLista());

	// utilizar constructor de copia de heap o lista

}

ColaPrioridad::ColaPrioridad(Lista* lista){

	cola->crearHeap(lista);
	//cola->heapify();

}

void ColaPrioridad::Agregar(int i){

	cola->insertar(i);

}

void ColaPrioridad::ExtraerMax(){

	cola->eliminar(getMax());
	
}

bool ColaPrioridad::Compara(int objA, int objB){

	return(objA > objB) ? true : false;
}

int ColaPrioridad::getMax()
{
	if (tam > 0) {
		return cola->getLista()->getInicio()->value;
	}

	return -1;
}

int ColaPrioridad::getPadre(int pos){
	return cola->getPadre(pos);
}

int ColaPrioridad::getHijoDerecho(int pos){
	return cola->getHijoDerecho(pos);
}

int ColaPrioridad::getHijoIzquierdo(int pos){
	return cola->getHijoIzquierdo(pos);
}

int ColaPrioridad::getTam(){

	return cola->getTam();
}