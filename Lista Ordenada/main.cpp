/*
	PRESENTADO POR:
	- Franco Jose Guzman - 20211020155
	- Adrian Stiven Olmos Ardila - 20181020039
*/


#include <iostream>
#include "listaordenada.h"

using namespace std;



int main(int argc, char** argv) {
 	estudiante estudiante,est2,et3,et4;
 	estudiante.codigo=123;
 	est2.codigo=122;
 	et3.codigo=001;
 	et4.codigo = 323;
 	listaordenada lista;
 	lista.insertar(estudiante);
 	lista.insertar(est2);
 	lista.insertar(et3);
 	lista.insertar(et4);
 	lista.eliminar(001);
 	lista.imprimir_datos();
	return 0;
}
