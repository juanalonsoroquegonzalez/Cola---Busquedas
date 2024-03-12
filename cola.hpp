#ifndef __COLA_H__
#define __COLA_H__

#include <iostream>
#include "constancia.hpp"

using namespace std;

template<typename T, int MAX>
class cola {
private:
    T Datos[MAX];
    int Tam;
    int ultimo;
    void Inserta(T dato, int posicion);
    void Busca(T dato);
    void Muestra();
    int ultimo_() const;
    T recupera(int posicion);
    void Agrega(T dato);
    void Elimina(int posicion);

public:
    cola();
    void Inicializa(T dato, int ultimo);
    bool Vacia() const;
    bool Llena() const;
    void enqueu(T element);
    void dequeu();
    void busquedaLineal(string nombre);
    T busquedaBinaria(T elemento);
    T bot();
};

template<typename T, int MAX>
cola<T, MAX>::cola() : Tam(MAX), ultimo(-1) {}

template<typename T, int MAX>
void cola<T, MAX>::busquedaLineal(string nombre) {
    if (Vacia()) {
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tLa cola esta vacia. No hay elementos en el fondo." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        return;
    }
    for (int i = 0; i <= ultimo; i++) {
        if (Datos[i].getNombre() == nombre) {
            if(i == 0){
                cout << "\t\t\t---------------------------------------" << endl;
                cout << "\t\t\tAlumno " << nombre << " es el siguiente en la cola " << endl;
                cout << "\t\t\t---------------------------------------" << endl;
                return;
            }
            cout << "\t\t\t---------------------------------------" << endl;
            cout << "\t\t\tFaltan " << i << " constancias para llegar a " << nombre << endl;
            cout << "\t\t\t---------------------------------------" << endl;
            return;
        }
    }
    cout << "\t\t\t---------------------------------------" << endl;
    cout << "\t\t\tNo se encontraron constancias para " << nombre << endl;
    cout << "\t\t\t---------------------------------------" << endl;
}

template<typename T, int MAX>
T cola<T, MAX>::busquedaBinaria(T elemento) {
    int i = 0;
    int j = ultimo;
    for(int m = 0; i <= j; m++){
        int medio = (i + j) / 2;
        if(Datos[m] == elemento){
            return medio;
        }
        else if(elemento < Datos[medio]){
            j = medio -1;
        }
        else{
            i = medio + 1;
        }
    }
    return -1;
}

template<typename T, int MAX>
T cola<T, MAX>::bot() {
    if (Vacia()) {
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tLa pila esta vacia. No hay elementos en el fondo." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        return Datos[0].getNombre();
    }
    cout << "\t\t\t---------------------------------------" << endl;
    cout << "\t\t\tLlena la constancia del alumno < " << Datos[0].getNombre() << " >" << endl;
    cout << "\t\t\t---------------------------------------" << endl;
    Datos[0].llenar();
    return Datos[0].getNombre();
}

template<typename T, int MAX>
void cola<T, MAX>::Inserta(T dato, int posicion) {
    if (Llena() || posicion < 0 || posicion > ultimo + 1) {
        cout << "\nError de insercion" << endl;
    } else {
        int i = ultimo + 1;
        while (i > posicion) {
            Datos[i] = Datos[i - 1];
            i--;
        }
        Datos[posicion] = dato;
        ultimo++;
        cout << "\nElemento insertado" << endl;
    }
}

template<typename T, int MAX>
void cola<T, MAX>::Busca(T dato) {
    bool encontrado = false;
    for (int i = 0; i <= ultimo; ++i) {
        if (Datos[i] == dato) {
            encontrado = true;
            cout << "\t\t\t---------------------------------------" << endl;
            cout << "\t\t\tEl elemento " << dato << " se encontro en la posicion " << i << "." << endl;
            cout << "\t\t\t---------------------------------------" << endl;
            return;
        }
    }

    if (!encontrado) {
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tEl elemento " << dato << " no se encontro en la pila." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
    }
}

template<typename T, int MAX>
void cola<T, MAX>::Muestra() {
    if (Vacia()) {
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tLa pila esta vacia." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        return;
    }
    cout << endl;
    cout << "\t\t\t---------------------------------------" << endl;
    cout << "\t\t\tElementos de la pila:" << endl;
    for (int i = 0; i <= ultimo; ++i) {
        cout << "\t\t\tElemento #" << i << ":  " << endl;
        cout << "\t\t\t" << Datos[i] << endl;
    }
    cout << "\t\t\t---------------------------------------" << endl;
}

template<typename T, int MAX>
int cola<T, MAX>::ultimo_() const {
    return ultimo;
}

template<typename T, int MAX>
T cola<T, MAX>::recupera(int posicion) {
    if (Vacia() || posicion < 0 || posicion > ultimo) {
        cout << "\nInsuficiencia datos";
        return T();
    } else {
        return Datos[posicion];
    }
}

template<typename T, int MAX>
void cola<T, MAX>::Agrega(T dato) {
    if (Llena()) {
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tNo se pudo agregar la cita porque la pila esta llena." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
    } else {
        Datos[++ultimo] = dato;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tCita agregada a la cola..." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
    }
}

template<typename T, int MAX>
void cola<T, MAX>::Elimina(int posicion) {
    if (Vacia() || posicion < 0 || posicion > ultimo) {
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tError..." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
    } else {
        int i = posicion;
        while (i < ultimo) {
            Datos[i] = Datos[i + 1];
            i++;
        }
        ultimo--;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tConstancia completada." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
    }
}

template<typename T, int MAX>
void cola<T, MAX>::Inicializa(T dato, int ultimo) {}

template<typename T, int MAX>
bool cola<T, MAX>::Vacia() const {
    if (ultimo == -1)
        return true;
    return false;
}

template<typename T, int MAX>
bool cola<T, MAX>::Llena() const {
    return (ultimo == Tam - 1);
}

template<typename T, int MAX>
void cola<T, MAX>::enqueu(T element) {
    Agrega(element);
}

template<typename T, int MAX>
void cola<T, MAX>::dequeu() {
    Elimina(0);
}

#endif // __COLA_H__