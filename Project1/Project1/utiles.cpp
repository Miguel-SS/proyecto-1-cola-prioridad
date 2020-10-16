#include "utiles.h"
#include <sstream>

int convertirInt(std::string s) {
	int v;
	std::stringstream r(s);
	r >> v;
	return v;
}
double convertirDouble(std::string s) {
	double v;
	std::stringstream r(s);
	r >> v;
	return v;
}

void imprimeCadena(string cadena)
{
	cout << cadena;                  // IMPRIME CADENA
}

void imprimeInt(int cadena) {
	cout << cadena;
}

string leerCadena()
{
	string x;
	getline(cin, x);                   // LEE UNA CADENA
	return x;
}

int leerEntero()
{
	int n;
	bool continuar = true;
	while (true) {
		if (cin >> n) {                                                      // METOD PARA LEER ENTEROS
			cin.clear(); // Limpia el estado del flujo..                        USADO PARA LA VALIDACION DE VARIABLES INT
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cerr << "Valor incorrecto.. digita UN NUMERO" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}

}

void limpiaPantalla() {     // LIMPIA PANTALLA NEGRA
	system("cls");
}

void esperandoEnter() {     // ESPERA A PRECIONAR EL ENTER
	cin.get();
}