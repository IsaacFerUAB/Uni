#ifndef ESPECTACLE_H
#define ESPECTACLE_H

#include <string>
using namespace std;


typedef enum
{
    COMPRA_OK,
    ERROR_ESPECTACLE,
    ERROR_DIA,
    ERROR_SEIENTS
} EstatCompra;

const int MAX_SEIENTS_COMPRA = 10;
const int MAX_SEIENTS = 20;

class Espectacle
{
public:
		Espectacle();
        Espectacle(string nom, string dia, float preu, int nEntrades);
        string getNom();
        string getDia();
        float getPreu();
        bool getOcupacio(int butaca);
        void ocuparSeient(int butaca);
        void desocuparSeient(int butaca);
private:
    bool ocupacio_e[MAX_SEIENTS];
    string nom_e;
    string dia_e;
    int nEntradesDispo_e;
    float preu_e;
};

#endif
