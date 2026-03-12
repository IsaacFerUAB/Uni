#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "aleatori.h"
using namespace std;

#define DIM 15


void EscollirParaula (char paraula[], int DIM_Paraula){

    //VARIABLES
    int NumeroLinies = 0;
    char linea[DIM_Paraula];
    
    //LECTURA ARCHIVO
    ifstream archiu;
    archiu.open("paraulespenjat.txt");

    if (archiu.is_open()){
        while (getline(archiu, linea)) {
            NumeroLinies++;
    
    LineaAleatoria = Aleatori(1, NumeroLinies);
    for(int i = 1; i =! LineaAleatoria; i++){
        getline(archiu, linea)
        paraula = linea;
    }
    
    }else{
        cout << "ERROR: Archiu no trobat" << endl;
        return 0;
    }
    }
}

void InicialitzarJoc (){

    cout << "Benvingut al joc del penjat" << endl;


}



int main(){

    char paraula[DIM];

    InicialitzarJoc();
    EscollirParaula(paraula,DIM);
    cout << paraula << endl;






}