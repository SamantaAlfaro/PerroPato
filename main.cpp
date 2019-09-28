#include <iostream>
#include <sstream>
using namespace std;
#include "Integer.h"
#include "Lista_Doble.h"
#include "Vector.h"

int main() {
	Integer* prueba = new Integer("1000000000000000000000000000000000000000000000000000000000000000000000");
	Integer* prueba2 = new Integer("1000000000000000000000000000000000000000000000000000000000000000001");

	//Integer nuevo = (*prueba)-(*prueba2);
	//Integer nuevo = (*prueba)/(*prueba2);
	//cout << nuevo.toString()<<endl;
	//nuevo += *prueba;

	//(*prueba2) *= (*prueba);
	//cout << prueba2->toString();
	if (*prueba < *prueba2) {
		cout << "good";
	}
	else
		cout << "Fx1000";




	delete prueba;
	delete prueba2;
	cout << endl << endl << endl;
	system("pause");
}
