#include"ColaPrioridad.h"
#include "Persona.h"

int main() {
	/**/
	Persona* p1 = new Persona("Andres", 1, 23);
	Persona* p2 = new Persona("Francisco", 2, 46);
	Persona* p3 = new Persona("Juan", 3, 34);
	Persona* p4 = new Persona("Ana", 4, 54);
	Persona* p5 = new Persona("Maria", 5, 12);
	Persona* p6 = new Persona("Luis", 6, 43);
	Persona* p7 = new Persona("Sandra", 7, 5);
	Persona* p8 = new Persona("Jose", 8, 2);
	/**/

	/**
	if (*p1 < *p2) {
		std::cout << p2->getNombre() << " es mayor" << std::endl;
	}
	else {
		std::cout << p1->getNombre() << " es mayor" << std::endl;
	}

	if (*p2 < *p3) {
		std::cout << p3->getNombre() << " es mayor" << std::endl;
	}
	else {
		std::cout << p2->getNombre() << " es mayor" << std::endl;
	}

	if (*p1 > *p2) {
		std::cout << p1->getNombre() << " es mayor" << std::endl;
	}
	else {
		std::cout << p2->getNombre() << " es mayor" << std::endl;
	}

	if (*p2 == *p9) {
		std::cout << "Son iguales" << std::endl;
	}
	if (*p2 == *p8) {
		std::cout << "Son iguales" << std::endl;
	}
	if (*p4 == *p6) {
		std::cout << "Son iguales" << std::endl;
	}

	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	std::cout << *p3 << std::endl;
	std::cout << *p4 << std::endl << std::endl;

	*p3 = *p4;
	std::cout << *p3 << std::endl;
	std::cout << *p4 << std::endl;

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete p7;
	delete p8;
	/**/
	/**
	Lista<Persona>* list = new Lista<Persona>();
	list->insertarFinal(p1);
	list->insertarFinal(p2);
	list->insertarFinal(p3);
	list->insertarFinal(p4);
	list->insertarFinal(p5);
	list->insertarFinal(p6);
	list->insertarFinal(p7);
	list->insertarFinal(p8);

	std::cout << "Info Lista normal" << std::endl;
	
	std::cout << list->toString() << std::endl;

	

	/**/

	/**
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


	/**
	ColaPrioridad<Persona>* c = new ColaPrioridad<Persona>(list);

	std::cout <<"Info Cola C" << std::endl;

	std::cout << c->toString() << std::endl;



	ColaPrioridad<Persona>* a = new ColaPrioridad<Persona>(c);

	std::cout << "Info Cola A" << std::endl;

	std::cout << a->toString() << std::endl;
	/**/



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

	/**/
	Heap<Persona>* h = new Heap<Persona>();
	h->insertar(p1);
	h->insertar(p2);
	h->insertar(p3);
	h->insertar(p4);
	h->insertar(p5);
	h->insertar(p6);
	h->insertar(p7);
	h->insertar(p8);

	std::cout << h->toString() << std::endl;

	delete h;
	/**/


	//delete list;

	return 0;
}