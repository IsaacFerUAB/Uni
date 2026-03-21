#include <iostream>
using namespace std;
#include <string>
#include "GestioProjecte.h"
#include "Data.h"
define MAX_ENCARREGATS 5;
class Tasca
{
public:
    setDurada(int durada);
    setEncarregats(string encarregats[]);

private:

    int m_durada;
    string m_encarregats[MAX_ENCARREGATS];
    Data m_dataFinalitzacio;
    Data m_dataInici;
}