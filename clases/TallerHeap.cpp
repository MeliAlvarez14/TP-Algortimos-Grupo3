#include "TallerHeap.h"
#include <iostream>

TallerHeap::TallerHeap(int capacidadInicial) {
    capacidad = capacidadInicial;
    tamano = 0;
    arreglo = new ElementoHeap[capacidad];
}

TallerHeap::~TallerHeap() {
    delete[] arreglo;
}

bool TallerHeap::estaVacio() const {
    return tamano == 0;
}

int TallerHeap::obtenerTamano() const {
    return tamano;
}

void TallerHeap::redimensionar() {
    capacidad *= 2;
    ElementoHeap* nuevoArreglo = new ElementoHeap[capacidad];
    for (int i = 0; i < tamano; i++) {
        nuevoArreglo[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = nuevoArreglo;
}

void TallerHeap::flotar(int indice) {
    while (indice > 0) {
        int padre = (indice - 1) / 2;
        // Min-heap: el de menor número de prioridad sube a la raíz (porque es el más urgente)
        if (arreglo[indice].prioridad < arreglo[padre].prioridad) {
            ElementoHeap temp = arreglo[indice];
            arreglo[indice] = arreglo[padre];
            arreglo[padre] = temp;
            indice = padre;
        } else {
            break;
        }
    }
}

void TallerHeap::hundir(int indice) {
    int menor = indice;
    int izq = 2 * indice + 1;
    int der = 2 * indice + 2;

    if (izq < tamano && arreglo[izq].prioridad < arreglo[menor].prioridad) {
        menor = izq;
    }
    if (der < tamano && arreglo[der].prioridad < arreglo[menor].prioridad) {
        menor = der;
    }

    if (menor != indice) {
        ElementoHeap temp = arreglo[indice];
        arreglo[indice] = arreglo[menor];
        arreglo[menor] = temp;
        hundir(menor);
    }
}

void TallerHeap::insertar(Bicicleta* bici, int prioridad) {
    if (tamano >= capacidad) {
        redimensionar();
    }
    arreglo[tamano].bici = bici;
    arreglo[tamano].prioridad = prioridad;
    flotar(tamano);
    tamano++;
}

Bicicleta* TallerHeap::extraerMasUrgente() {
    if (estaVacio()) {
        return nullptr;
    }
    Bicicleta* biciUrgente = arreglo[0].bici;
    arreglo[0] = arreglo[tamano - 1];
    tamano--;
    if (tamano > 0) {
        hundir(0);
    }
    return biciUrgente;
}