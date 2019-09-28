#ifndef INTEGER
#define INTEGER
#define ZERO 0
#define UNO 1
#include <string>
using namespace std;

#include "Vector.h"
#include "Lista_Doble.h"


class Integer {
private:
	ListaDobleEnlazada<Vector>* list;//va a ser mi numero enooorme
	bool negative;
public:
	Integer();//sin parametros
	Integer(string);
	Integer(Integer&);//constructor copia
	Integer& operator = (Integer& int2);//sobrecarga del operador de asignacion
	~Integer();
	/*ayudas*/
	char intTochar(int n);//este lo ocupa
	int charToint(char n);//este lo ocupa
	Integer& multiplicacion(Integer*);//este lo ocupa

	bool getNegative();
	void setNegative(bool negative);
	ListaDobleEnlazada<Vector>* getList();
	void Agregar(string num);
	void AgregarVerdadero(string num);

	Integer& operator +(Integer&);//suma
	Integer& sumar_nodos(Integer*);
	int sumar_vectores(Vector *,Vector*,Integer&, int);
	int sumar_vector_extra(Vector*, int, Integer&);
	Integer& operator -(Integer&);//resta
	 
	Integer& operator *(Integer&);//multiplica
	Integer& operator /(Integer&);//division

	


	void operator +=(Integer&);//incremento
	void operator -=(Integer&);//decremento
	void operator *=(Integer&);//multiplicacion propia
	void operator /=(Integer&);//division propia


	bool operator ==(Integer&) ;//comparacion
	bool comparar_nodos(Integer*); //Recorre la lista
	bool comparar_vectores(Vector* v1, Vector* v2); //Recorre el vector

	bool operator !=(Integer&);//distinto
	bool operator <(Integer&);//menor
	bool comparar_nodos_menor(Integer*);
	bool comparar_vectores_menor(Vector*, Vector*);
	bool operator <=(Integer&);//menor igual
	bool operator >(Integer&);//mayor
	bool operator >=(Integer&);//mayor igual

	void parse(string);//pasa de string a Integer

	string toString();
	void quitarCeros(string &n);

	Integer& dividir(Integer& divisor);

	Integer& resta(Integer& num2);
	//Integer& factorialCola(Integer& uno, Integer &dos);
	//el verdadero
	Integer& factorial(Integer&);
	
	//siempre positivos
	Integer& fibonacci(Integer&);

	Integer& Combinatoria(Integer& uno, Integer& dos);

};
//ostream& operator << (ostream&, Integer&);



#endif // !INTEGER

