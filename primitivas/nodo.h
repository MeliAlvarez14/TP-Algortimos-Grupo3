#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef int Dato;

class Nodo
{
private:
    Dato dato;
    Nodo* siguiente;

public:
    Nodo(Dato d);

    void cambiar_dato(Dato d);

    void cambiar_siguiente(Nodo* s);

    Dato obtener_dato();

    Nodo* obtener_siguiente();
};

#endif 
