#include "constancia.hpp"
#include <iostream>

constancia::constancia() : nombre(""), carrera(""), materias_aprobadas(0), promedio(0.0f) {}

constancia::constancia(const string &nombre) : nombre(nombre), carrera(""), materias_aprobadas(0), promedio(0.0f) {}

void constancia::llenar()
{
    cin.ignore();
    cout << "\t\t\tCarrera: ";
    getline(cin, carrera);
    cout << "\t\t\tMaterias aprobadas: ";
    cin >> materias_aprobadas;
    cout << "\t\t\tPromedio: ";
    cin >> promedio;
}

const string& constancia::getNombre() const
{
    return nombre;
}

constancia& constancia::operator=(const constancia &other)
{
    if (this != &other) {
        this->nombre = other.nombre;
    }
    return *this;
}

bool constancia::operator==(const constancia &other) const
{
    return (nombre == other.nombre &&
            carrera == other.carrera &&
            materias_aprobadas == other.materias_aprobadas &&
            promedio == other.promedio);
}

bool constancia::operator!=(const constancia &other) const
{
    return !(*this == other);
}

ostream& operator<<(ostream &out, const constancia &obj)
{
    out << "Nombre: " << obj.nombre << endl;
    out << "Carrera: " << obj.carrera << endl;
    out << "Materias Aprobadas: " << obj.materias_aprobadas << endl;
    out << "Promedio: " << obj.promedio << endl;
    return out;
}

istream& operator>>(istream &in, constancia &obj)
{
    cout << "Ingrese carrera: ";
    in >> obj.carrera;
    cout << "Ingrese cantidad de materias aprobadas: ";
    in >> obj.materias_aprobadas;
    cout << "Ingrese promedio: ";
    in >> obj.promedio;
    return in;
}
