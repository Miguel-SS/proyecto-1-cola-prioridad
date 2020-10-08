#include "Lista.h"

// Constructor copia
Lista::Lista(const Lista& obj)
{
	if (obj.inicio == nullptr) { inicio = nullptr; tam = 0; }
	else {
		inicio = new Nodo(obj.inicio->value);
		iterador tmp = inicio;
		iterador tmp_obj = obj.inicio->next;
		while (tmp_obj != nullptr) {
			tmp->next = new Nodo(tmp_obj->value, tmp);
			tmp = tmp->next;
			tmp_obj = tmp_obj->next;
		}
		tam = obj.tam;
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
	tam++;
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
						tam--;
						return;
					}
				}
				else {
					tmp->prev->next = nullptr;
					delete tmp;
					tam--;
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
		tam--;
	}
}

// Borra todos los nodos de la lista
void Lista::borrarLista() { while (!isVacia()) { eliminarPrimero(); } }

// Verifica si la lista está vacia
bool Lista::isVacia() { return (inicio != nullptr) ? false : true; }

void Lista::intercambiaNodos(int pos1, int pos2)
{
	if (pos1 <= tam && pos2 <= tam) {
		if (pos1 != pos2) {
			Nodo* nodo1;
			Nodo* nodo2;
			if (pos1 < pos2) {
				nodo1 = getNodo(pos1);
				nodo2 = getNodo(pos2)->prev;
			}
			else {
				nodo1 = getNodo(pos2);
				nodo2 = getNodo(pos1)->prev;
			}

			if (tam <= 2) {
				nodo2 = nodo2->next;
				nodo1->next = nullptr;
				nodo2->prev = nullptr;
				nodo1->prev = nodo2;
				nodo2->next = nodo1;
				inicio = nodo2;
			}
			else {
				Nodo* aux;
				if (nodo1->prev) {
					nodo1 = nodo1->prev;
					aux = nodo1->next;
					nodo1->next = nodo2->next;
					nodo2->next = aux;
					nodo1->next->prev = nodo1;
					nodo2->next->prev = nodo2;
					aux = nodo2->next->next;
					nodo2->next->next = nodo1->next->next;
					nodo1->next->next = aux;
				}
				else {
					aux = nodo1->next;
					nodo1->next = nodo2->next->next;
					if (nodo1->next) nodo1->next->prev = nodo1;
					nodo2->next->next = aux;
					aux->prev = nodo2->next;
					nodo2->next->prev = nullptr;
					nodo2->next = nodo1;
					nodo1->prev = nodo2;
					inicio = aux->prev;
				}
			}
		}
	}
}

Lista::Nodo* Lista::getNodo(int pos)
{
	if (pos <= tam) {
		iterador it = inicio;
		for (int i = 0; i <= pos; i++) {
			if (i == pos) {
				return it;
			}
			it = it->next;
		}
	}
	return nullptr;
}

Lista::Nodo* Lista::getInicio() { return inicio; }

int Lista::getTam() { return tam; }

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