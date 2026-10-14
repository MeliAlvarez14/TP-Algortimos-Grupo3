#include "ABB.h"
#include <iostream>

Bicicleta::Bicicleta(int id, std::string estacion, std::string tipo, std::string estado, int km){
    this->biciId = id;
    this->codigoEstacion = estacion;
    this->estado = estado;
    this->kilometros = km;
}

int Bicicleta::obtenerId(){
    return this->biciId;
}

string Bicicleta::obtenerEstacion(){
    return this->codigoEstacion;
}

string Bicicleta::obtenerTipo(){
    return this->tipo;
}

string Bicicleta::obtenerEstado(){
    return this->estado;
}

int Bicicleta::obtenerKilometros(){
    return this->kilometros;
}

void Bicicileta::cambiarEstacion(std::string nuevaEstacion){
    this->codigoEstacion = nuevaEstacion;
}

void Bicicileta::cambiarEstado(std::string nuevoEstado){
    this->estado = nuevoEstado;
}

void Bicicileta::sumarKilometros(int km){
    this->kilometros += km;
}








