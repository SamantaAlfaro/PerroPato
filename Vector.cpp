#include "Vector.h"



Vector::Vector() {
	cant = 0;
	for (int i = 0; i < SIZE; i++) {
		vect[i] = -1;
	}
}


Vector::~Vector() {	}


void Vector::insertar(int numero) {
	vect[cant++] = numero;
}


int Vector::getNumero(int i) {
	return vect[i];
}

void Vector::setNumero(int pos, int val){
	vect[pos] = val;
}

string Vector::toString() {
	stringstream s;
	for (int i = cant-1; i >= 0; i--) {
		/*if (vect[i] == 0) {
			s<<completar(to_string(vect[i]));
		}
		else*/
		s << completar(to_string(vect[i]));
			//s << vect[i];
	}
	return s.str();
}

int Vector::getCantidad(){
	return cant;
}

ostream & operator<<(ostream & salida,  Vector &d){
	salida << d.toString();
	return salida;
}

string Vector::completar(string n){//para completar los 0 a la izq
	if (n.length() < 9) {//si el tamaño no es 0
		
		for (int i = 0; i < n.length() - 9; i++) {
			//if (n.size() % 9 != 0) {//si no lo ha comletado (no tiene los 9 digitos)
				n = "0" + n;
			//}
			//else { break; }
		}
	}
	return n;
}