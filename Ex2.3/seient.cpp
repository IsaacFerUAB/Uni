#include "seient.h"

Seient::~Seient() {
    
    if (m_passatger != nullptr)
    {
        delete m_passatger;
        m_passatger = nullptr;
    }
}
Seient& Seient::operator=(const Seient& otro)
{
    m_codi = otro.m_codi;

    delete m_passatger;
    m_passatger = nullptr;

    if (otro.m_passatger != nullptr) 
        {
            m_passatger = new Passatger(otro.m_passatger->getDni(), otro.m_passatger->getNom());
        }
        else 
        {
            m_passatger = nullptr;
        }

    return *this;
}



bool Seient::assignaPassatger(const string& dni, const string& nom)
{

    if(m_passatger == nullptr)
    {
        Passatger* passatger;
        passatger = new Passatger(dni,nom);

        m_passatger = passatger;
        return true;
    }
    return false;
}

bool Seient::eliminaPassatger()
{
    if(m_passatger != nullptr)
    {
        delete m_passatger;
        m_passatger = nullptr;
        return true;
    }
    return false;
}