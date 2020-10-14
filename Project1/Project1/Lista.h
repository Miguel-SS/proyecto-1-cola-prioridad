#pragma once
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class Lista {
private:
	template <class T>
	struct Nodo {
		T* value;
		struct Nodo<T>* next;
		struct Nodo<T>* prev;
		Nodo(T* v, Nodo<T>* p = nullptr, Nodo<T>* n = nullptr)
			: value{ v }, prev{ p }, next{ n } {}
	};
	Nodo<T>* inicio;
	int tam;

public:
	typedef Nodo<T>* iterador;


	Lista();
	Lista(const Lista<T>&);
	~Lista();
	void insertarFinal(T*);
	int eliminar(T*);
	void eliminarPrimero();
	void borrarLista();
	bool isVacia();
	void intercambiaNodos(int, int);

	T* getValores(int);

	Nodo<T>* getNodo(int);
	Nodo<T>* getInicio();
	int getTam();

	std::string toString();

	//Lista* operator=(Lista*);

};


template<class T>
Lista<T>::Lista()
{
	inicio = nullptr;
	tam = 0;
}

// Constructor copia
template <class T>
Lista<T>::Lista(const Lista& obj)
{
	if (obj.inicio == nullptr) { inicio = nullptr; tam = 0; }
	else {

		// ????? se debe borrar algo?
		inicio = new Nodo<T>(obj.inicio->value);
		iterador tmp = inicio;
		iterador tmp_obj = obj.inicio->next;
		while (tmp_obj != nullptr) {
			tmp->next = new Nodo<T>(tmp_obj->value, tmp);
			tmp = tmp->next;
			tmp_obj = tmp_obj->next;
		}
		tam = obj.tam;
	}
}

template<class T>
Lista<T>::~Lista()
{
	borrarLista();
}

// Inserta un elemento n al final de la lista
template <class T>
void Lista<T>::insertarFinal(T* n)
{
	Nodo<T>* nuevo = new Nodo<T>(n);
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
// Retorna la posicion
template <class T>
int Lista<T>::eliminar(T* n)
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

template <class T>
void Lista<T>::eliminarPrimero()
{
	if (!isVacia()) {
		Nodo<T>* aux = inicio;
		inicio = inicio->next;
		delete aux;
		tam--;
	}
}

// Borra todos los nodos de la lista
template <class T>
void Lista<T>::borrarLista() { while (!isVacia()) { eliminarPrimero(); } }

// Verifica si la lista está vacia
template <class T>
bool Lista<T>::isVacia() { return (inicio != nullptr) ? false : true; }

template <class T>
void Lista<T>::intercambiaNodos(int pos1, int pos2)
{
	if (pos1 < tam && pos2 < tam) {
		if (pos1 != pos2) {
			Nodo<T>* nodo1;
			Nodo<T>* nodo2;
			Nodo<T>* aux = nullptr;
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
				if (inicio == nodo1) inicio = nodo2;
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
				// if (aux) aux->prev = nodo2;
				if (inicio == nodo1) inicio = nodo2;
			}
		}
	}
}

template <class T>
T* Lista<T>::getValores(int x)
{
	if (this->getInicio()->value == NULL) {
		return NULL;
	}
	return this->getNodo(x)->value;
}

template <class T>
Lista<T>::Nodo<T>* Lista<T>::getNodo(int pos)
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

template <class T>
Lista<T>::Nodo<T>* Lista<T>::getInicio() { return inicio; }

template <class T>
int Lista<T>::getTam() { return tam; }

// Devuelve los datos en forma de cadena
template <class T>
std::string Lista<T>::toString()
{
	std::stringstream s;
	if (!isVacia()) {
		iterador tmp = inicio;
		while (tmp != nullptr) {
			s << *tmp->value << std::endl;
			tmp = tmp->next;
		}
		s << std::endl;
	}
	else {
		s << "Lista vacia" << std::endl;
	}
	return s.str();
}

/*Lista* Lista::operator=(Lista* nuevo)
{

	if (this != nuevo) {

		borrarLista();

		inicio = nuevo->inicio;

		while (nuevo->inicio->next->next == NULL) {

			inicio->prev = nuevo->inicio->prev;
			inicio->next = nuevo->inicio->next;


			inicio = inicio->next;
			nuevo->inicio = nuevo->inicio->next;
		}

	}
	return this;


}*/