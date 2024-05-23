#include <iostream>
#include <list>

using namespace std;

struct File
{
    list<string> Files;
};
struct Users
{
    string User;
    File Files;
};


int main(){

    list<Users> users;
    Users user;
    string username, localUser;
    int salir, menu;
    string tmp;

    do{
    
    cout << "Enter username: ";
    cin >> username;

    localUser = &user;
    localUSer->User = username;

    for(auto i : users){
        if(i.User == username){
            localUser = &i;
            cout << "Usuario ya existe" << endl;
            return 0;
        }
    }
    user.User = username; //add username to user
    user.Files = File();

    do
    {
        cout << "Options: " << endl << "1. Listar" << endl << "2. Crear archivo" << endl << "3. Salir" << endl;
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Lista: " << endl;
            users.push_back(user); //add user to list
            //dysplay users
            for(auto i : users.Files){
                cout << i << " - " << endl;
                }
            break;
        case 2:
            cout << "Ingresa Archivo: ";
            cin >> tmp;
            user.FIles.push_back(tmp); //add file to user
            break;
        case 3:
        default:
            break;
        }
    } while (menu != 3);

    users.push_back(user); //add user to list

    //dysplay users
    for(auto i : users){
        cout << i.User << " - ";
    }
    
    cout << endl << endl;
    cout << "Quieres salir? (1:yes 2:no): ";
    cin >> salir;
    cout << endl;


    } while (salir == 2);

    return 0;

}