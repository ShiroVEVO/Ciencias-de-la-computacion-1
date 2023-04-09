#ifndef PILA1_H     
#define PILA1_H    
#include <cstddef>

template <class tipoElemento> class Pila{
	tipoElemento *pila;
  	int p;
	public:
  		Pila (int max=100){
		  pila = new tipoElemento[max]; p=0;
		}
		~Pila(){
			delete pila;
		}
		inline void meter (tipoElemento v){
			pila[p++]=v;
		}
		inline tipoElemento sacar(){
			return pila [--p];
		}
		inline int vacia(){
			return !p;
		}
	};
#endif



