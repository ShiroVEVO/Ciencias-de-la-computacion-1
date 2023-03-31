#ifndef LISTAORDENADA_H
#include <iostream>
#define LISTAORDENADDA_H
#include <cstddef>
#include <string>
using namespace std;

struct estudiante
{
   int codigo;
   string Nombre;
};

struct nodo{
    estudiante estudiante;
    nodo *sig;
};

class listaordenada{
    public:
    	nodo *inicio, *centinela_final;
    	int tamano;
    
    listaordenada(){
        inicio = centinela_final = NULL;
        tamano=0;
    }
    
    void insertar(estudiante est){ //Inserta un estudiante en la lista
        nodo *nuevoNodo = new nodo();
    	nuevoNodo->estudiante = est;
    	nuevoNodo->sig = NULL;
    
    	if (inicio == NULL) { // si la lista está vacía, el nuevo nodo se convierte en la cabeza y en el centinela final
        	inicio = centinela_final = nuevoNodo;
        	tamano = 1;
        	return;
    	} else if (est.codigo < inicio->estudiante.codigo) { // si el nuevo nodo es menor que la cabeza, se convierte en la nueva cabeza
        	nuevoNodo->sig = inicio;
        	inicio = nuevoNodo;
        	tamano++;
        	return;
    	} else if (est.codigo > centinela_final->estudiante.codigo) { // si el nuevo nodo es mayor que el centinela final, se convierte en el nuevo centinela final
        	centinela_final->sig = nuevoNodo;
        	centinela_final = nuevoNodo;
        	tamano++;
        	return;
    	}
    	nodo *actual = inicio;
    	while (actual->sig != NULL && actual->sig->estudiante.codigo <= est.codigo) { // buscar el lugar adecuado para insertar el nuevo nodo
        	actual = actual->sig;
    	}
    	nuevoNodo->sig = actual->sig;
    	actual->sig = nuevoNodo;
    	tamano++;   
    }
    
    estudiante buscar (int codigo){//Busca un estudiante y si lo encuentra lo regresa, si no regresa un estudiante con codigo invalido
    	nodo *actual = inicio;
    	while (actual != NULL && actual->estudiante.codigo <= codigo) {
	        if (actual->estudiante.codigo == codigo) { // se ha encontrado el estudiante buscado
    	        return actual->estudiante;
        	}
        	actual = actual->sig;
    	} // si se llega aquí es porque no se encontró el estudiante
    	estudiante no_encontrado;
    	no_encontrado.codigo = -1;
    	return no_encontrado;
	}
	
	bool eliminar(int codigo){ //Elimina un estudiante segun su codigo
		nodo *actual = inicio;
    	if (inicio == NULL) { // la lista está vacía
        	return false;
    	} else if (inicio->estudiante.codigo == codigo) { // el estudiante a eliminar es la cabeza
        	inicio = inicio->sig;
        	tamano--;
        	return true;
    	} else if (centinela_final->estudiante.codigo == codigo) { // el estudiante a eliminar es el centinela final
        	nodo *temp = centinela_final;
        	actual->sig = NULL;
        	centinela_final = actual;
        	delete temp;
        	tamano--;
        	return true;
    	}
    
    	while (actual->sig != NULL && actual->sig->estudiante.codigo <= codigo) {
        	if (actual->sig->estudiante.codigo == codigo) { // se ha encontrado el estudiante a eliminar
            	nodo *temp = actual->sig;
            	actual->sig = actual->sig->sig;
            	delete temp;
            	tamano--;
            	return true;
        	}
        	actual = actual->sig;
    	}
	}
	 
	bool modificar(int codigo, int nuevoCodigo, string nuevoNombre){
		nodo *actual = inicio;
    	while (actual != NULL && actual->estudiante.codigo <= codigo) {
        	if (actual->estudiante.codigo == codigo) { // se ha encontrado el estudiante a modificar
            	actual->estudiante.codigo = nuevoCodigo;
            	actual->estudiante.Nombre = nuevoNombre;
            	return true; // se ha modificado el estudiante
        	}
        	actual = actual->sig;
    	}
    	return false; // no se ha modificado ningún estudiante
	}
    
    void imprimir_datos() { //Imprime los datos guardados en la lista conforme van apareciendo
        nodo *temp = inicio;
    	while (temp != NULL) {
        	std::cout << temp->estudiante.codigo << " ";
        	temp = temp->sig;
    	}
    	std::cout << std::endl;
	}
        
}
;

#endif
