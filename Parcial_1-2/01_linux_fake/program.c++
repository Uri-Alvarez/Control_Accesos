#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <cstdlib>

using namespace std;


int main() {
    cout << "Ingresa Usuario" << endl;
    string user;
    cin >> user;

    // Create a directory with the user's name
    string directory;
	directory = "mkdir " + user;
	system(directory.c_str());

    cout << "Bienvenido Usuario" << endl;
    cout << "Selecione opcion:" << endl;
    cout << "1. Crear archivo" << endl;
    cout << "2. Listar archivos" << endl;
    cout << "3. Salir" << endl;
    cout << ">> ";

    int option;
    cin >> option;
    switch (option)
    {
    case 1:{
        string file;
		cout << "\nEnter the file name: ";
		cin >> file;
		string command = "touch " + user + "/" + file;
		system(command.c_str());
		break;
        }

	case 2:{
		string command = "ls " + user;
		system(command.c_str());
		break;
        }

	default:{
		exit(EXIT_SUCCESS);
        break;
        }
    }
}
