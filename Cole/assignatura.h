// assignatura.h
#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H
#include "estudiant.h"
#include "professor.h"

const int MAX_ESTUDIANTS = 50;

class Assignatura
{
public:
    Assignatura() : m_nom(""), m_nEstudiants(0), m_professor(nullptr) {}
    Assignatura(const string& nom) : m_nom(nom), m_nEstudiants(0), m_professor(nullptr) {}

    void afegeixEstudiant(const string& nom, const string& niu);
    bool afegeixNota(const string& niu, float nota);
    float calculaNotaMitjana(const string& niu);
    string getNom() { return m_nom; }

    void modificarProfessor(Professor* prof) { m_professor = prof;}
    
    
    Professor* getProfessor() {return m_professor;}
private:
    string m_nom;
    Estudiant m_estudiants[MAX_ESTUDIANTS];
    int m_nEstudiants;
    Professor* m_professor;

    int cercaEstudiant(const string& niu);
};

#endif