#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H


#include <iostream>
#include <sstream>
using namespace std;

template <class T>
struct NodoDoble {
	T* object;
	NodoDoble<T>* previous;
	NodoDoble<T>* next;
};

template <class T>
class ListaDobleEnlazada {
private:
	NodoDoble<T>* start;
	NodoDoble<T>* end;
	int tam;
public:
	ListaDobleEnlazada();
	virtual ~ListaDobleEnlazada();
	virtual bool InsertElement(T*);
	virtual bool Empty();
	//virtual bool Errase_Element(T);
	//virtual T* Search_Element(T*);
	virtual string Show();
	virtual string ShowInvertedList();//ver la lista invertida
	virtual int getTam();
	virtual NodoDoble<T>* getHead();
	virtual NodoDoble<T>* getEnd();
};//fin lista doblemente enlazada
template <class T>
NodoDoble<T>* ListaDobleEnlazada<T>::getEnd() {
	return end;
}

template <class T>
NodoDoble<T>* ListaDobleEnlazada<T>::getHead() {
	return start;
}

template <class T>
int ListaDobleEnlazada<T>::getTam() {
	return tam;
}

template <class T>
ListaDobleEnlazada<T>::ListaDobleEnlazada() {
	start = NULL;
	tam = 0;
}

template <class T>
ListaDobleEnlazada<T>::~ListaDobleEnlazada() {
	NodoDoble<T>* tmp;
	while (start != NULL) {
		tmp = start;
		start = start->next;
		delete tmp;
	}
	tam = 0;
}

template <class T>
bool ListaDobleEnlazada<T>::InsertElement(T* item) {
	NodoDoble<T>* actual;
	try {
		actual = new NodoDoble<T>;
	}
	catch (std::bad_alloc exception) {
		return false;
	}

	actual->object = item;     // Guardamos el valor en el nodo
	actual->next = NULL;   // El puntero siguiente apuntaría a NULL
	actual->previous = NULL;//puntero previo apunte a null

	//1.Si la lista está vacía, el nodo creado se convierte en el primer elemento
	if (start == NULL) {
		this->start = actual;
		this->end = actual;
		++tam;
		return true;
	}
	else {// Si ya existen elementos en la lista, insertarlo al final
		NodoDoble<T>* tmp = start;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = actual;   // El último nodo apunta al nodo nuevo
		end = actual;
		actual->previous = tmp;   // Apuntamos al nodo anterior
		++tam;
		return true;
	}
}//fin InsertElement

template <class T>
bool ListaDobleEnlazada<T>::Empty() {
	return (!start);
}//si está null

//template <class T>
//bool ListaDobleEnlazada<T>::Errase_Element(T item) {
//	if (Empty())
//		return false;
//	// Caso #2: Si el elemento a borrar es el primer nodo de la lista
//	NodoDoble<T>* tmp;
//	tmp = start;
//	if (*(start->object) == item) {
//		start = start->next;
//		start->previous = NULL;
//		--tam;
//		delete tmp;
//		return true;
//	}
//
//	// Caso #3: Si el elemento a borrar es cualquier otro nodo distinto del primero
//	NodoDoble<T>* tmp2;
//	tmp2 = tmp->next;
//	while (tmp2 != NULL) {
//		if (*(tmp2->object) == item) {
//			tmp->next = tmp2->next;
//			tmp2->next->previous = tmp;
//			delete tmp2;
//			--tam;
//			return item;
//		}
//		tmp = tmp2;
//		tmp2 = tmp2->next;
//	}
//	return false;//no lo encontró
//}//fin errase_element

//template <class T>
//T* ListaDobleEnlazada<T>::Search_Element(T* item) {//retorna la direccion en donde esta el objeto
//	if (!start)
//		return NULL;//lista vacia
//	NodoDoble<T>* tmp = start;
//	while (tmp) {
//		if (*(tmp->object) == *item)
//			return (tmp->object);
//		tmp = tmp->next;
//	}
//	return NULL;//si no encontró nada
//}

template <class T>
string ListaDobleEnlazada<T>::Show() {
	stringstream aux;
	if (!start)
		aux << "EMPTY LIST :c\n\n";
	else {
		aux << "LIST OF ELEMENTS\n";
		NodoDoble<T>* tmp = start;
		while (tmp) {
			aux << *(tmp->object);
			tmp = tmp->next;
		}
		aux << "\nList size:" << tam;
	}//fin else
	return aux.str();
}//fin del mostrar

template <class T>
string ListaDobleEnlazada<T>::ShowInvertedList() {
	stringstream aux;
	if (!start) //lista vacia
		aux << "\nEMPTY LIST :c ...\n";
	else {
		NodoDoble<T>* tmp = end;
		while (tmp != NULL) {
			aux << *(tmp->object);
			tmp = tmp->previous;
		}
	}
	return aux.str();
}//fin lista Invertida

#endif // !LISTA_SIMPLE_H
