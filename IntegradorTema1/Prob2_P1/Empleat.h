#include <iostream>
#include <string>
using namespace std;
#include "Venda.h"
const int MAX_VENDES = 100;

class Empleat
{
public:
Empleat();
    void setNom(const string& nom); // Añadido void y mayúscula
    string getNom() const { return m_nom; }
    bool afegeixVenda(const Venda& v);

    int getNVendes() const { return m_nVendes; }
    Venda getVenda(int i) const { return m_vendes[i]; }
private:
    string m_nom;
    int m_nVendes;
    Venda m_vendes[MAX_VENDES];
};