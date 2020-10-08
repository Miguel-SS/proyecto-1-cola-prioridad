#include "Heap.h"

int main() {
	/*
	Lista list;
	list.insertarFinal(1);
	list.insertarFinal(2);
	
	std::cout << list.toString() << std::endl;

	list.intercambiaNodos(0, 1);

	std::cout << list.toString() << std::endl;
	/**/

	/**/
	Heap h;
	h.insertar(2);
	h.insertar(100);
	h.insertar(9);
	h.insertar(6);
	h.insertar(20);
	h.insertar(14);
	h.insertar(7);

	std::cout << h.toString() << std::endl;
	/**/
	//h.heapify(0);

	//std::cout << h.toString() << std::endl;


	return 0;
}