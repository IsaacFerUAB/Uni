#include <iostream>
using namespace std;
#include "sudoku.h"


void carregarNivell(EstatSudoku &joc, const int dades[MIDA_TAULER][MIDA_TAULER]){

    for(int i = 0; i < MIDA_TAULER; i++){
        for(int j = 0; j < MIDA_TAULER; j++){
            //Copia tauler
            joc.cel_les[i][j] = dades[i][j];
            //marca True si fixa
            if(dades[i][j] != CEL_LA_BUIDA){
                joc.esFixa[i][j] = true;
            }else{
                joc.esFixa[i][j] = false;
            }
        }
    }
}

void imprimirTauler(const EstatSudoku &joc){

    char ValorAImprimir = 'X';

    for(int i = 0; i < MIDA_TAULER; i++){
        for(int j = 0; j < MIDA_TAULER; j++){

            if(joc.cel_les[i][j] == CEL_LA_BUIDA){
                ValorAImprimir = '.';
            }else{
                ValorAImprimir = joc.cel_les[i][j] + '0';
            }

            if((j % 3 != 0) && (j != 0)){
                cout << ValorAImprimir << " ";
            }else{
                cout << "| " << ValorAImprimir << " ";
            }
            
        }

        //Fila 2 y 5 --
        if((i + 1) % 3 != 0 || i == MIDA_TAULER - 1){
            cout << endl;
        }else{
            cout << endl;
            cout << "------------------------" << endl;
        }
    }
}

bool esMovimentValid(const EstatSudoku &joc, int fila, int col, int valor){
/**
* 1) Rang de posició: fila i col han d’estar dins [0..MIDA_TAULER-1].
* 2) Rang del valor: 'valor' ha d’estar dins [1..9]. (Aquesta funció NO gestiona el cas 0.)
* 3) La cel·la NO pot ser fixa (no es poden modificar pistes inicials).
* 4) Regles Sudoku: el valor no pot repetir-se ni a la fila, ni a la columna, ni al bloc 3x3.
*/
//1
    bool esValid = true;
    if(fila < 0 || fila > MIDA_TAULER - 1){
        return false;
    }

    if(col < 0 || col > MIDA_TAULER - 1){
        return false;
    }
//2
    if(valor < 1 || valor > 9){
        return false;
    }
//3
    if(joc.esFixa[fila][col] == true){
        return false;
    }
//4
    for(int i = 0; i < MIDA_TAULER; i++){
        if(joc.cel_les[i][col] == valor){
            esValid = false;
        }
        if(joc.cel_les[fila][i] == valor){
            esValid = false;
        }
    }

    int subFila = (fila / MIDA_BLOC) * MIDA_BLOC;
    int subCol = (col / MIDA_BLOC) * MIDA_BLOC;

    for (int i = 0; i < MIDA_BLOC; i++) {
        for (int j = 0; j < MIDA_BLOC; j++) {
            if (joc.cel_les[subFila + i][subCol + j] == valor) {
                esValid = false;
            }
        }
    }

    return esValid;
}

bool colocarNumero(EstatSudoku &joc, int fila, int col, int valor){
    bool CanviAplicat = false;
    if(valor == CEL_LA_BUIDA){
        if(joc.esFixa[fila][col] == false){
            joc.cel_les[fila][col] = CEL_LA_BUIDA;
            CanviAplicat = true;
        }
    }else{
        bool MovimentValid = esMovimentValid(joc,fila,col,valor);
        if(MovimentValid == true){
            joc.cel_les[fila][col] = valor;
            CanviAplicat = true;
        }
    }
return CanviAplicat;
}

bool taulerComplet(const EstatSudoku &joc){
    bool TaulerComplet = true;
    for (int i = 0; i < MIDA_TAULER; i++) {
        for (int j = 0; j < MIDA_TAULER; j++) {
            if(joc.cel_les[i][j] == CEL_LA_BUIDA){
                TaulerComplet = false;
            }
        }
    }
    return TaulerComplet;
}


void bucleJoc(EstatSudoku &joc){

    int filaIntro = 0;
    int colIntro = 0;

    int valor = 0;
    int fila = 0;
    int col = 0;
    
    while(!taulerComplet(joc)){

        imprimirTauler(joc);
        
        cout << "Introdueix la fila (1-9): ";
        cin >> filaIntro;
        cout << endl;

        cout << "Introdueix la columna (1-9): ";
        cin >> colIntro;
        cout << endl;

        cout << "Introdueix el valor (1-9) (0 per borrar): ";
        cin >> valor;
        cout << endl;

        int fila = filaIntro - 1;
        int col = colIntro - 1;

        bool movimentRealitzat = colocarNumero(joc, fila, col, valor);

        if (movimentRealitzat) {
                cout << "Moviment realitzat correctament." << endl;
            } else {
                cout << "ERROR: Moviment no valid o cel_la fixa. Torna a intorduir." << endl;
        }
    }
    
    imprimirTauler(joc);
    cout << "Perfecte! Sudoku completat!" << endl;
}
