#include "Heap.h"

int main() {
	Lista list;
	list.insertarFinal(1);
	
	std::cout << list.getInicio()->value << std::endl;

	return 0;
}