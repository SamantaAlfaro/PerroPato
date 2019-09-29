//Vector.h
//Autores: Dafhnne Alfaro Cruz, Carlos Zhou Zheng, David Vargas
//Descripcion: Definicion de la clase vector con un arreglo estatico para almacenar un maximo
//			   de 27 digitos (9 digitos por celda)
#ifndef VECTOR
#define VECTOR
#define SIZE 3

#include <iostream>
#include <sstream>
using namespace std;

class Vector {
private:
	int cant;
	int vect[SIZE];

public:
	Vector();
	~Vector();
	void insertar(int numero);
	int getNumero(int i);
	void setNumero(int pos, int val);
	string toString();
	int getCantidad();
	string completar(string n);
};
ostream& operator << (ostream&, Vector&);

#endif // !VECTOR