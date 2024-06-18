    #include <iostream>
    #include <list>
    #include <fstream>
    #include <vector>
    #include <sstream>
    using namespace std;

    enum permitions {
        r, w, x
    };

    struct Files {
        string Name;
        permitions permitionOwner;
        permitions permitionGroup;
        permitions permitionOther;
    };

    // Estructura que representa a un usuario y su lista de archivos
    struct Users {
        string User;              // Nombre del usuario
        list<Files> files;       // Lista de archivos del usuario
    };

    // Función split
    vector<string> split(const string &s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    int main() {
        list<Users> users;        // Lista que contiene todos los usuarios
        Users user, * localUser;   // Estructura temporal para el usuario y puntero para el usuario local
        string username;          // Variable para almacenar el nombre del usuario ingresado
        int salir, menu, optUser;          // Variables para controlar la salida y la selección del menú
        string tmp, user_root, file_user;      // Variable temporal para almacenar el nombre del archivo
        ofstream fuser, ofRoot;             // Variable para escribir en el archivo de usuario
        ifstream ifRoot ("root");    // Variable para leer en el archivo de usuario
        Files tmpfile;             // Variable temporal para almacenar el archivo

        string biopass; //Variable para almacenar la contraseña
        cout << "Ingresar master password: "; //Se pide la contraseña
        cin >> biopass; //Se pide la contraseña

        if (biopass != "input") //Si la contraseña es incorrecta se cierra el programa
        {
            return 2;
        }

        if (ifRoot.is_open())//Existe
        {
            while (getline(ifRoot, user_root)) //Lee el archivo root
            {
                cout << "Loading user: " << user_root << endl;
                user.User = user_root;   // Asigna el nombre ingresado al nuevo usuario
                user.files.clear();     // Limpia la lista de archivos del nuevo usuario (asegurando que esté vacía)

                ifstream fuser (user_root + ".usr");
                cout << "Archivos dentro del usuario: ";
                while (getline(fuser, file_user)) { // Lee el archivo root
                    vector<string> file_info = split(file_user, '|');
                    if (file_info.size() == 4) {
                        tmpfile.Name = file_info[0];
                        tmpfile.permitionOwner = static_cast<permitions>(stoi(file_info[1]));
                        user.files.push_back(tmpfile);
                    }
                    else {
                        cout << "Error al leer el archivo: " << file_user << endl;
                        }
                    cout << tmpfile.Name << " - ";
                }
                cout << endl;
                users.push_back(user);  // Añade el nuevo usuario a la lista de usuarios
            }
            ifRoot.close();
        }
        else //No existe el archivo root
        {
            //Crear archivo root
            ofRoot.open("root");
            ofRoot.close(); 
        }
        

        do {

            cout << "\nMENU: " << endl << "1) Listar users" << endl << "2) Login" << endl;
            cin >> optUser;

            switch (optUser)
            {
            case 1: // Listar usuarios
                for (auto i : users)
                {
                    cout << "user_:" << i.User << endl;
                }
                break;
            
            case 2:
                // Solicita el nombre del usuario
                cout << "Ingresa username: ";
                cin >> username;

                localUser = nullptr;  // Inicializa el puntero a null

                // Busca si el usuario ya existe en la lista
                for (auto& i : users) { // Se usa referencia para evitar copia innecesaria
                    if (i.User == username) {
                        localUser = &i;     // Si encuentra el usuario, apunta a él
                        cout << "User exists" << endl;
                        break;              // Sale del bucle si encuentra el usuario
                    }
                }

                // Si el usuario no existe, crea uno nuevo
                if (localUser == nullptr) {
                    user.User = username;   // Asigna el nombre ingresado al nuevo usuario
                    user.files.clear();     // Limpia la lista de archivos del nuevo usuario (asegurando que esté vacía)

                    users.push_back(user);  // Añade el nuevo usuario a la lista de usuarios
                    localUser = &(users.back()); // Apunta al nuevo usuario añadido
                }

                // Bucle para manejar las opciones del menú
                do {
                    cout << "Opciones:" << endl
                        << "\t1) Listar" << endl
                        << "\t2) Crear" << endl
                        << "\t3) Mostrar todos los usuarios y archivos" << endl
                        << "\t4) Salir" << endl
                        << "Selecciona una opcion: ";
                    cin >> menu;

                    switch (menu) {
                    case 1: // Listar archivos del usuario actual
                        cout << "Archivos del usuario " << localUser->User << ":" << endl; // Imprime el nombre del usuario
                        for (const auto& file : localUser->files) { // Itera sobre la lista de archivos del usuario
                            cout << file.Name << " - " << file.permitionOwner << "|" << file.permitionGroup << "|" << file.permitionOther << "|"; // Imprime el nombre del archivo y sus permisos
                        }
                        cout << endl << endl; // Imprime dos saltos de línea al final
                        break;

                    case 2: // Crear un nuevo archivo para el usuario actual
                        cout << "Ingresa archivo: ";
                        cin >> tmp;
                        tmpfile.Name = tmp;
                        tmpfile.permitionOwner = x;
                        tmpfile.permitionGroup = w;
                        tmpfile.permitionOther = r;
                        localUser->files.push_back(tmpfile); // Añade el nuevo archivo a la lista del usuario
                        break;

                    case 3: // Mostrar todos los usuarios y sus archivos en forma de tabla
                        cout << "Usuarios y sus archivos:" << endl;
                        for (const auto& i : users) {
                            cout << i.User << ":\t"; // Imprime el nombre del usuario seguido de dos puntos y una tabulación
                            for (const auto& file : i.files) {
                                cout << file.Name << "\t"; // Imprime cada archivo del usuario separado por tabulación
                            }
                            cout << endl; // Imprime un salto de línea para el siguiente usuario
                        }
                        break;

                    case 4: // Salir del menú
                        break;

                    default:
                        cout << "Opción no válida" << endl;
                        break;
                    }
                } while (menu != 4); // Repite el menú hasta que el usuario elija salir
            break;
            }

                // Pregunta al usuario si desea salir del programa principal
                cout << "Quieres salir? (0: yes 1: no): ";
                cin >> salir;
                cout << endl;

            } while (salir == 1); // Repite el bucle principal hasta que el usuario decida salir

        // Guardar en archivo
        ofRoot.open("root");
        // Muestra todos los usuarios y sus archivos (este bucle es redundante y no se necesita en este contexto)
        for (const auto& i : users) {
            cout << i.User << " - ";
            ofRoot << i.User << endl;
            fuser.open(i.User + ".usr");
            
            for (const auto& file : i.files) 
            {
                fuser << file.Name << "|" << file.permitionOwner << "|" << file.permitionGroup<< "|" << file.permitionOther << endl;//guarda el nombreArchivo en el archivo
                cout << "\t" << file.Name << " - " << file.permitionOwner << " - " << file.permitionGroup<< " - " << file.permitionOther<< endl;  // Imprime el nombre del archivo y sus permisos
            }
            cout << endl;
            fuser.close(); //cierra archivo
        }
        ofRoot.close();
        cout << "Guardado" << endl;

        return 0;
    }