#include <iostream>
using namespace std;

int index_element(int valor, int array[], int DIM){
    
    bool trobat = false;
    int index = -1;
    for(int i = 0; i < DIM; i++){
        
        if(valor == array[i]){
            index = i;
        }
    }
    
    return index;
}