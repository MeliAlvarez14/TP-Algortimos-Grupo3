#include "NodoArbol.h"
#include "Bicicleta.h"

NodoArbol::NodoArbol(int clave, Bicicleta* bici){
    this->clave = clave;
    this->bicicleta = bici;
    this->izquierdo = nullptr;
    this->derecho = nullptr;
}

int NodoArbol::obtenerClave(){ 
    return this->clave; 
}

Bicicleta* NodoArbol::obtenerBicicleta(){ 
    return this->bicicleta; 
}

NodoArbol* NodoArbol::obtenerIzquierdo(){ 
    return this->izquierdo; 
}

NodoArbol* NodoArbol::obtenerDerecho(){ 
    return this->derecho; 
}

void NodoArbol::cambiarIzquierdo(NodoArbol* izq){ 
    this->izquierdo = izq; 
}

void NodoArbol::cambiarDerecho(NodoArbol* der){ 
    this->derecho = der; 
}
