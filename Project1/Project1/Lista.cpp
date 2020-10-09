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
int Lista::eliminar(int n)
{
	if (!isVacia()) {
		int i = 0;
		if (inicio->value == n) { eliminarPrimero(); return i; }
		else {
			iterador tmp = inicio;
			while (tmp != nullptr) {
				if (tmp->next) {
					if (tmp->value == n) {
						tmp->prev->next = tmp->next;
						tmp->next->prev = tmp->prev;
						delete tmp;
						tam--;
						return i;
					}
				}
				else {
					tmp->prev->next = nullptr;
					delete tmp;
					tam--;
					return i;
				}
				tmp = tmp->next;
				i++;
			}
		}
	}
	return -1;
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
	if (pos1 < tam && pos2 < tam) {
		if (pos1 != pos2) {
			Nodo* nodo1;
			Nodo* nodo2;
			Nodo* aux = nullptr;
			if (pos1 < pos2) {
				nodo1 = getNodo(pos1);
				nodo2 = getNodo(pos2);
			}
			else {
				nodo1 = getNodo(pos2);
				nodo2 = getNodo(pos1);
			}

			if (nodo1->next == nodo2) {
				if (nodo1->prev) nodo1->prev->next = nodo2;
				if (nodo2->prev) nodo2->prev->next = nodo1;
				nodo2->prev = nodo1->prev;
				nodo1->prev = nodo2;
				aux = nodo2->next;
				nodo2->next = nodo1;
				nodo1->next = aux;
				if (aux) aux->prev = nodo1;
				if(inicio == nodo1) inicio = nodo2;
			}
			else {
				if (nodo1->prev)nodo1->prev->next = nodo2;
				if (nodo2->prev)nodo2->prev->next = nodo1;
				if (nodo1->next)nodo1->next->prev = nodo2;
				if (nodo2->next)nodo2->next->prev = nodo1;
				aux = nodo1->prev;
				nodo1->prev = nodo2->prev;
				nodo2->prev = aux;
				aux = nodo1->next;
				nodo1->next = nodo2->next;
				nodo2->next = aux;
				if (inicio == nodo1) inicio = nodo2;
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