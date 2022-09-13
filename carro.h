//
//  carro.h
//  HashTable
//
//  Created by Uziel Cornejo olivares on 11/11/21.
//

#ifndef carro_h
#define carro_h

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

class Carro
{
    string Marca;
    string Nombre;
    int Anio;
    
public:
    Carro(){};
    string getMarca() const;
    void setMarca(const string value);
    string getNombre() const;
    void setNombre(const string &value);
    int getAnio() const;
    void setAnio(int value);

friend ostream& operator<<(ostream &out, const Carro &c)
{
    out << left;
    out << setw(25) << c.Marca;
    out << setw(25) << c.Nombre;
    out << setw(25) << c.Anio;
    out << endl;

    return out;
}

friend istream& operator>>(istream &in, Carro &c) {
  
    cout << "Ingresa la marca del carro: " << endl;
    getline(cin, c.Marca);
    
    cout << "Ingresa el nombre del carro: " << endl;
    getline(cin, c.Nombre);
    
    
    cout << "Ingresa el anio de creacion: " << endl;
    cin >> c.Anio;
    cin.ignore();
    
    
    return in;
}
    
};
#endif /* carro_h */
