#include <iostream>
using namespace std;

// 1=moviment cap a la esquerra, 2=moviment cap a la dreta, 3=moviment cap a baix, 4=moviment cap a dalt.
void modificarpos(int &xcord, int &ycord, int dir, int x_min, int x_max, int y_min, int y_max){
    switch(dir){

        case 1: //L
            if(xcord != x_min){
                xcord--;
            }
            break;

        case 2: ////R
            if(xcord != x_max){
                xcord++;
            }
            break;

        case 3: //Abajo
            if(ycord != y_min){
                ycord--;
            }
            break;

        case 4: //up
            if(ycord != y_max){
                ycord++;
            }
            break;
    }
}

//Utilitzeu aquesta funció en un programa que inicialment demani a l’usuari els límits d'un quadre (x_min, x_max, y_min, y_max) 
//i comprovi que els límits del quadre són correctes 
//(x_min < x_max i y_min < y_max). Si no ho són, el programa anirà demanant els límits fins que siguin correctes.

int main(){
    
    int x_min, x_max, y_min, y_max, x, y;
    bool LIMOK = false;
    bool yOK = false;
    bool xOK = false;
    int dir = 0;
        while(LIMOK == false){
            cin >> x_min >> x_max >> y_min >> y_max;
            if ((x_min < x_max) && (y_min < y_max)){
                LIMOK = true;
            }
        }
        
/* A continuació, el programa demanarà a l'usuari que introdueixi les coordenades d’un punt (x,y) dins del quadre. Caldrà comprovar que el punt 
és dins dels límits del quadre i si no hi és, el programa ha d'anar demanant les coordenades del punt fins que siguin correctes.
*/
    do{
    cin >> x;
    if ((x >= x_min && x <= x_max)){
        xOK = true;
    }
    }while(xOK == false);
    
    do{
        cin >> y;
        if ((y >= y_min && y <= y_max)){
        yOK = true;
    }
    }while(xOK == false);


    while (dir != 5){
        cin >> dir;
        modificarpos(x, y, dir, x_min, x_max, y_min, y_max);
        cout << "(" << x << "," << y << ")" << endl;
    }
}

  
