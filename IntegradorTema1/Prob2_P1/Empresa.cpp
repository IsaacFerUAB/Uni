#include <iostream>
#include <string>
using namespace std;
#include "Empresa.h"
#include "Venda.h"
// =============================================================
// Exercici 2: Constructor
// =============================================================
Empresa::Empresa(int nEmpleats, string empleats[MAX_EMPLEATS])
{
    m_nEmpleats = nEmpleats;
    for(int i = 0; i < nEmpleats; i++) {
        m_empleats[i].setNom(empleats[i]);
    }
}

// =============================================================
// Exercici 5: importComissio
// =============================================================
float Empresa::importComissio(const Data& dataInici, const Data& dataFi) const
{
    float totalcomisio = 0.0;
    
    for (int i = 0; i < m_nEmpleats; i++) {
        totalcomisio += m_empleats[i].importComissio(dataInici, dataFi);
    }
    return totalcomisio;
}
