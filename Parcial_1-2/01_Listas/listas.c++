/*linux_fake_v2.c++ es la version 2 del programa linux_fake.c++
En esta version se agregarán listas, asi como apuntadores*/

#include <iostream>
#include <list>

using namespace std;

int main(){
    
    list<int> gqlist{12,45,8,6}; //definimos la lista #1
    
    cout << "La lista original es:" << endl;
    for (auto i : gqlist){
        cout << i << " ";
    }

    gqlist.push_back(99); //inserta un elemento al final de la lista
    gqlist.push_front(0); //inserta un elemento al inicio de la lista

    cout << "\nLa lista con los push es:" << endl;
    for (auto i : gqlist){
        cout << i << " ";
    }

    gqlist.pop_back(); //elimina el ultimo elemento de la lista

    cout << "\nLa lista con el pop_back es:" << endl;
    for (auto i : gqlist){
        cout << i << " ";
    }

    gqlist.pop_front(); //elimina el primer elemento de la lista
    cout << "\nLa lista con el pop_front es:" << endl;
    for (auto i : gqlist){
        cout << i << " ";
    }
}
