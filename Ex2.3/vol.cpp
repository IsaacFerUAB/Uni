#include "vol.h"

Vol::Vol() 
{
    m_codi= " ";
    m_origen= " ";
    m_desti= " ";
    m_data= " ";
    m_hora = " ";
    m_seients = new Seient();//DIN
    m_nSeients = 0;
    //MAX SEIENTS???

}
Vol::Vol(const string& codi, const string& origen, const string& desti,
const string& data, const string& hora, int nSeients)
{
    m_codi= codi;
    m_origen =origen;
    m_desti= desti;
    m_data= data;
    m_hora = hora;
    m_seients = new Seient();//DIN
    m_nSeients = nSeients;
    
}

    Vol::Vol(const Vol& v)
{
    
    m_codi = v.m_codi;
    m_origen = v.m_origen;
    m_desti = v.m_desti;
    m_data = v.m_data;
    m_hora = v.m_hora;
    m_nSeients = v.m_nSeients;
    m_maxSeients = v.m_maxSeients;
    if (v.m_seients != nullptr)
    {
        m_seients = new Seient[m_maxSeients];

        for (int z = 0; z < m_nSeients; ++z)
        {
            m_seients[z] = v.m_seients[z]; 
        }
    }
    else{
        m_seients = nullptr;
    }
}
    Vol::~Vol()
    {
        delete[] m_seients;
    }


Vol& Vol::operator=(const Vol& v)
{
    
    if (this != &v)
    {
        delete[] m_seients;
        m_seients = nullptr;
        m_codi = v.m_codi;
        m_origen = v.m_origen;
        m_desti = v.m_desti;
        m_data = v.m_data;
        m_hora = v.m_hora;
        m_nSeients = v.m_nSeients;
        m_maxSeients = v.m_maxSeients;

        if (v.m_seients != nullptr)
        {
            m_seients = new Seient[m_maxSeients];
            for (int s = 0; s < m_nSeients; ++s)
            {
            m_seients[s] = v.m_seients[s];
            }
        }
        else
        {
            m_seients = nullptr;
        }
    }

    return *this;
}

void Vol::afegeixSeients(string* codiSeients, int nSeients)
{
    m_nSeients = nSeients;
    m_maxSeients = nSeients;
    if (m_seients != nullptr)
    {
        delete[] m_seients;
    }

    m_seients = new Seient[m_maxSeients];

    for (int i = 0; i < m_nSeients; i++)
    {
        m_seients[i] = Seient(codiSeients[i]);
    }
}
bool Vol::afegeixPassatger(const string& codiSeient, const string& dni, const string& nom)
{
    bool passatgerasignat = false;
    for(int s = 0; s < m_nSeients; s++)
    {
        if(m_seients[s].getCodi() == codiSeient)
        {
                passatgerasignat = m_seients[s].assignaPassatger(dni,nom);
                s = m_nSeients;
        }
    }
    return passatgerasignat;
}

Passatger* Vol::recuperaPassatger(const string& codiSeient)
{
    Passatger* passatger = nullptr;
    bool seienttrobat = false;

    for(int s = 0; s < m_nSeients && !seienttrobat; s++)
    {
        if(m_seients[s].getCodi() == codiSeient)
        {
                seienttrobat = true;
                passatger = m_seients[s].getPassatger();
        }
    }
    return passatger;
}

bool Vol::cancelaReserva(const string& codiSeient)
{
    bool cancelat = false;
    for(int s = 0; s < m_nSeients && !cancelat; s++)
    {
        if(m_seients[s].getCodi() == codiSeient)
        {
                cancelat = m_seients[s].eliminaPassatger();
        }
    }
    return cancelat;
}


bool Vol::modificaReserva(const string& codiSeientOriginal, const string& codiSeientNou)
{
    
    int posOriginal = -1;
    int posNou = -1;
    bool goku = false;
    bool vegetta = false;
    bool assignat = false;
    int s = 0;
    while (s < m_nSeients && (!goku || !vegetta))
    {
        if (m_seients[s].getCodi() == codiSeientOriginal)
        {
            posOriginal = s;
            goku = true;
        }
        if (m_seients[s].getCodi() == codiSeientNou)
        {
            posNou = s;
            vegetta = true;
        }
        s++; 
    }

    
    if (posOriginal == -1 || posNou == -1)
    {
        return false;
    }

    Passatger* pOriginal = m_seients[posOriginal].getPassatger();
    Passatger* pNou = m_seients[posNou].getPassatger();

    if (pOriginal == nullptr || pNou != nullptr) //si no estan opcupats
    {
        return false; 
    }

 //change
    assignat = m_seients[posNou].assignaPassatger(pOriginal->getDni(), pOriginal->getNom());

    if (assignat)
    {
        m_seients[posOriginal].eliminaPassatger();
        return true;
    }

    return false;
}

    // string m_codi;
    // string m_origen;
    // string m_desti;
    // string m_data;
    // string m_hora;
    // Seient *m_seients;
    // int m_nSeients;
    // int m_maxSeients;
