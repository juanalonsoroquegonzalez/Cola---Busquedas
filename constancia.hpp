#ifndef __CONSTANCIA_H__
#define __CONSTANCIA_H__

#include <string>
#include <iostream>

using namespace std;

class constancia {
private:
    string nombre;
    string carrera;
    int materias_aprobadas;
    float promedio;

public:
    constancia();
    
    constancia(const string &nombre);

    void llenar();

    const string &getNombre() const;
    
    constancia &operator=(const constancia &);
 
    bool operator==(const constancia &) const;
    bool operator!=(const constancia &) const;

    friend istream &operator>>(istream &, constancia &);
    friend ostream &operator<<(ostream &, const constancia &);
};

#endif // __CONSTANCIA_H__
