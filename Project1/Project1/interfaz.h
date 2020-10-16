#pragma once
#include<iostream>
#include<sstream>
using namespace std;
#include"utiles.h"
#include "ColaPrioridad.h"

template<class T>
class interfaz {

private:
	ColaPrioridad<T> * cola;

public:

	interfaz();
	~interfaz();

	void inizializar();
	void trabajarMaximos();
	void trabajarMinimos();
	void creaHeap(int);

};

template<class T>
inline interfaz<T>::interfaz(){
	cola = new ColaPrioridad<T>();
}

template<class T>
inline interfaz<T>::~interfaz(){}

template<class T>
inline void interfaz<T>::inizializar(){

	imprimeCadena("  HECHO POR LOS ESTUDIANTES:\n\n");
	imprimeCadena("               - MIGUEL SANCHEZ SALAS -\n");
	imprimeCadena("               - DANIEL LEONARDO ULLOA ROJAS -\n");
	imprimeCadena(" ____________________________________________________ \n");
	imprimeCadena("||                                                  ||\n");
	imprimeCadena("||                 ESTRUCTURA DE DATOS              ||\n");
	imprimeCadena("||                                                  ||\n");
	imprimeCadena("||                    II CICLO 2020                 ||\n");
	imprimeCadena("||                                                  ||\n");
	imprimeCadena("||                    PROYECTO  #1                  ||\n");
	imprimeCadena("||                                                  ||\n");
	imprimeCadena("||                - COLA DE PRIORIDAD -             ||\n");
	imprimeCadena("||                                                  ||\n");
	imprimeCadena("||            FECHA DE ENTREGA: 15/10/2020          ||\n");
	imprimeCadena("||__________________________________________________||\n\n\n\n\n");

	imprimeCadena("                    PRESIONE ENTER PARA SEGUIR....\n");

	esperandoEnter();
	limpiaPantalla();

	
	int opc;

	do {

		imprimeCadena(" ____________________________________________________ \n");
		imprimeCadena("|                    COLA PRIORIDAD                  |\n");
		imprimeCadena("|            SEGUN LA EDAD DE LAS PERSONAS           |\n");
		imprimeCadena("|____________________________________________________|\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|                1. TRABAJAR CON MAXIMOS             |\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|                2. TRABAJAR CON MINIMOS             |\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|                0. SALIR                            |\n");
		imprimeCadena("|____________________________________________________|\n\n");

		imprimeCadena("DIGITE SU OPCION: \n");

		opc = leerEntero();

		switch (opc)
		{
		case 1:
			trabajarMaximos();
			limpiaPantalla();
			break;
		case 2:
			trabajarMinimos();
			limpiaPantalla();
			break;
		case 0:
			break;
		default:
			imprimeCadena("          Digito una opcion no valida!\n");
			break;
		}
		limpiaPantalla();
	} while (opc != 0);
	
}

template<class T>
inline void interfaz<T>::trabajarMaximos(){

	cola->CambiaTipo(0);
	cola->BorrarDatos();
	int gestionC;
	
	/*string nombre;
	int edad, id;
	Persona* objeto = new Persona();*/

	do {

		string nombre;
		int edad, id;
		Persona* objeto = new Persona();
		

		limpiaPantalla();		imprimeCadena("\n\n");
		imprimeCadena(" ____________________________________________________ \n");
		imprimeCadena("|                        MAXIMOS                     |\n");
		imprimeCadena("|____________________________________________________|\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|               1. AGREGAR PERSONA                   |\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|               2. ELIMINAR DE COLA                  |\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|               3. VER COLA PRIORIDAD                |\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|               4. CREA COLA APARTIR DE LISTA        |\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|               0. SALIR                             |\n");
		imprimeCadena("|____________________________________________________|\n\n");

		gestionC = leerEntero();
		switch (gestionC) {
		case 1:


			limpiaPantalla();
			imprimeCadena(" ____________________________________________________ \n");
			imprimeCadena("|                       PERSONA                      |\n");
			imprimeCadena("|____________________________________________________|\n");
			imprimeCadena(" INGRESA SU NOMBRE: \n");
			nombre = leerCadena();
			imprimeCadena(" INGRESAR SU IDENTIFIACION: \n");
			id = leerEntero();
			imprimeCadena(" INGRESAR SU EDAD: \n");
			edad = leerEntero();

			objeto->setNombre(nombre);
			objeto->setId(id);
			objeto->setEdad(edad);
			
			cola->Agregar(objeto);

			break;

		case 2:
			limpiaPantalla();

			cola->ExtraerMax();
			imprimeCadena("          SE HA EXTRAIDO EL OBJETO DE LA COLA!!!\n\n\n\n\n");


			imprimeCadena("                    PRESIONE ENTER PARA SEGUIR....\n");

			esperandoEnter();
			break;


		case 3:
			limpiaPantalla();

			imprimeCadena(cola->toString());

			imprimeCadena("                    PRESIONE ENTER PARA SEGUIR....\n");

			esperandoEnter();
			break;

		case 4:
			limpiaPantalla();

			creaHeap(0);

			esperandoEnter();
			break;

		case 0:
			break;
		default:
			cout << "          Digito una opcion no valida!" << endl;
			break;
		}
		limpiaPantalla();
	} while (gestionC != 0);

}

template<class T>
inline void interfaz<T>::trabajarMinimos() {

	cola->CambiaTipo(1);
	cola->BorrarDatos();
	int gestionC;

	/*string nombre;
	int edad, id;
	Persona* objeto = new Persona();*/

	do {

		string nombre;
		int edad, id;
		Persona* objeto = new Persona();


		limpiaPantalla();		imprimeCadena("\n\n");
		imprimeCadena(" ____________________________________________________ \n");
		imprimeCadena("|                        MINIMOS                     |\n");
		imprimeCadena("|____________________________________________________|\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|               1. AGREGAR PERSONA                   |\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|               2. ELIMINAR DE COLA                  |\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|               3. VER COLA PRIORIDAD                |\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|               4. CREA COLA APARTIR DE LISTA        |\n");
		imprimeCadena("|                                                    |\n");
		imprimeCadena("|               0. SALIR                             |\n");
		imprimeCadena("|____________________________________________________|\n\n");

		gestionC = leerEntero();
		switch (gestionC) {
		case 1:


			limpiaPantalla();
			imprimeCadena(" ____________________________________________________ \n");
			imprimeCadena("|                       PERSONA                      |\n");
			imprimeCadena("|____________________________________________________|\n");
			imprimeCadena(" INGRESA SU NOMBRE: \n");
			nombre = leerCadena();
			imprimeCadena(" INGRESAR SU IDENTIFIACION: \n");
			id = leerEntero();
			imprimeCadena(" INGRESAR SU EDAD: \n");
			edad = leerEntero();

			objeto->setNombre(nombre);
			objeto->setId(id);
			objeto->setEdad(edad);

			cola->Agregar(objeto);

			break;

		case 2:
			limpiaPantalla();

			cola->ExtraerMax();
			imprimeCadena("          SE HA EXTRAIDO EL OBJETO DE LA COLA!!!\n");

			esperandoEnter();
			break;


		case 3:
			limpiaPantalla(); ("cls");

			imprimeCadena(cola->toString());

			esperandoEnter();
			break;

		case 4:
			limpiaPantalla();

			creaHeap(1);

			esperandoEnter();
			break;

		case 0:
			break;
		default:
			cout << "          Digito una opcion no valida!" << endl;
			break;
		}
		limpiaPantalla();
	} while (gestionC != 0);
}
template<class T>
inline void interfaz<T>::creaHeap(int tipo){

	cola->BorrarDatos();

	int x;

	Lista<Persona>* lp = new Lista<Persona>();

	limpiaPantalla();
	imprimeCadena(" CUANTAS PERSONAS DESEA INGRESAR? \n\n");
	x = leerEntero();

	for (int i= 0; i < x;i++) {

		string nombre;
		int edad, id;
		Persona* objeto = new Persona();

		imprimeCadena(" INGRESA SU NOMBRE: \n");
		nombre = leerCadena();
		imprimeCadena(" INGRESAR SU IDENTIFIACION: \n");
		id = leerEntero();
		imprimeCadena(" INGRESAR SU EDAD: \n");
		edad = leerEntero();

		objeto->setNombre(nombre);
		objeto->setId(id);
		objeto->setEdad(edad);

		lp->insertarFinal(objeto);
		limpiaPantalla();

	}
	
	delete cola;
	cola = new ColaPrioridad<Persona>(lp, tipo);

	limpiaPantalla();
	imprimeCadena(cola->toString());


	imprimeCadena("                    PRESIONE ENTER PARA SEGUIR....\n");

	cola->BorrarDatos();

}



