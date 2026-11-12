#include "Bicicleta.h"
#include <iostream>
using namespace std;

Bicicleta::Bicicleta(int id, string estacion, string tipo, string estado, int km){
    biciId = id;
    codigoEstacion = estacion;
    estado = estado;
    kilometros = km;
}

int Bicicleta::obtenerId(){
    return biciId;
}

string Bicicleta::obtenerEstacion(){
    return codigoEstacion;
}

string Bicicleta::obtenerTipo(){
    return tipo;
}

string Bicicleta::obtenerEstado(){
    return estado;
}

int Bicicleta::obtenerKilometros(){
    return kilometros;
}

void Bicicleta::cambiarEstacion(string nuevaEstacion){
    codigoEstacion = nuevaEstacion;
}

void Bicicleta::cambiarEstado(string nuevoEstado){
    estado = nuevoEstado;
}

void Bicicleta::sumarKilometros(int km){
    kilometros += km;
}








