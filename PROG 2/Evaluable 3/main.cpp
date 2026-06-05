#include <iostream>
#include <string>
#include "assignacio.h" // Conecta con tus estructuras y cabeceras

using namespace std;

int main() {
    // 1. Creamos la "caja principal" de nuestro sistema
    Assignacio elMeuSistema;

    // 2. Preparamos los datos de 3 asignaturas
    string nomsAssig[MAX_ASSIGNATURES] = {"Mates", "Fisica", "Progra"};
    // ¡Atención! Solo 1 plaza en Mates para forzar la competencia
    int placesAssig[MAX_ASSIGNATURES] = {1, 2, 2}; 

    // Inicializamos el sistema
    inicialitza(elMeuSistema, 3, nomsAssig, placesAssig);

    // 3. Añadimos a los alumnos
    
    // Alumno 1: Luis (60 créditos, nota 7.0). Se añade primero.
    string prefLuis[MAX_ASSIGNATURES] = {"Mates", "Progra"};
    afegeixPreferenciesEstudiant(elMeuSistema, "Luis", 60, 7.0, 2, 2, prefLuis);

    // Alumno 2: Ana (120 créditos, nota 8.5). 
    // Tiene prioridad sobre Luis por tener más créditos, aunque se apunte después.
    string prefAna[MAX_ASSIGNATURES] = {"Mates", "Fisica"};
    afegeixPreferenciesEstudiant(elMeuSistema, "Ana", 120, 8.5, 2, 2, prefAna);

    // 4. Ejecutamos el algoritmo de asignación
    fesAssignacio(elMeuSistema);

    // 5. Comprobamos los resultados por consola
    cout << "--- RESULTADOS DE LA MATRICULA ---" << endl;

    // A. ¿Qué le ha tocado a Ana?
    int nAssigAna = 0;
    string matriculaAna[MAX_ASSIGNATURES];
    assignaturesEstudiant(elMeuSistema, "Ana", nAssigAna, matriculaAna);

    cout << "Ana se ha matriculado de " << nAssigAna << " assignatures: ";
    for(int i = 0; i < nAssigAna; i++) cout << matriculaAna[i] << " ";
    cout << endl;

    // B. ¿Qué le ha tocado a Luis?
    int nAssigLuis = 0;
    string matriculaLuis[MAX_ASSIGNATURES];
    assignaturesEstudiant(elMeuSistema, "Luis", nAssigLuis, matriculaLuis);

    cout << "Luis se ha matriculado de " << nAssigLuis << " assignatures: ";
    for(int i = 0; i < nAssigLuis; i++) cout << matriculaLuis[i] << " ";
    cout << endl;

    // C. ¿Quién ha conseguido entrar en Mates?
    int nEstMates = 0;
    string alumnosMates[MAX_ESTUDIANTS];
    estudiantsAssignatura(elMeuSistema, "Mates", nEstMates, alumnosMates);

    cout << "En Mates hay " << nEstMates << " alumne/s matriculat/s: ";
    for(int i = 0; i < nEstMates; i++) cout << alumnosMates[i] << " ";
    cout << endl;

    return 0;
}