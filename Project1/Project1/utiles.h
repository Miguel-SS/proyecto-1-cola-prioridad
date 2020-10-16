#pragma once
#include <iostream>
using namespace std;

#define DELIMITADOR_CAMPO '\t';
#define DELIMITADOR_REGISTRO '\n';

int convertirInt(std::string);
double convertirDouble(std::string);
void imprimeCadena(string);
void imprimeInt(int);
void limpiaPantalla();
string leerCadena();
int leerEntero();
void esperandoEnter();

