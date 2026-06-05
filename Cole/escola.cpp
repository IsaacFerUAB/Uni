#include "escola.h"
#include <fstream>
using namespace std;

void Escola::inicialitzaProfessors(const string& nomFitxer)
{
    ifstream fitxer(nomFitxer);
    if (fitxer.is_open())
    {
        string nom, mail, despatx;
        while (!fitxer.eof())
        {
            fitxer >> nom >> mail >> despatx;
            m_professors[m_nProfessors++] = Professor(nom, mail, despatx);
        }
        fitxer.close();
    }
}

void Escola::inicialitzaAssignatures(const string& nomFitxer)
{
    ifstream fitxer(nomFitxer);
    if (fitxer.is_open())
    {
        string nomAssignatura;
        int nEstudiants;
        while (!fitxer.eof())
        {
            fitxer >> nomAssignatura >> nEstudiants;
            m_assignatures[m_nAssignatures] = Assignatura(nomAssignatura);
            for (int i = 0; i < nEstudiants; i++)
            {
                string nom, niu;
                fitxer >> nom >> niu;
                m_assignatures[m_nAssignatures].afegeixEstudiant(nom, niu);
            }
            m_nAssignatures++;
        }
        fitxer.close();
    }
}

Assignatura* Escola::cercaAssignatura(const string& nomAssignatura)
{
    Assignatura* A_trobada = nullptr;
    for(int i = 0; i < m_nAssignatures; i++)
    {
        if(m_assignatures[i].getNom() == nomAssignatura)
        {
            A_trobada = &m_assignatures[i];
            i = m_nAssignatures;
        }
    }
    return A_trobada;
}

Professor* Escola::cercaProfessor(const string& nomProfessor)
{
    Professor* P_trobat = nullptr;
    for(int i = 0; i < m_nProfessors; i++)
    {
        if(m_professors[i].getNom() == nomProfessor)
        {
            P_trobat = &m_professors[i];
            i = m_nProfessors;
        }
    }
    return P_trobat;
}

bool Escola::afegeixProfessorAssignatura(const string& nomAssignatura, const string& nomProfessor)
{
    Assignatura* assignatura = cercaAssignatura(nomAssignatura);
    Professor* professor = cercaProfessor(nomProfessor);
    
    if (assignatura != nullptr && professor != nullptr)
    {
        if (assignatura->getProfessor() != nullptr)
        {
            return false;
        }
        assignatura->modificarProfessor(professor);
        return true;
    }
    return false;
}

bool Escola::eliminaProfessorAssignatura(const string& nomAssignatura)
{
    Assignatura* assignatura = cercaAssignatura(nomAssignatura);
    
    if (assignatura != nullptr && assignatura->getProfessor() != nullptr)
    {
        assignatura->modificarProfessor(nullptr);
        return true;
    }
    return false;
}

void Escola::getAssignaturesProfessor(const string& nomProfessor, string assignatures[MAX_ASSIGNATURES], int& nAssignatures)
{
    nAssignatures = 0;
    for (int i = 0; i < m_nAssignatures; i++)
    {
        Professor* profe = m_assignatures[i].getProfessor();
        if (profe != nullptr && profe->getNom() == nomProfessor)
        {
            assignatures[nAssignatures] = m_assignatures[i].getNom();
            nAssignatures++;
        }
    }
}

string Escola::getProfessorAssignatura(const string& nomAssignatura)
{
    Assignatura* assignatura = cercaAssignatura(nomAssignatura);
    if (assignatura != nullptr && assignatura->getProfessor() != nullptr)
    {
        Professor* profe = assignatura->getProfessor();
        return profe->getNom();
    }
    return "";
}