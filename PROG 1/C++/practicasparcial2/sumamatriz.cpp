#include <iostream>
using namespace std;

#define files 2
#define columnes 3
void llegirMatriu(int m[][],int files,int columnes){

for(int i = 0; i < files; i++){
    for(int j = 0; j < columnes; j++){
        cout << "INTRODUIR VALOR: ";
        cin >> valor;
        m[files][columnes] = valor;
    }
}
}

void EscriuMatriu(int m[][],int files,int columnes){

for(int i = 0; i < files; i++){
    for(int j = 0; j < columnes; j++){
        cout << "INTRODUIR VALOR: ";
        cin >> valor;
        m[files][columnes] = valor;
    }
}

}