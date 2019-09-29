//Integer.h
//utores: Dafhnne Alfaro Cruz, Carlos Zhou Zheng, David Vargas
//Descripcion: clase princial con sobrecargas de operadores para realizar calculos con 
//			   numeros de orden arbitrario
#ifndef INTEGER_H
#define INTEGER_H
#include <string>
using namespace std;

#include "Vector.h"
#include "Lista_Doble.h"
#include "Utiles.h"

class Integer {
private:
	ListaDobleEnlazada<Vector>* list;//va a ser mi numero enooorme
	bool negative;
public:
	Integer();//sin parametros
	Integer(const Integer&);//constructor copia
	Integer(string);
	Integer& operator =(Integer&);//sobrecarga del operador de asignacion
	~Integer();
	bool getNegative();
	void setNegative(bool negative);
	ListaDobleEnlazada<Vector>* getList();

	//Funciones para convertir una cadena de caracteres a un Integer
	void parse(string);//pasa de string a Integer
	void Agregar(string num);
	void AgregarVerdadero(string num);//llama al parse(string)
	string toString();

	/*Operador Suma y metodos a usar*/
	Integer& operator +(Integer&);
	void operator +=(Integer&);
	Integer& Sumar_Nodos(Integer*);
	int Sumar_Vectores(Vector*, Vector*, Integer&, int);
	int Sumar_Vector_Extra(Vector*, int, Integer&);

	/*Operador Resta & Resta= con metodo a usar*/
	Integer& operator -(Integer&);
	void operator -=(Integer&);
	Integer& Resta(Integer& num2);

	/*Operador Multiplicacion y metodos a usar*/
	Integer& operator *(Integer&);
	void operator *=(Integer&);
	Integer& Multiplicacion(Integer*);
	

	/*Operador Division & Division= con metodos a usar*/
	Integer& operator /(Integer&);
	void operator /=(Integer&);
	Integer& dividir(Integer&);

	/*Comparativas*/
	bool operator ==(Integer&) ;	
	bool operator !=(Integer&);
	bool operator <(Integer&);
	bool operator <=(Integer&);
	bool operator >(Integer&);
	bool operator >=(Integer&);

	/*Metodos para comparar == y menores*/
	bool Comparar_Nodo(Integer*); //Recorre la lista
	bool Comparar_Vectores(Vector* v1, Vector* v2); //Recorre el vector
	bool Comparar_Nodos_Menor(Integer*);
	bool Comparar_Vectores_Menor(Vector*, Vector*);
	/*estos estan mientras tanto*/
	bool CompararConString(Integer&);
	bool CompararMenorConString(Integer&);

	//Funciones a implementar
	Integer& factorial(Integer&);
	Integer& fibonacci(Integer&);
	Integer& Combinatoria(Integer&, Integer&);
};
#endif // !INTEGER_H