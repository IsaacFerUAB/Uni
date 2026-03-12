#include <iostream>
using namespace std;

#define X 4
#define Y 4


int main(){

int matriu[X][Y];
int valor = 0;

for(int i = 0; i < X; i++){
    for(int j = 0; j < Y; j++){
        cout << "INTRODUIR VALOR: ";
        cin >> valor;
        matriu[i][j] = valor;
    }
}
for(int i = 0; i < X; i++){
    for(int j = 0; j < Y; j++){
        cout <<  matriu[i][j];
    }
    cout << endl;
}

for(int i = 0; i < X; i++){
    for(int j = 0; j < Y; j++){
        if(i == j){
        cout <<  matriu[i][j];
        }
    cout << endl;
    }
}

}