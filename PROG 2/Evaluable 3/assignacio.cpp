#include <iostream>
#include "assignacio.h"

void inicialitza(Assignacio& dadesAssignacio, int nAssignatures, string nomAssignatures[MAX_ASSIGNATURES], int maxMatriculats[MAX_ASSIGNATURES])
{
    
    dadesAssignacio.nEstudiants = 0; //estuidiantes a 0
    
    for(int i = 0; i < MAX_ASSIGNATURES; i++) //inicializa las asignaturas
    {
        dadesAssignacio.assignatures[i].nom = nomAssignatures[i];
        dadesAssignacio.assignatures[i].nAssignats = 0;
        dadesAssignacio.nAssignatures = nAssignatures;
        dadesAssignacio.assignatures[i].maxMatriculats = maxMatriculats[i];
        
    }
}
void afegeixPreferenciesEstudiant(Assignacio& dadesAssignacio, std::string nomEstudiant, 
    int nCreditsSuperats, float notaMitjana, int nAssignaturesAMatricular, 
    int nAssignaturesPreferides, string assignaturesPreferides[MAX_ASSIGNATURES])
{
        int num_Estudiants = dadesAssignacio.nEstudiants;
        dadesAssignacio.estudiants[num_Estudiants].nom = nomEstudiant;
        dadesAssignacio.estudiants[num_Estudiants].nCreditsSuperats = nCreditsSuperats;
        dadesAssignacio.estudiants[num_Estudiants].notaMitjana = notaMitjana;
        dadesAssignacio.estudiants[num_Estudiants].nAssignaturesAMatricular = nAssignaturesAMatricular;
        dadesAssignacio.estudiants[num_Estudiants].nAssignaturesAssignades = 0;
        dadesAssignacio.estudiants[num_Estudiants].nAssignaturesPreferides = nAssignaturesPreferides;
        for(int i = 0; i < nAssignaturesPreferides; i++)
        {
            dadesAssignacio.estudiants[num_Estudiants].assignaturesPreferides[i] = assignaturesPreferides[i];
        }
        dadesAssignacio.nEstudiants++;
}
        




void ordenarEstudiants(Assignacio& dadesAssignacio)//he usado sort por insercion
{
    
    int j;
    for(int s = dadesAssignacio.nEstudiants - 2; s >= 0; s--)
    {
        Estudiant temporal = dadesAssignacio.estudiants[s];
    
        j = s + 1;

    while (j < dadesAssignacio.nEstudiants &&
        (dadesAssignacio.estudiants[j].nCreditsSuperats > temporal.nCreditsSuperats || //CREDITOS
        (dadesAssignacio.estudiants[j].nCreditsSuperats == temporal.nCreditsSuperats && dadesAssignacio.estudiants[j].notaMitjana > temporal.notaMitjana))) //POR NOTA
        { 
            //estudiante a la izquierda
            dadesAssignacio.estudiants[j - 1] = dadesAssignacio.estudiants[j]; 
            j++; 
        }

        dadesAssignacio.estudiants[j - 1] = temporal;
    
    }
}
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
    ordenarEstudiants(dadesAssignacio);

    
    for(int e = 0; e < dadesAssignacio.nEstudiants; e++)
    {
        Estudiant& estudiante = dadesAssignacio.estudiants[e]; //estudiante en assignacio
        int prefActual = 0;
        while(estudiante.nAssignaturesAssignades < estudiante.nAssignaturesAMatricular && prefActual < estudiante.nAssignaturesPreferides)
        { //si el estudiante tiene plazas y no se ha acabado su lista ->

                string assignaturaEst = estudiante.assignaturesPreferides[prefActual];

                for(int y = 0; y < dadesAssignacio.nAssignatures; y++)
                {
                //si el nombre de la asssingatura del estudiant coincide con el de uno de la lista,
                //  si esa asignatura tiene menos asignados que el max...
                    if ((dadesAssignacio.assignatures[y].nom == assignaturaEst) && 
                        (dadesAssignacio.assignatures[y].nAssignats < dadesAssignacio.assignatures[y].maxMatriculats))
                    {
                        //EX6
                        int plazasOcupadas = dadesAssignacio.assignatures[y].nAssignats;
                        dadesAssignacio.assignatures[y].estudiantsAssignats[plazasOcupadas] = estudiante.nom;
                        dadesAssignacio.assignatures[y].nAssignats++;

                        estudiante.assignaturesAssignades[estudiante.nAssignaturesAssignades] = assignaturaEst;
                        estudiante.nAssignaturesAssignades++;
                        //suma nAssAssignades i se le agrega a la lista
                        
                    }
                }
                
            prefActual++;
        }

        
    }
    

}




void assignaturesEstudiant(Assignacio& dadesAssignacio, string nomEstudiant, int& nAssignatures,
    string assignaturesAssignades[MAX_ASSIGNATURES])
{
    for(int i = 0; i < dadesAssignacio.nEstudiants; i++)
    {
        if(dadesAssignacio.estudiants[i].nom == nomEstudiant)
        {
            nAssignatures = dadesAssignacio.estudiants[i].nAssignaturesAssignades;
            for(int s = 0; s < nAssignatures; s++){
                assignaturesAssignades[s] = dadesAssignacio.estudiants[i].assignaturesAssignades[s];
            }
        }
    
    }
}
void estudiantsAssignatura(Assignacio& dadesAssignacio, string nomAssignatura, int& nEstudiants,
    string estudiantsAssignats[MAX_ESTUDIANTS])
    {
        
    for(int i = 0; i < dadesAssignacio.nAssignatures; i++)
    {
        if(dadesAssignacio.assignatures[i].nom == nomAssignatura)
        {
            nEstudiants = dadesAssignacio.assignatures[i].nAssignats;
            for(int s = 0; s < nEstudiants; s++){
                estudiantsAssignats[s] = dadesAssignacio.assignatures[i].estudiantsAssignats[s];
            }
        }
    
    }
    }
