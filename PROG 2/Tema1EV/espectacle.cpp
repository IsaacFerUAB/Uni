#include "espectacle.h"
Espectacle::Espectacle() {}
Espectacle::Espectacle(string nom, string dia, float preu, int nEntrades)
{
    nom_e = nom;
    dia_e = dia;
    preu_e = preu;
    nEntradesDispo_e = nEntrades;
    for(int i = 0; i < MAX_SEIENTS; i++) {ocupacio_e[i] = false;}

}

string Espectacle::getNom()
{
    return nom_e;
}

string Espectacle::getDia()
{
    return dia_e;
}
float Espectacle::getPreu(){
    return preu_e;
}
bool Espectacle::getOcupacio(int butaca)
{
    return ocupacio_e[butaca];
}
void Espectacle::ocuparSeient(int butaca)
{
    ocupacio_e[butaca] = true;
}
void Espectacle::desocuparSeient(int butaca)
{
    ocupacio_e[butaca] = false;
}

