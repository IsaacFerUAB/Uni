#ifndef POSICIO_H
#define POSICIO_H

#include <string>
#include <fstream>
using namespace std;

const int N_FILES = 8;
const int N_COLUMNES = 8;

class Posicio
{
public:
    Posicio();
    Posicio(int fila, int columna);
    int getFila() const; 
    int getColumna() const; 
    string toString() const;
    void fromString(const string& pos);


private:
    int m_fila, m_columna;
    string posicio;
};

ifstream& operator>>(ifstream& fitxer, Posicio& posicio){};
ofstream& operator<<(ofstream& fitxer, const Posicio& posicio);

#endif // POSICIO_H
// 1. Abrimos el archivo
    ifstream fitxer(nomFitxer);

    // 2. Comprobamos que el archivo existe y se ha abierto bien
    if (fitxer.is_open())
    {
        // 3. Leemos el primer dato. 
        // Si el archivo dice "O d6", esto coge la 'O' y la guarda en tipusFitxa.
        fitxer >> tipusFitxa; 
        
        // 4. Leemos el segundo dato.
        // El operador >> se salta automáticamente el espacio en blanco.
        // Luego lee "d6" y usa TU sobrecarga del operador >> que llama a fromString("d6").
        fitxer >> posicio; 
        
        // 5. Cerramos el archivo
        fitxer.close();
    }
    else
    {
        cout << "Error: No s'ha pogut obrir el fitxer " << nomFitxer << endl;
    }