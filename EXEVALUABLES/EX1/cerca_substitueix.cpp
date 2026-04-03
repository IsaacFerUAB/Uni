#include <iostream>
using namespace std;
#include "cerca_substitueix.h"

bool cercaString(char text[], char str[], int& posicio) {
    int t = posicio;
    int s = 0;
    bool started = false;
    

    int posible_posicio = 0; 

    while (text[t] != '\0') { //hasta que acabe el texto
        
        if (text[t] == str[s] && !started)
        { //primera letra

            posible_posicio = t; 
            t++;
            s++;
            started = true;
            
        } else if (text[t] == str[s] && started)
        { //mas letras si no es la primera
            
            t++;
            s++;
            
        } else
        {
            if (started)
            {
                
                t = posible_posicio + 1; 
                started = false;
            }else
            {
                
                t++;
            }
            s = 0;
        }
        
        if (str[s] == '\0') 
        {
            posicio = posible_posicio;
            return true;
        }
    }
    
    return false;
}


void substitueixString(char text[], int posicio, char stringOriginal[], char nouString[]){
    int lenOrig = 0;
    int lenNou = 0;
    int lenText = 0;
    //logitudes
    while (stringOriginal[lenOrig] != '\0') {
        lenOrig++;
    }
    while (nouString[lenNou] != '\0') {
        lenNou++;
    }
    while (text[lenText] != '\0') {
        lenText++;
    }

    int diferencia = lenNou - lenOrig;
    
    if(diferencia > 0) 
    {//mayor diff
        
        for (int i = lenText; i >= posicio + lenOrig; i--) {
            text[i + diferencia] = text[i];
        }
    } else if(diferencia < 0) 
    {//menor diff
        for (int i = posicio + lenOrig; i <= lenText; i++) {
            text[i + diferencia] = text[i];
        }
    }

    for (int i = 0; i < lenNou; i++) {
        text[posicio + i] = nouString[i];
    }
}


int cercaSubstitueix(char text[], char stringOriginal[], char nouString[]){
    int lenNou = 0;
    int posicio = 0;
    int substitucions = 0;
    while (nouString[lenNou] != '\0') {
        lenNou++;
    }

    while (cercaString(text, stringOriginal, posicio)) {
        substitueixString(text, posicio, stringOriginal, nouString);

        substitucions++;
        posicio = posicio + lenNou; 
    }
    
    return substitucions;
}
