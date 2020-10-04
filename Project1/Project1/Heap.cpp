#include "Heap.h"

// Constructor copia
Heap::Heap(const Heap& obj)
{
	if (obj.inicio == nullptr) inicio = nullptr;
	else {
		inicio = new Nodo(obj.inicio->value);
		iterador tmp = inicio;
		iterador tmp_obj = obj.inicio->next;
		while (tmp_obj != nullptr) {
			tmp->next = new Nodo(tmp_obj->value, tmp);
			tmp = tmp->next;
			tmp_obj = tmp_obj->next;
		}
	}
}

// Inserta un elemento n al final de la lista
void Heap::insertar(int n)
{
	
}

void Heap::eliminar(int n) { Lista::eliminar(n); }

void Heap::heapify()
{
}

void Heap::crearHeap()
{
}
