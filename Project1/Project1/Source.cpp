#include "Heap.h"
#include"ColaPrioridad.h"

int main() {
	
	Lista* list = new Lista();
	list->insertarFinal(44);
	list->insertarFinal(26);
	list->insertarFinal(73);
	list->insertarFinal(10);
	list->insertarFinal(21);
	list->insertarFinal(72);
	list->insertarFinal(58);
	list->insertarFinal(99);

	std::cout << "Info Lista normal" << std::endl;
	
	std::cout << list->toString() << std::endl;

	/*list.intercambiaNodos(0, 7);

	std::cout << list.toString() << std::endl;*/
	/*
	Heap h;
	h.crearHeap(list);

	std::cout << h.toString() << std::endl;

	h.insertar(50);
	std::cout << h.toString() << std::endl;
	*/
	/*
	h.insertar(2);
	h.insertar(9);
	h.insertar(6);
	h.insertar(20);
	h.insertar(100);
	h.insertar(14);
	h.insertar(7);
	h.insertar(50);

	std::cout << h.toString() << std::endl;
	std::cout << h.getMax() << std::endl;

	
	h.eliminar(100);

	std::cout << h.toString() << std::endl;
	std::cout << h.getMax() << std::endl;
	/**/


	
	ColaPrioridad* c = new ColaPrioridad(list);

	std::cout <<"Info Cola C" << std::endl;

	std::cout << c->toString() << std::endl;



	ColaPrioridad* a = new ColaPrioridad(c);

	std::cout << "Info Cola A" << std::endl;

	std::cout << a->toString() << std::endl;




/*
	c->Agregar(20);
	c->Agregar(3);
	c->Agregar(89);
	c->Agregar(76);
	c->Agregar(54);
	c->Agregar(33);
	c->Agregar(27);
	c->Agregar(13);
	c->Agregar(5);
	c->Agregar(8);
	c->Agregar(11);

	std::cout << c->toString() << std::endl; 

	c->ExtraerMax();

	std::cout << c->toString() << std::endl;
	*/

	return 0;
}