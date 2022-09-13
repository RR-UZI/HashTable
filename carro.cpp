//
//  carro.cpp
//  HashTable
//
//  Created by Uziel Cornejo olivares on 11/11/21.
//

#include "carro.h"

string Carro::getMarca() const
{
    return Marca;
}

void Carro::setMarca(const string value)
{
    Marca = value;
}

string Carro::getNombre() const {
    return Nombre;
}

void Carro::setNombre(const string &value)
{
    Nombre = value;
}

int Carro::getAnio() const
{
    return Anio;
}

void Carro::setAnio(int value)
{
    Anio = value;
}
