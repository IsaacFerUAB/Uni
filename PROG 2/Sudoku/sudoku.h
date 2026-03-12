#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <string>

const int MIDA_TAULER = 9;
const int MIDA_BLOC = 3;
const int CEL_LA_BUIDA = 0;

struct EstatSudoku {
    int cel_les[MIDA_TAULER][MIDA_TAULER];
    bool esFixa[MIDA_TAULER][MIDA_TAULER];
};

// Inicialització
void carregarNivell(EstatSudoku &joc, const int dades[MIDA_TAULER][MIDA_TAULER]);

// Visualització
void imprimirTauler(const EstatSudoku &joc);

// Lògica del joc
bool esMovimentValid(const EstatSudoku &joc, int fila, int col, int valor);
bool colocarNumero(EstatSudoku &joc, int fila, int col, int valor);
bool taulerComplet(const EstatSudoku &joc);

// Bucle principal
void bucleJoc(EstatSudoku &joc);


#endif


