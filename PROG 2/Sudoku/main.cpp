#include <iostream>
#include "sudoku.h"

using namespace std;

int main() {
    // 1. Creamos un tablero de prueba (las pistas iniciales)
    // Usamos 0 para las celdas vacías.
    const int nivellProva[MIDA_TAULER][MIDA_TAULER] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // 2. Creamos la variable que guardará todo el estado del juego
    EstatSudoku laMevaPartida;

    // 3. Preparamos la memoria usando la función que creaste
    carregarNivell(laMevaPartida, nivellProva);

    // 4. ¡A jugar!
    cout << "--- BENVINGUT AL SUDOKU ---" << endl;
    bucleJoc(laMevaPartida);

    return 0;
}