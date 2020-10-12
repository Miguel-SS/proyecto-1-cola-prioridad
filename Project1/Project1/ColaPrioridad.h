#pragma once
#include "Lista.h"
#include "Heap.h"


class ColaPrioridad{

private:

	Heap* cola;
	int tam;

public:

	ColaPrioridad();                   
	ColaPrioridad(ColaPrioridad&);     
	ColaPrioridad(Lista*);            
	void Agregar(int);
	void ExtraerMax();
	bool Compara(int objA, int objB);

	int getMax();
	int getPadre(int);
	int getHijoDerecho(int);
	int getHijoIzquierdo(int);
	int getTam();

	std::string toString() { return cola->getLista()->toString(); }


};