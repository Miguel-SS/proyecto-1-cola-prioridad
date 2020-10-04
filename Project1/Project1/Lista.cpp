#include "Lista.h"

// Constructor copia
Lista::Lista(const Lista& obj)
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
void Lista::insertarFinal(int n)
{
	Nodo* nuevo = new Nodo(n);
	if (isVacia()) inicio = nuevo;
	else {
		iterador tmp = inicio;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = nuevo;
		nuevo->prev = tmp;
	}
}

// Elimina un elemento n de la lista (cualquier posición)
void Lista::eliminar(int n)
{
	if (!isVacia()) {
		if (inicio->value == n) eliminarPrimero();
		else {
			iterador tmp = inicio;
			while (tmp != nullptr) {
				if (tmp->next) {
					if (tmp->value == n) {
						tmp->prev->next = tmp->next;
						tmp->next->prev = tmp->prev;
						delete tmp;
						return;
					}
				}
				else {
					tmp->prev->next = nullptr;
					delete tmp;
					return;
				}
				tmp = tmp->next;
			}
		}
	}
}

void Lista::eliminarPrimero()
{
	if (!isVacia()) {
		Nodo* aux = inicio;
		inicio = inicio->next;
		delete aux;
	}
}

// Borra todos los nodos de la lista
void Lista::borrarLista() { while (!isVacia()) { eliminarPrimero(); } }

// Verifica si la lista está vacia
bool Lista::isVacia() { return (inicio != nullptr) ? false : true; }

// Devuelve los datos en forma de cadena
std::string Lista::toString()
{
	std::stringstream s;
	if (!isVacia()) {
		iterador tmp = inicio;
		while (tmp != nullptr) {
			s << tmp->value << "\t";
			tmp = tmp->next;
		}
		s << std::endl;
	}
	else {
		s << "Lista vacia" << std::endl;
	}
	return s.str();
}