#include <iostream>
#include "cola.hpp"
#include "constancia.hpp"

int main() {
    cola<constancia, 5> Cola;

    int opcion;
    do {
        system("cls");
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\t            MENU                     " << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\t1. Enqueu" << endl;
        cout << "\t\t\t2. Dequeu" << endl;
        cout << "\t\t\t3. Busqueda" << endl;
        cout << "\t\t\t4. Salir" << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tIngrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                if (Cola.Llena()) {
                    cout << "\t\t\t---------------------------------------" << endl;
                    cout << "\t\t\tLa cola esta llena." << endl;
                    cout << "\t\t\t---------------------------------------" << endl;
                    break;
                } else {
                    string nombreAlumno;
                    cout << "\t\t\tIngresa el nombre del alumno para agendar la constancia: ";
                    cin.ignore();
                    getline(cin, nombreAlumno);
                    Cola.enqueu(constancia(nombreAlumno));
                }
            }
                break;
            case 2: {
                if (Cola.Vacia()) {
                    cout << "\t\t\t---------------------------------------" << endl;
                    cout << "\t\t\tNo hay mas constancias en cola." << endl;
                    cout << "\t\t\t---------------------------------------" << endl;
                    break;
                } else {
                    Cola.bot();
                    Cola.dequeu();
                }
            }
                break;
            case 3: {
                if (Cola.Vacia()) {
                    cout << "\t\t\t---------------------------------------" << endl;
                    cout << "\t\t\tNo hay mas constancias en cola." << endl;
                    cout << "\t\t\t---------------------------------------" << endl;
                    break;
                } else {
                    cout << "\t\t\tBuscar su constancia en la cola: ";
                    string nombre;
                    cin.ignore();
                    getline(cin, nombre);
                    Cola.busquedaLineal(nombre);
                }
            }
                break;
            case 4:
                cout << "\t\t\tSaliendo del programa..." << endl;
                break;
            default:
                cout << "\t\t\t---------------------------------------" << endl;
                cout << "\t\t\tOpcion no valida. Por favor, ingrese una opcion valida." << endl;
                cout << "\t\t\t---------------------------------------" << endl;
                break;
        }
        system("PAUSE");
    } while (opcion != 4);

    return 0;
}