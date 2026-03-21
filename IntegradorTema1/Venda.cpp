#include "Venda.h"

Venda::Venda()
{
    m_import = 0.0;
    m_producte = "";
    m_tipus = TIPUS_NO_ASSIGNAT;
}

Venda::Venda(const string& data, float import_, const string& producte, TIPUS_VENDA tipus)
{
    m_data.setData(data);
    m_import = import_;
    m_producte = producte;
    m_tipus = tipus;
}

// =============================================================
// Exercici 1: operator<
// =============================================================
bool Venda::operator<(const Venda& v) const
{   
    if (m_data < v.m_data) {
        return true;
    }
    
    else if (m_data == v.m_data) {
        return m_import < v.m_import;
    }

    return false;
    
}

// =============================================================
// Exercici 5: getComissio
// =============================================================
float Venda::getComissio() const
{
    switch (m_tipus) {

        case TIPUS_A: 
            return m_import * 0.10f;
            break;

        case TIPUS_B: 
            return m_import * 0.05f;
            break;

        case TIPUS_C: 
            return m_import * 0.02f;
            break;

        default:      
            return 0.0f;
    }
}

// =============================================================
// Exercici 5: getData
// =============================================================
Data Venda::getData() const
{
    return m_data;
}
