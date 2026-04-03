#include <iostream>


void inicialitza(Assignacio& dadesAssignacio, int nAssignatures, string nomAssignatures[MAX_ASSIGNATURES], int maxMatriculats[MAX_ASSIGNATURES]);
void afegeixPreferenciesEstudiant(Assignacio& dadesAssignacio, std::string nomEstudiant, int nCreditsSuperats, float notaMitjana, int nAssignaturesAMatricular, int nAssignaturesPreferides, string assignaturesPreferides[MAX_ASSIGNATURES]);

void assignaturesEstudiant(Assignacio& dadesAssignacio, string nomEstudiant, int& nAssignatures, string assignaturesAssignades[MAX_ASSIGNATURES]);
void estudiantsAssignatura(Assignacio& dadesAssignacio, string nomAssignatura, int& nEstudiants, string estudiantsAssignats[MAX_ESTUDIANTS]);



void ordenarEstudiants (Estudiant estudiants[MAX_ESTUDIANTS])
void fesAssignacio(Assignacio& dadesAssignacio)
{
    //dadesAssignacio son sol arrays de asignaturas i estudiantes
    
    //*
    // Ordenar por creditos i en caso de empate por nota
    //---------
    // MIrar que quiere el estudainte LISTA PREFERENCIA 1
    // Comprobar que haya plaza
    // sino, siguiente en su lista de preferencia* 
    // SI NUMERO DE ASSIGNATURAS = N0 de asignaturas que queria -> ACABA
    // sino, pues vuelta a empezar con el siguiente de la lista de preferencia
    // 
    // SIGUIENTE ALUMNO*/

//     typedef struct 
// {
//     Assignatura assignatures[MAX_ASSIGNATURES];
//     Estudiant estudiants[MAX_ESTUDIANTS];
//     int nAssignatures;
//     int nEstudiants;
// } Assignacio; 
    ordenarEstudiants(dadesAssignacio.estudiants&)

}