#include "Integer.h"

Integer::Integer() {
	this->list = new ListaDobleEnlazada<Vector>();
	negative = false;
}

Integer::Integer(const Integer& obj) {//constructor de copia, copio de uno lleno a uno vacio
	this->negative = obj.negative;
	this->list = new ListaDobleEnlazada<Vector>();
	NodoDoble<Vector>* aux2 = obj.list->getHead();//auxiliar para recorrer la segunda lista
	while (aux2 != NULL) {//ir recorriendo la segunda lista
		Vector* tmp = new Vector();//por cada nodo se hace un vector
		for (int i = 0; i < aux2->object->getCantidad(); i++) {//se llena hasta la cantidad de cada vector
			tmp->insertar(aux2->object->getNumero(i));
		}
		list->InsertElement(tmp);
		tmp = NULL;
		aux2 = aux2->next;
	}//fin del while
}

Integer& Integer::operator=(Integer& obj) {
	if (list != NULL) {//si mi lista esta llena, eliminela
		delete list;	}
	this->negative = obj.negative;
	this->list = new ListaDobleEnlazada<Vector>();
	NodoDoble<Vector>* aux2 = obj.list->getHead();
	while (aux2 != NULL) {
		Vector* tmp = new Vector();
		for (int i = 0; i < aux2->object->getCantidad(); i++) {
			tmp->insertar(aux2->object->getNumero(i));		}
		list->InsertElement(tmp);
		tmp = NULL;
		aux2 = aux2->next;
	}//fin del while
	return *this;
}

Integer::~Integer() {
	list->~ListaDobleEnlazada();
	negative = false;
	//delete list;	
}

bool Integer::getNegative() {
	return negative;	}

void Integer::setNegative(bool negative) {
	this->negative = negative;	}


ListaDobleEnlazada<Vector>* Integer::getList() {
	return list;	}

Integer::Integer(string valor) {
	this->list = new ListaDobleEnlazada<Vector>();
	negative = false;
	parse(valor);
}

void Integer::parse(string s) {
	this->Agregar(s);}

void Integer::Agregar(string num) {
	string num_aux = num;
	if (num_aux[0] == '-') {
		num_aux.erase(0, 1);
		negative = true;
	}
	AgregarVerdadero(num_aux);
}
void Integer::AgregarVerdadero(string num) {
	string num_auxiliar;
	Vector* aux = NULL;
	for (int i = num.size(); i >= 0; i -= 9) {
		if (aux == NULL)
			aux = new Vector(); //Cuando el auxiliar es nulo crea un nuevo vector

		if (i < 9 && aux->getCantidad() == 3) { //Por si lo que queda es menos de 6
			num_auxiliar = num.substr(0, i);
			aux->insertar(stoi(num_auxiliar));
		}
		else if (i <= 9) {
			num_auxiliar = num.substr(0, i);
			aux->insertar(stoi(num_auxiliar));
			list->InsertElement(aux);
			return;
		}
		else {
			num_auxiliar = num.substr(i - 9, 9);
			aux->insertar(stoi(num_auxiliar));
		}
		if (i - 9 == 0) {
			list->InsertElement(aux);
			aux = NULL;
			return;
		}
		else if (aux->getCantidad() == 3) { //cuando el vector se llena se borra ese y se añade a la lista
			list->InsertElement(aux);
			aux = NULL;
		}
	}
}

string Integer::toString() {
	string aux = list->ShowInvertedList();
	if (list->getTam() == 1 && list->getHead()->object->getCantidad() == 1 && list->getHead()->object->getNumero(0) == 0)
		aux = "0";
	else quitarCeros(aux);
	if (negative) 
		return "-" + aux;
	else 
		return aux;
}

/*SUMA*/
Integer& Integer::operator+(Integer& integer) {
	return Sumar_Nodos(&integer);	}

void Integer::operator+=(Integer& integer) {
	*this = Sumar_Nodos(&integer);	}

Integer& Integer::Sumar_Nodos(Integer* integer) {
	Integer* nuevo = new Integer();
	int i = 0, carry = 0;
	Integer* aux1_i, * aux2_i;//auxiliares integers
	NodoDoble<Vector>* aux;
	NodoDoble<Vector>* aux1;
	//Se recorrerá el integer que tenga mayor tamaño
	if (this->list->getTam() > integer->getList()->getTam()) {
		//se posiciona en los primeros digitos, los "menores"
		aux = this->list->getHead();
		aux1 = integer->getList()->getHead();
		aux1_i = this;
		aux2_i = integer;
	}
	else {//resulta que el de la izquierda es el menor y el de la derecha es mayor, recorrer el de la derecha
		aux = integer->getList()->getHead();
		aux1 = this->list->getHead();
		//se acomoda igual, el mayor arriba y el menor abajo
		aux1_i = integer;
		aux2_i = this;
	}
	while (aux != NULL) {
		//el contador me dice cuando ya se terminó la lista menor para seguir trabajando con la grande
		if (i < aux2_i->getList()->getTam()) {
			carry = Sumar_Vectores(aux->object, aux1->object, *nuevo, carry);
			aux1 = aux1->next; 
		}
		else //todavia quedan nodos con vectores arriba, seguir trabajando con esos y el acarreo
			carry = Sumar_Vector_Extra(aux->object, carry, *nuevo);
		aux = aux->next;
		i++;
	}
	if (carry != 0) {//ya al final de todo, y si todavia tiene carry, que lo agregue
		nuevo->Agregar(to_string(carry));
		carry = 0;
	}
	return *nuevo;
}

int Integer::Sumar_Vectores(Vector* v1, Vector* v2, Integer& nuevo, int carry) {//trabajar sobre el mismo integer
	int aux1, aux2, carry1 = carry;//el carry va a ser el mismo que traia
	long long int num;//para ir almacenando el numero y luego separarlo
	Vector* v_aux1;
	string numero = "";
	if (v1->getCantidad() > v2->getCantidad()) {
		aux1 = v1->getCantidad();
		aux2 = v2->getCantidad();
		v_aux1 = v1;//todo el vector de arriba
	}
	else {
		aux1 = v2->getCantidad();
		aux2 = v1->getCantidad();
		v_aux1 = v2;
	}
	for (int i = 0; i < aux1; i++) {
		if (aux2 > i) {
			num = v1->getNumero(i) + v2->getNumero(i) + carry1;//suma ambas posiciones de los vectores
			carry1 = num / 1000000000;//saca el primer digito, el carry
			num = num % 1000000000;//saca los 9 digitos limite a almacenar 
			if (num == 0)
				numero = "000000000" + numero;
			else
			numero = to_string(num) + numero;//pasa el numero a string
		}
		else {
			num = v_aux1->getNumero(i) + carry1;
			carry1 = num / 1000000000;
			num = num % 1000000000;
			if (num == 0)
				numero = "000000000" + numero;//para que agregue los 9 ceros
			else
				numero = to_string(num) + numero;//lo pasa a string
		}
	}
	nuevo.Agregar(numero);//agrega los valores al nuevo integer
	return carry1; //retorna el carry para que lo reciba de nuevo en el proximo nodo
}

int Integer::Sumar_Vector_Extra(Vector* v, int carry, Integer& integer) {
	int carry1 = carry;
	long long int num;
	string numero = "";
	for (int i = 0; i < v->getCantidad(); i++) {
		num = v->getNumero(i) + carry1;
		carry1 = num / 1000000000;
		num = num % 1000000000;
		numero = to_string(num) + numero;
	}
	integer.Agregar(numero);
	return carry1;
}


/*RESTA*/
Integer& Integer::operator-(Integer& integer) {
	return Resta(integer);	}

void Integer::operator-=(Integer& integer) {
	*this = Resta(integer);	}

Integer& Integer::Resta(Integer& num2){
	Integer* nuevo = new Integer();
	string str1;
	string str2;
	//resta 
	if (*this == num2 && ((!this->getNegative() && !num2.getNegative())
		|| (this->getNegative() && num2.getNegative()))) {
		nuevo->Agregar("-1");//aqui tiene que ser 0
		return *nuevo;
	}
	//negativos || positivos
	if (this->negative && num2.negative || !this->negative && !num2.negative) {//si ambos son negativos
		if (*this < num2) {//si el de la izquierda es el menor, entonces por dentro, el izq es el mayor en los negativos
			str2 = this->toString();//el menor
			str1 = num2.toString();//el mayor
			if (str1[0] == '-') //quitarles los -
				str1.erase(0, 1);
			if (str2[0] == '-') //quitarles los -
				str2.erase(0, 1);//quitarle el negativo	
			//darles vuelta cuando son ambos negativos
			if (this->negative && num2.negative) {//si ambos son positivos, el resultado es negativo
				swap(str1, str2);
				nuevo->setNegative(true);
			}
			if (!this->negative && !num2.negative) {//si ambos son positivos, el resultado es negativo
				nuevo->setNegative(true);
			}
		}
		else {//siempre el mayor queda arriba
			str1 = this->toString();
			str2 = num2.toString();
			if (str1[0] == '-') //quitarles los -
				str1.erase(0, 1);
			if (str2[0] == '-') //quitarles los -
				str2.erase(0, 1);//quitarle el negativo	
			if (this->negative && num2.negative) {//si ambos son positivos, el resultado es negativo
				swap(str1, str2);
			}
		}
	}
	//si son de signos diferentes, suma
	if (this->negative && !num2.negative || !this->negative && num2.negative) {
		//la suma ya acomoda al mayor y al menor
		if (this->negative && !num2.negative) {//-&+ = resultado -
			nuevo->setNegative(true);
		}
		*nuevo = this->Sumar_Nodos(&num2);
		return *nuevo;
	}
	
	string str = "";
	int n1 = str1.length(), n2 = str2.length();
	//Le da vuelta al numero, 123--->321
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	int carry = 0;
	//recorre con el menor valor
	for (int i = 0; i < n2; i++){
		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry); 
		//resultado negativo --> se añade un 10 el acarreo se vuelve 1
		if (sub < 0){
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;
		str.push_back(sub + '0');
	}
	//continua con los restantes del numero mayor
	for (int i = n2; i < n1; i++)	{
		int sub = ((str1[i] - '0') - carry);
		//si el valor es negativo, lo hace positivo
		if (sub < 0){
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;
		str.push_back(sub + '0');
	}
	//invierte el resultado final.....321-->123
	reverse(str.begin(), str.end());
	nuevo->Agregar(str);
	return *nuevo;
}

/*MULTIPLICACION*/
Integer& Integer::operator*(Integer& I2) {
	return Multiplicacion(&I2);	}

void Integer::operator*=(Integer& integer) {
	*this = Multiplicacion(&integer);	}

Integer& Integer::Multiplicacion(Integer* numero) {
	Integer* nuevo = new Integer();
	int numero_aux1 = 0;
	int numero_aux2 = 0;
	string aux_numero1 = this->toString();
	string aux_numero2 = numero->toString();
	string aux_resultado(aux_numero1.length() + aux_numero2.length(), 0);//maximo tamaño del resultado, y lo llena con 0
	//si alguno es 0, de una vez retorna 0
	if (aux_numero1.length() == 0 || aux_numero2.length() == 0) {
		nuevo->Agregar("0");
		return *nuevo;
	}
	for (int i = aux_numero1.length() - 1; i >= 0; i--) { //recorre de derecha izquierda el vector 1 
		int carry = 0;
		int numero1 = aux_numero1[i] - '0';
		numero_aux2 = 0;
		for (int j = aux_numero2.length() - 1; j >= 0; j--) {
			int numero2 = aux_numero2[j] - '0';
			int suma = numero1 * numero2 + (charToint(aux_resultado[numero_aux1 + numero_aux2])) + carry;
			carry = suma / 10;
			aux_resultado[numero_aux1 + numero_aux2] = intTochar(suma % 10);
			numero_aux2++;
		}
		if (carry > 0) {
			aux_resultado[numero_aux1 + numero_aux2] += intTochar(carry);
		}
		numero_aux1++;
	}
	int i = aux_resultado.size() - 1;
	while (i >= 0 && aux_resultado[i] == 0){
		i--;
	}
	if (i == -1) {
		nuevo->Agregar("0");
		return *nuevo;
	}
	string s = "";
	while (i >= 0) {//para darle vuelta
		s += (aux_resultado[i--]);
	}
	nuevo->Agregar(s);
	return *nuevo;
}

/*DIVISION*/
Integer& Integer::operator/(Integer& num) {
	return dividir(num);	}

void Integer::operator/=(Integer& integer) {
	*this = dividir(integer);	}

Integer& Integer::dividir(Integer& divisor) {
	Integer* aux1 = new Integer(this->toString());
	Integer aux(divisor.toString());
	Integer* contador = new Integer("0");
	Integer *help;
	Integer uno("1");
	while (aux <= *aux1) {//mientras el divisor sea menor al numero si puede dividir
		help = new Integer((*aux1 - aux));
		string s = help->toString();
		*aux1 = *new Integer(s);
		*contador += uno;
	}
	delete aux1;
	return *contador;
}

/*COMPARATIVAS*/
bool Integer::operator==(Integer& i1) {
	//return Comparar_Nodo(&i1);
	return CompararConString(i1);
}
bool Integer::operator!=(Integer& i1) {
	//return !Comparar_Nodo(&i1);
	return !CompararConString(i1);
}

bool Integer::operator<(Integer& i1) {
	//if (Comparar_Nodo(&i1)) // si son iguales, entonces no son menores
	//	return false;	
	//else //compara a ver si son mayores o menores
	//	return !Comparar_Nodos_Menor(&i1);	
	if (CompararConString(i1))
		return false;
	else return CompararMenorConString(i1);
}
bool Integer::operator<=(Integer& i1) {
	//if (Comparar_Nodo(&i1))
	//	return true;
	//else//compara a ver si son mayores o menores
	//	return !Comparar_Nodos_Menor(&i1);

	//pruebas con strings
	if (CompararConString(i1))
		return true;
	else if (CompararMenorConString(i1))
		return true;
	else return false;
}

bool Integer::operator>(Integer& i) {
	/*if (Comparar_Nodo(&i))
		return false;
	else if (Comparar_Nodos_Menor(&i))
		return true;
	else return false;*/

	//CON STRINGS
	if(CompararConString(i))
		return false;
	if (!CompararMenorConString(i))
		return true;
	else return false;

}

bool Integer::operator>=(Integer& i1) {
	/*if (Comparar_Nodo(&i1))
		return true;
	else if (Comparar_Nodos_Menor(&i1))
		return true;
	else return false;*/
	if (CompararConString(i1))
		return true;
	else return !CompararMenorConString(i1);
		//return false;
}

//recorre los nodos para comparar sus vectores, si son == o !=
bool Integer::Comparar_Nodo(Integer* integer) {
	if (this->list->getTam() != integer->getList()->getTam()) //si los tamaños son distintos, de una vez no son iguales
		return false;
	//ir comparando los vectores de cada nodo, desde los ultimos numeros de integer
	NodoDoble<Vector>* aux = this->list->getHead();
	NodoDoble<Vector>* aux1 = integer->getList()->getHead();
	while (aux != NULL) {
		if (!Comparar_Vectores(aux->object, aux1->object))//si los contenidos de los arreglos no son iguales
			return false;
		aux = aux->next;
		aux1 = aux1->next;
	}
	return true;//al final de todo, son iguales 
}

bool Integer::Comparar_Vectores(Vector* v1, Vector* v2) {
	if (v1->getCantidad() != v2->getCantidad()) 
		return false;	
	//ir comparando los contenidos de los vectores
	for (int i = 0; i < v1->getCantidad(); i++) {
		if (v1->getNumero(i) != v2->getNumero(i)) //apenas sean distintos, se sale
			return false;		
	}
	return true;//al final de todo, si son iguales los vectores
}

//i1 < i2
bool Integer::Comparar_Nodos_Menor(Integer* integer) {
	//Si los 2 son negativos 
	if (this->negative && integer->getNegative()) {
		if (this->list->getTam() > integer->getList()->getTam()) 
			return false;
	
		//si tiene menos nodos, es el menor
		else if (this->list->getTam() < integer->getList()->getTam())
			return true;
	
		//si son del mismo tamaño
		NodoDoble<Vector>* aux = this->list->getEnd();
		NodoDoble<Vector>* aux1 = integer->getList()->getEnd();
		while (aux != NULL) {
			if (Comparar_Vectores_Menor(aux->object, aux1->object)) {
				return true;
			}
			aux = aux->previous;
			aux1 = aux1->previous;
		}
		return false;
	}

	//S EL IZQUIERDO EN NEGATIVO Y EL DERECHO POSITIVO
	if (this->negative && !integer->getNegative()) 
		return false;
	
	//SI EL IZQUIERDO ES POSITIVO Y EL DERECHO NEGATIVO
	if (!this->negative && integer->getNegative()) 
		return true;
	
	//Compara tam de la lista, si tiene mas nodos, entonces no es el menor
	if (this->list->getTam() > integer->getList()->getTam()) 
		return true;//era false
	//si tiene menos nodos, es el menor
	else if (this->list->getTam() < integer->getList()->getTam()) 
		return false;

	//SI AMBOS SON POSITIVOS
	NodoDoble<Vector>* aux = this->list->getEnd();
	NodoDoble<Vector>* aux1 = integer->getList()->getEnd();
	while (aux != NULL) {
		if (Comparar_Vectores_Menor(aux->object, aux1->object))//esta negado ya que va a devolver false apenas haya un mayor
			return false;//esto es false
		aux = aux->previous;
		aux1 = aux1->previous;
	}
	return true;//era true
}

//IR COMPARANDO VECTORES DE LOS NODOS
bool Integer::Comparar_Vectores_Menor(Vector* v1, Vector* v2) {
	//si el de la izq tiene mas numeros que el de la derecha, ya no es el menor
	if (v1->getCantidad() > v2->getCantidad())
		return false;

	//si le de la izq tiene menos numeros que el de la derecha, entonces si es el menor
	else if (v1->getCantidad() < v2->getCantidad()) 
		return true;
	//ir comparando los numeros de los vectores, pero inverso, desde los primeros digitos del numero...del vector empieza desde atras
	for (int i = v1->getCantidad() - 1; i >= 0; i--) {
		int num1 = v1->getNumero(i);
		int num2 = v2->getNumero(i);
		//ir comparando los digitos
		if (v1->getNumero(i) > v2->getNumero(i))
			return false;
		if (v1->getNumero(i) < v2->getNumero(i))
			return true;
	}//fin del for
	return false;//antes era true
}

/*FUNCIONES A IMPLEMENTAR*/
Integer& Integer::factorial(Integer& num) {
	Integer* nuevo = new Integer("1");//empieza con 1							  
	Integer i("1");
	Integer contador("1");
	while (i <= num) {
		(*nuevo) *= i;
		i += contador;
	}
	return *nuevo;
}

Integer& Integer::fibonacci(Integer& num) {
	Integer aux1("0");
	Integer aux2("1");
	Integer sig, primero("0"), segundo("1");
	for (aux1; aux1 < num; aux1 += aux2) {
		if (aux1 < aux2)// < 1
			sig = aux1;
		else {
			sig = primero + segundo;
			primero = segundo;
			segundo = sig;
		}
	}
	Integer* nuevo = new Integer(sig);
	return *nuevo;
}

Integer& Integer::Combinatoria(Integer& uno, Integer& dos) {//dura mucho
	Integer* nuevo = new Integer();
	Integer aux1(uno);
	Integer aux2(dos);
	*nuevo = (factorial(aux1) / (factorial(aux2) * factorial(aux1 - aux2)));//formula
	return *nuevo;
}


/*OTRAS FUNCIONES*/

bool Integer::CompararConString(Integer& integer){
	string num1 = this->toString();
	string num2 = integer.toString();
	if (num1!=num2) 
		return false;
	else return true;
}

bool Integer::CompararMenorConString(Integer& num2){
	string uno = this->toString();
	string dos = num2.toString();
	if (this->negative && num2.negative) {//ambos negativos
		//les quito los negativos
		uno.erase(0, 1);
		dos.erase(0, 1);
		if (uno.length() == dos.length()) {//si tienen la misma cantidad de digitos....... -123<-100 porque 123>100
			if (uno > dos)
				return true;
			else return false;
		}
		if (uno.length() > dos.length()) //-123<-1  porque 123>1
			return true;//si es el menor
		else return false;//no es el menor
	}//si son menores

	if (this->negative && !num2.negative) {//-&+
		return true;//el de la izquierda es el menor por ser negativo
	}
	if (!this->negative && num2.negative) {//+&-
		return false;//el de la derecha es el mayor
	}
	if (!this->negative && !num2.negative) {//+&+
		if (uno.length() == dos.length()) {//si tienen la misma cantidad de de digitos
			if (uno < dos)
				return true;
			else return false;
		}
		if (uno.length() < dos.length())
			return true;
		else return false;
	}
	//return true;
}

