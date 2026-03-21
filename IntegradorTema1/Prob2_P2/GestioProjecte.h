#include <iostream>
using namespace std;
#include <string>
#include "Tasca.h"
#include "Data.h"
class GestioProjecte
{
public:
//funcion con nombbre, tiempo, fecha, No participantes i quienes son en array string
void afegeixTasca(const string& nom, int duradaPrevista, const Data& dataActual, int nParticipants, 
    string participants[MAX_PARTICIPANTS])
    {
        
    }


void endarrereixTasca(const string& nom, int nDies);
//Ha de modificar la data prevista de finalització de la tasca amb el nom que s’indica, endarrerint la data tants dies com indica
//el paràmetre nDies.
int completaTasca(const string& nom, const Data& dataActual); 
//Retorna la diferència de dies entre la data prevista i la data actual. Si la data prevista és posterior a la data
//actual el valor retornat ha de ser positiu i si la data prevista és anterior, el valor retornat ha de ser negatiu.
void tasquesPendents(const string& nom, const Data& dataActual, int nDies, int& nTasques, string tasques[]);
void retardTasques(const Data& dataActual, int& nPersones, string persones[]);
void recuperarTasca(const string& nom, Data& dataPrevista, bool& completada, Data& dataFinal);

}