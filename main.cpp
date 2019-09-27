#include <iostream>
#include <sstream>
using namespace std;
#include "Integer.h"
#include "Lista_Doble.h"
#include "Vector.h"

int main() {
	Integer* prueba = new Integer("1000");
	Integer* prueba2 = new Integer("2");

	Integer nuevo = prueba->fibonacci(*prueba);
	//Integer nuevo = (*prueba)/(*prueba2);
	cout << nuevo.toString()<<endl;
	//nuevo += *prueba;

	//(*prueba2) *= (*prueba);
	//cout << prueba2->toString();

	delete prueba;
	delete prueba2;
	cout << endl << endl << endl;
	system("pause");
}
