#include "Empleat.h"
#include "Venda.h"
// =============================================================
// Exercici 2: Constructor per defecte
// =============================================================
Empleat::Empleat()
{
    m_nVendes = 0; 
}

// =============================================================
// Exercici 2: setNom
// =============================================================
void Empleat::setNom(const string& nom)
{
    m_nom = nom;
}

// =============================================================
// Exercici 3: afegeixVenda
// =============================================================
bool Empleat::afegeixVenda(const Venda& v)
{
    if(m_nVendes == MAX_VENDES){
        return false;
    }
    int i = m_nVendes - 1;

    while ((i >= 0) && (v < m_vendes[i])) {
        m_vendes[i + 1] = m_vendes[i];
        i--;
    }

    m_vendes[i + 1] = v;
    m_nVendes++;

    return true;
}

// =============================================================
// Exercici 5: importComissio
// =============================================================
float Empleat::importComissio(const Data& dataInici, const Data& dataFi) const
{
    float comisio = 0.0;
    
    for (int i = 0; i < m_nVendes; i++) {
        Data dataVenda = m_vendes[i].getData();
        
        if (!(dataVenda < dataInici) && !(dataVenda > dataFi)) {
            comisio += m_vendes[i].getComissio();
        }
    }
    return comisio;
}
