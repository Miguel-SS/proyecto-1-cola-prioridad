#include"ColaPrioridad.h"
#include "Persona.h"
#include "interfaz.h"

int main() {

	interfaz<Persona>* i = new interfaz<Persona>();
	i->inizializar();

	system("pause");
	return 0;
}