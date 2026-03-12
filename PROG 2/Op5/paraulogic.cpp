#include iostream
using namespace std;
#include "paraulogic.h"


bool checkLletraCentral(char paraula[MAX_PARAULA],char lletres[N_LLETRES]){

        bool estaLletraCentral = false;
        int pos_lletra = 0;

        //mentres no acabi paraula y no es trobli la central
        while((lletra != '\0') && !estaLletraCentral){
            
            if( paraula[pos_lletra] == lletres[0]){
                estaLletraCentral = true;
            }else{
                pos_lletra++;
            }
        }

        return estaLletraCentral;
}

bool lletresValides(char paraula[MAX_PARAULA],char lletres[N_LLETRES]){
    
    bool lletresValides = true;
    bool lletraEnParaula = false;

    int iLletresValides = 1; //comença en 1 pq la primera lletra es la central ja mirada
    int iLletresParaula = 0;

    char lletraParaula = paraula[iLletresParaula];
    char lletraValida = lletres[iLletresValides];

    while((lletraParaula != '\0') && lletresValides){
        lletraParaula = paraula[iLletresParaula] //escull letra de paraula
        
        while((lletraEnParaula = false) && (iLletresValides < N_LLETRES)){
            //conmprova si la lletra esta en les 7
            if(lletraParaula == lletraValida[iLletresValides]){
                lletraEnParaula = true;
            }else{
                iLletresValides++;
            }
        } 
        if(!lletraEnParaula){
            lletresValides = false; //si NO esta la letra anterior no es valida,
        }else{
            iLletresParaula++; // sino puede seguir
        }
        
    }

    return lletresValides;
}

bool paraulaEnDiccionari(char paraula[MAX_PARAULA],char diccionari[N_PARAULES][MAX_PARAULA]){

    int p = 0; //fila-> paraula1,2,3...
    int ll = 0; //letra de la palabra 
    char lletra_dic = 'x'
    bool coincideix_lletra = true;
    bool paraula_trobada = false;

    while((p < N_PARAULES) && (!paraula_trobada)){
        coincideix_lletra = true;
        while((coincideix_lletra) && (lletra_dic != '\0')){
            if(paraula[ll] = diccionari[p][ll]){ //si la x letra es la misma en el dicc de la palabra p, siguiente letra ll+
                if(paraula[ll] = '\0'){
                    paraula_trobada = true; //si no se ha cambiado la palabra es que son iguals, i como acaban a la vez significa que son iguales en su totalidad.
                }else{
                    ll++;
                }
                
            }else{
                coincideix_lletra = false; //si no coinice sale bucle y siguente palabra
            }
        }
        p++; //next word
    }

    return paraula_trobada;


}
bool introdueixParaula(char paraula[MAX_PARAULA], char lletres[N_LLETRES],
	char diccionari[N_PARAULES][MAX_PARAULA], bool& tutti, int& puntuacio){


    }


/**paraula és la paraula que s’introdueix i que s’ha de comprovar si és vàlida o no. Sempre conté el caràcter ‘\0’ per indicar el
final de la paraula.
_ _ _ _ /0

▪ lletres és un array que conté les 7 lletres possibles per formar paraules. La primera posició de l’array conté la lletra central
que ha d’estar a totes les paraules vàlides.

▪ diccionari és una matriu que conté la llista de paraules vàlides. Cada fila de la matriu és una de les paraules vàlides del
diccionari (que també contenen el caràcter ‘\0’ per indicar el final de la paraula).

▪ tutti s’utilitza com a paràmetre per referència per retornar si la paraula és un tutti o no. Si la paraula no és vàlida ha de
retornar false.

▪ puntuacio s’utilitza com a paràmetre per referència per retornar la puntuació que s’obté amb la paraula. Si la paraula no és
vàlida ha de retornar 0.

▪ La funció retorna si la paraula és vàlida o no
**/

