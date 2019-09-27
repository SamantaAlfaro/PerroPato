#include <iostream>
#include <sstream>
using namespace std;
#include "Integer.h"
#include "Lista_Doble.h"
#include "Vector.h"

int main() {
	Integer* prueba = new Integer("349823492494");
	Integer* prueba2 = new Integer("1");
	Integer* prueba3 = new Integer("343464564564564654645");
	
	//Integer nuevo = (*prueba)/(*prueba2);
	//Integer nuevo = (*prueba2)+(*prueba);
	//cout << nuevo.toString()<<endl;
	//nuevo += *prueba;
	cout << prueba2->toString();
	
	/*if (*prueba2 <= *prueba)
		cout << "good";
	else
		cout << "nel";*/
	//cout << prueba3->toString() << endl;
	//cout << prueba2->toString();

	//if (*prueba2 == *prueba) {
	//	cout << "\nyei";
	//}
	//else 
	//	cout << "\nnel :c";
	//if (*prueba2 < *prueba){//
	//	cout << ":#";
	//}
	//else {
	//	cout << "no es el menor";//
	//}
	
	//1000000000000000000
	//658365 834683 294734 673463 <- head0
	//	109238 456789 - 123
	//cout << prueba->toString() << endl;
	//cout << prueba2->toString();
	delete prueba;
	delete prueba2;
	delete prueba3;
	cout << endl << endl << endl;
	system("pause");
}
