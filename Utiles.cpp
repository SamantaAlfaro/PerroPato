#include "Utiles.h"
char intTochar(int n) {
	stringstream a;
	char x;
	a << n;
	a >> x;
	return x;
}

int charToint(char n) {
	stringstream a;
	int x;
	a << n;
	a >> x;
	return x;
}

void quitarCeros(string& n) {
	if (n[0] == '0') {
		while (n[0] == '0') {
			n.erase(0, 1);
		}
	}
}