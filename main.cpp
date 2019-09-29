//main.cpp
//utores: Dafhnne Alfaro Cruz, Carlos Zhou Zheng, David Vargas
//Descripcion: main con datos de prueba comentados....Descomentar las para probar
//			   para probar las oruebas
#include <iostream>
#include <sstream>
using namespace std;
#include "Integer.h"

int main() {
	Integer* prueba = new Integer("-999999999999999999999999999999999999999999999999999999999999999999999999999999999");
	Integer* prueba2 = new Integer("100000000000000000000000000000000011100010100");
	Integer* prueba3 = new Integer("123456789101112131415161718192021222324252627282930");
	Integer* prueba4 = new Integer("-6763263743483856384654365843858324");
	Integer* prueba6 = new Integer("1234567891011121314151617181920");
	Integer* prueba7 = new Integer("732638359837459738945389579326");
	Integer* prueba8 = new Integer("1000");
	Integer* nuevo;//para operadores +,-,*,/

	//Prueba Constructor de copia y operador de asignacion
	Integer* prueba5= new Integer(*prueba);
	//cout << prueba5->toString()<<"\n\n";
	//cout << "DATOS DE prueba4\n";
	//cout << prueba4->toString()<<"\n\n";
	//cout << "DATOS DE prueba4 despues de = \n";
	*prueba4 = (*prueba);//asignacion
	//cout << prueba4->toString() << "\n\n";
	//system("pause");
	//system("cls");

	/*************************************************************************************/
	//DISTINTO
	cout << "\n\n\n-------------------------------------------------------------";
	cout << "\n-                     DISTINTOS                             -";
	cout << "\n-------------------------------------------------------------\n\n";
	if(*prueba!=*prueba2)
		cout << prueba->toString() << "\nES DISTINTO DE\n" << prueba2->toString()<<"\n\n";
	else
		cout << prueba->toString() << "\nNO ES DISTINTO DE\n" << prueba2->toString()\n\n;
	system("pause");
	system("cls");

	*************************************************************************************/
	//IGUAL
	cout << "\n\n\n-------------------------------------------------------------";
	cout << "\n-                     IGUALES                               -";
	cout << "\n-------------------------------------------------------------\n\n";
	if (*prueba4 == *prueba)
		cout << prueba4->toString() << "\nES IGUAL A\n" << prueba->toString()<<"\n\n";
	else
		cout << prueba4->toString() << "\nNO ES IGUAL A\n" << prueba->toString()<<"\n\n";
	system("pause");
	system("cls");

	/*************************************************************************************/
	///MENOR con positivos
	cout << "\n\n\n-------------------------------------------------------------";
	cout << "\n-                     MENOR                                 -";
	cout << "\n-------------------------------------------------------------\n\n";
	if (*prueba < *prueba2)
		cout << prueba->toString() << "\nES MENOR A\n" << prueba2->toString() << "\n\n";
	else
		cout << prueba->toString() << "\nNO ES MENOR A\n" << prueba2->toString()<<"\n\n";
	system("pause");
	system("cls");

	/*************************************************************************************/
	///MENOR IGUAL con positivos
	cout << "\n\n\n-------------------------------------------------------------";
	cout << "\n-                     MENOR IGUAL                             -";
	cout << "\n-------------------------------------------------------------\n\n";
	if (*prueba <= * prueba2)
		cout << prueba->toString() << "\nES MENOR IGUAL A\n" << prueba2->toString() << "\n\n";
	else
		cout << prueba->toString() << "\nNO ES MENOR IGUAL A\n" << prueba2->toString()<<"\n\n";
	system("pause");
	system("cls");

	/*************************************************************************************/
	///Mayor
	cout << "\n\n\n-------------------------------------------------------------";
	cout << "\n-                     MAYOR                                 -";
	cout << "\n-------------------------------------------------------------\n\n";
	if (*prueba > *prueba2)
		cout << prueba->toString() << "\nES MAYOR A\n" << prueba2->toString() << "\n\n";
	else
		cout << prueba->toString() << "\nNO ES MAYOR A\n" << prueba2->toString() << "\n\n";
	system("pause");
	system("cls");

	/*************************************************************************************/
	///MAYOR IGUAL 
	cout << "\n\n\n-------------------------------------------------------------";
	cout << "\n-                     MAYOR IGUAL                             -";
	cout << "\n-------------------------------------------------------------\n\n";
	if (*prueba >= * prueba2)
		cout << prueba->toString() << "\nES MAYOR IGUAL A\n" << prueba2->toString() << "\n\n";
	else
		cout << prueba->toString() << "\nNO ES MAYOR IGUAL A\n" << prueba2->toString() << "\n\n";
	system("pause");
	system("cls");

	/*************************************************************************************/
	//SUMA solo positivos
	cout << "\n\n\n-------------------------------------------------------------";
	cout << "\n-                     SUMA                                -";
	cout << "\n-------------------------------------------------------------\n\n";
	nuevo = new Integer((*prueba + *prueba2));
	cout << "LA SUMA DE " << prueba->toString() << " Y " << prueba2->toString() << " es: \n";
	cout << nuevo->toString() << endl;
	delete nuevo;
	nuevo = NULL;
	system("pause");
	system("cls");

	/*************************************************************************************/
	//RESTA 
	cout << "\n\n\n-------------------------------------------------------------";
	cout << "\n-                      RESTA                               -";
	cout << "\n-------------------------------------------------------------\n\n";
	nuevo = new Integer((*prueba - *prueba2));
	cout << "LA RESTA DE " << prueba->toString() << " Y " << prueba2->toString() << " es: \n";
	cout << nuevo->toString() << endl;
	delete nuevo;
	nuevo = NULL;
	system("pause");
	system("cls");

	/*************************************************************************************/
	//MULTIPLICACION 
	cout << "\n\n\n-------------------------------------------------------------";
	cout << "\n-                      MULTIPLICACION                       -";
	cout << "\n-------------------------------------------------------------\n\n";
	nuevo = new Integer((*prueba6 * *prueba7));
	cout << "LA MULTIPLICACION DE " << prueba6->toString() << " POR " << prueba7->toString() << " es: \n";
	cout << nuevo->toString() << endl;
	delete nuevo;
	nuevo = NULL;
	system("pause");
	system("cls");

	/*************************************************************************************/
	//DIVISION 
	cout << "\n\n\n-------------------------------------------------------------";
	cout << "\n-                        DIVISION                            -";
	cout << "\n-------------------------------------------------------------\n\n";
	nuevo = new Integer((*prueba6 / *prueba7));
	cout << "LA DIVISON DE " << prueba6->toString() << " ENTRE " << prueba7->toString() << " es: \n";
	cout << nuevo->toString() << endl;
	delete nuevo;
	nuevo = NULL;
	system("pause");
	system("cls");

	/*OPERACIONES DE PRUEBAS*/

	//FACTORIAL
	//cout << "\n\n\n-------------------------------------------------------------";
	//cout << "\n-                 FACTORIAL DE 1000                        -";
	//cout << "\n-------------------------------------------------------------\n\n";
	//nuevo = new Integer(prueba->factorial(*prueba8));
	//cout << nuevo->toString() << endl;
	//delete nuevo;
	//nuevo = NULL;
	//system("pause");
	//system("cls");

	//FIBONACCI
	//cout << "\n\n\n-------------------------------------------------------------";
	//cout << "\n-                 FIBONACCI DE 1000                        -";
	//cout << "\n-------------------------------------------------------------\n\n";
	//nuevo = new Integer(prueba->fibonacci(*prueba8));
	//cout << nuevo->toString() << endl;
	//delete nuevo;
	//nuevo = NULL;
	//system("pause");
	//system("cls");


	//Combinatoria, tarda mucho con numeros grandes
	//cout << "\n\n\n-------------------------------------------------------------";
	//cout << "\n-                 Combinatoria DE 1000                        -";
	//cout << "\n-------------------------------------------------------------\n\n";
	//Integer nuevo = prueba->Combinatoria(*prueba, *prueba2);	
	//cout << nuevo->toString() << endl;
	//delete nuevo;
	//nuevo = NULL;
	//system("pause");
	//system("cls");



	delete prueba;
	delete prueba2;
	delete prueba3;
	delete prueba4;
	delete prueba5;
	delete prueba6;
	delete prueba7;
	delete prueba8;

}
