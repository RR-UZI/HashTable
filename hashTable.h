//
//  hashTable.h
//  HashTable
//
//  Created by Uziel Cornejo olivares on 11/11/21.
//

#ifndef hashTable_h
#define hashTable_h

#include <iostream>
#include <list>
#include <cstring>
#include "carro.h"
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class HashTable {
private:
    static const int hashGroups = 10;
    list<pair<int, Carro>> table[hashGroups];
    
public:
//    bool isEmpty() const;
//    int hashFunction(int key);
//    void insertItem(int key, string value);
//    void eliminar(int key);
//    string buscar(int key);
//    void printTable();
    
bool isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if (sum == 0) {
        return true;
    }else {
        return false;
    }
}
    
int hashFunction(int key) {
    return key % hashGroups;
}

void insertItem(int key, Carro value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto itr = begin(cell);
    bool keyExists = false;
    for (; itr != end(cell); itr++) {
        if (itr->first == key) {
            keyExists = true;// en caso de que exista la llave se modifica su valor
            itr->second = value;
            cout << "La llave existe. Se modifico el carro! " << endl;
            break;
        }
    }
    
    if (!keyExists) {
        cell.emplace_back(key, value);
    }
    return;
}

void eliminar(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto itr = begin(cell);
    bool keyExists = false;
    for (; itr != end(cell); itr++) {
        if (itr->first == key) {
            keyExists = true;
            itr = cell.erase(itr);
            cout << "Se elimino el par correctamente" << endl;
            break;
        }
    }
    
    if (!keyExists) {
        cout << "El par no existe. No se elimino el par" << endl;
    }
    
    return;
}

void printTable() {
    if (isEmpty()) {
        cout << "Esta vacio!!!" << endl;
    }
    else{
        for (int i{}; i < hashGroups; i++) {
            if (table[i].size() == 0) continue;
        
            auto itr = table[i].begin();
            for (; itr != table[i].end(); itr++) {
                cout << "[Informacion] Llave: " << itr->first << endl;
                cout << "---------------------------------Carro ----------------------------------------" << endl;
                cout << left;
                cout << setw(25) << "Marca";
                cout << setw(25) << "Nombre";
                cout << setw(25) << "Anio";
                cout << endl;
                cout << itr->second << endl;
            }
        }
        }
}

string buscar(const int key)
{
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            cout << "Se encontro el carro \n";
            cout << "---------------------------------Carro ----------------------------------------" << endl;
            cout << left;
            cout << setw(25) << "Marca";
            cout << setw(25) << "Nombre";
            cout << setw(25) << "Anio";
            cout << endl;

            cout << bItr->second;
        }
    }

    cout << "No se encontro el carro" << endl;
    return string("No se encontro el carro");
}
    
void respaldar() {
    ofstream archivo("file01.txt", ios::binary | ios::out);
    if (archivo.is_open()) {
        for (int i{}; i < hashGroups; i++) {
            if (table[i].size() == 0) continue;
            
            auto itr = table[i].begin();
            for (; itr != table[i].end(); itr++) {
                archivo << itr->first << ",";
                archivo << itr->second.getMarca() << ",";
                archivo << itr->second.getNombre() << ",";
                archivo << itr->second.getAnio() << "*";
            }
        }
        archivo.close();
    }
}

vector<string> split(string s, string delimitador) {
    size_t pos = 0;
    string token;
    vector<string> atributos;
    while ((pos = s.find(delimitador)) != string::npos) {
        token = s.substr(0, pos);
        atributos.push_back(token);
        s.erase(0, pos + delimitador.length());
        
    }
        if (s != "") {
            atributos.push_back(s);
        }
        return atributos;
    }
    
    
void cargar() {
        queue<string> cola;
        string info;
        ifstream archivo("file01.txt", ios::binary | ios::in);
        if (archivo.is_open()) {
            while (getline(archivo, info)) {
                vector<string> llaves = split(info, "*");
//                vector<string> llaves = split(info, "|");
                vector<Carro*> carros;
                for ( auto &key: llaves) {
                    vector<string> atributos = split(key, ",");
                    int llave = stoi(atributos.at(0));
                    string marca = atributos.at(1);
                    string nombre = atributos.at(2);
                    int anio = stoi(atributos.at(3));
                    Carro * carro = new Carro();
                    int LLave = llave;
                    carro->setMarca(marca);
                    carro->setNombre(nombre);
                    carro->setAnio(anio);
                    carros.push_back(carro);
                    insertItem(LLave, *carro);
                }
                

                
            }
          
            }
    archivo.close();
        }
    
    
};
#endif /* hashTable_h */
