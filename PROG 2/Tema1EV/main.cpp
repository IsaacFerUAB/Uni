#include <iostream>
#include <string>
#include "venda_entrades.h"

using namespace std;

// Funció auxiliar per imprimir l'estat de forma llegible
void mostrarEstat(EstatCompra estat) {
    switch(estat) {
        case COMPRA_OK: cout << "COMPRA_OK" << endl; break;
        case ERROR_ESPECTACLE: cout << "ERROR_ESPECTACLE" << endl; break;
        case ERROR_SEIENTS: cout << "ERROR_SEIENTS" << endl; break;
        // case ERROR_DIA: cout << "ERROR_DIA" << endl; break; // Descomenta-ho quan afegeixis ERROR_DIA al .h
        default: cout << "ESTAT DESCONEGUT" << endl; break;
    }
}

// Funció auxiliar per veure quins seients ens han tocat
void mostrarSeients(int seients[], int n) {
    cout << "Seients assignats: ";
    for(int i = 0; i < n; i++) {
        cout << seients[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "--- INICIANT SISTEMA DE VENDA D'ENTRADES ---" << endl;
    
    // Creem un teatre petit (10 butaques) per veure fàcilment què passa
    VendaEntrades teatre(10); 

    cout << "\n1. Afegint espectacle 'El Rey Leon'..." << endl;
    // Li posem preu 100 euros perquè calcular els percentatges de memòria sigui molt fàcil
    teatre.afegeixEspectacle("El Rey Leon", "20/10", 100.0); 

    int seientsComprats[MAX_SEIENTS_COMPRA];
    float preuFinal = 0.0;
    string dia = "20/10";

    cout << "\n2. Comprant 3 entrades (han de ser adjacents 0, 1 i 2)..." << endl;
    EstatCompra estat1 = teatre.compraEntrades("El Rey Leon", dia, 3, preuFinal, seientsComprats);
    mostrarEstat(estat1);
    if (estat1 == COMPRA_OK) {
        mostrarSeients(seientsComprats, 3);
        cout << "Preu total (sense descompte): " << preuFinal << " euros." << endl;
    }

    cout << "\n3. Comprant 2 entrades mes (han de ser 3 i 4)..." << endl;
    EstatCompra estat2 = teatre.compraEntrades("El Rey Leon", dia, 2, preuFinal, seientsComprats);
    mostrarEstat(estat2);
    if (estat2 == COMPRA_OK) mostrarSeients(seientsComprats, 2);

    // En aquest punt el teatre està així: [Ocupat, Ocupat, Ocupat, Ocupat, Ocupat, Lliure, Lliure...]

    cout << "\n4. Anul.lant les 3 primeres entrades..." << endl;
    int seientsAAnullar[] = {0, 1, 2};
    EstatCompra estat3 = teatre.anulaCompra("El Rey Leon", dia, 3, seientsAAnullar);
    mostrarEstat(estat3);

    // Ara el teatre està així: [Lliure, Lliure, Lliure, Ocupat, Ocupat, Lliure, Lliure, Lliure, Lliure, Lliure]
    // El forat més gran adjacent és de 5 butaques (del 5 al 9). Els seients 0, 1 i 2 també estan lliures.

    cout << "\n5. Comprant 6 entrades. (Més de 5: Descompte 5% + Com no hi ha 6 juntes: Descompte 10%)" << endl;
    cout << "El preu de 6 entrades son 600e. Amb el 15% de descompte hauria de costar 510e." << endl;
    EstatCompra estat4 = teatre.compraEntrades("El Rey Leon", dia, 6, preuFinal, seientsComprats);
    mostrarEstat(estat4);
    if (estat4 == COMPRA_OK) {
        mostrarSeients(seientsComprats, 6); // Haurien de ser: 0, 1, 2 (salta el 3 i 4) i agafa 5, 6 i 7.
        cout << "Preu total (amb descompte acumulat): " << preuFinal << " euros." << endl; 
    }

    cout << "\n6. Comprovant l'ocupacio total a traves de recuperaOcupacio..." << endl;
    bool ocupacio[MAX_SEIENTS];
    teatre.recuperaOcupacio("El Rey Leon", dia, ocupacio);
    cout << "Mapa de butaques (1=Ocupat, 0=Lliure): [ ";
    for(int i = 0; i < 10; i++) { // Només iterem fins a 10 perquè és la grandària del nostre teatre
        cout << ocupacio[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}