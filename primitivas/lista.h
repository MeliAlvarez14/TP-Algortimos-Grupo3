#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
#include "nodo.h"
using namespace std;

class Lista
{
private:
    Nodo* primero;
    int largo;

public:

    Lista();

    void alta(int d, int pos);

    void baja(int pos);

    int consulta(int pos);

    bool vacia();

    virtual ~Lista();

    int obtener_largo();

    void mostrar();


private:
    Nodo* obtener_nodo(int pos);
};

#endif 

