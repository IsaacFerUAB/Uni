#include "posicio.h"
using namespace std;
#include <iostream>
#include <string>

    Posicio::Posicio(){
        m_fila = 0;
        m_columna = 0;
    }

    Posicio::Posicio(int fila, int columna)
    {
        m_fila = fila;
        m_columna = columna;
    }

ifstream& operator>>(ifstream& fitxer, Posicio& posicio){
    
    string stringLectura;
    
    fitxer >> stringLectura;

    posicio.fromString(stringLectura);
    
    return fitxer;
}
ofstream& operator<<(ofstream& fitxer, const Posicio& posicio){

    fitxer << posicio.toString();
    return fitxer; 
}


    int Posicio::getFila() const
    {
        return m_fila;
    }

    int Posicio::getColumna() const
    {
        return m_columna;
    }

    string Posicio::toString(const int fila, const int columna, string& posicio) const{ 
        posicio[0] = fila;
        posicio[1] = columna;
    }

    void Posicio::fromString(const string& pos){

    }