//
//  main.cpp
//  HashTable
//
//  Created by Uziel Cornejo olivares on 11/11/21.
//

#include <iostream>
#include "hashTable.h"
#include "carro.h"

using namespace std;
 

 
// Driver Code
int main()
{
    HashTable HT;
    string op, temp;
    while (true) {
        cout << "---------- Menu ----------" << endl;
        cout << "1.-  Insertar " << endl;
        cout << "2.-  Eliminar " << endl;
        cout << "3.-  Buscar " << endl;
        cout << "4.-  Mostrar Tabla " << endl;
        cout << "5.-  Respaldar " << endl;
        cout << "6.-  Cargar " << endl;
        cout << "0.-  Salir" << endl;
        getline(cin,op);
        
        if (op == "1") {
            int key;
            Carro c;
            cin >> c;
            cout << "Ingresa la llave: ";
            cin >> key;
            cin.ignore();
            HT.insertItem(key, c);
        }
        else if (op == "2") {
            int key;
            cout << "Ingresa la llave que deseas elminar: ";
            cin >> key;
            cin.ignore();
            HT.eliminar(key);
            cin.ignore();
        
        }
        else if (op == "3") {
            int key;
            cout << "Ingresa la llave que deseas buscar: ";
            cin >> key;
            cin.ignore();
            HT.buscar(key);
        }
        else if (op == "4") {
            HT.printTable();
       
        }
        else if (op == "5") {
            HT.respaldar();
       
        }
        else if (op == "6") {
            HT.cargar();
       
        }
        else if (op == "0")
        {
            break;
        }
    }
     

    return 0;
}
 
