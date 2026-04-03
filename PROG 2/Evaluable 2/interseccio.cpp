#include <iostream>


bool cercaElement (int vector[], int mida, int valor)
{
    bool trobat = false;
    for(int i = 0; i < mida; i++)
    {
        if (vector[i] == valor){
            trobat = true;
            i = mida;
        }
    }
    return trobat;
}
void eliminaElement (int vector[], int& mida, int index)
{
    int i = index;
    while(i < (mida - 1))
    {
        vector[i] = vector[i+1];
        i++;
    }
    mida --;
}


void interseccioVectors(int vector1[], int& mida1,int vector2[], int mida2)
{
    int valor_v1;
    for(int s = 0; s < mida1; s++ )
    {
        valor_v1 = vector1[s];
        if(!cercaElement(vector2, mida2, valor_v1))
        {
            eliminaElement(vector1,mida1,s);
            s--;
        }
    }
    

}

//partB
// int trobarInterseccio(int vector1[], int vector2[],int mida1, int mida2)
// {
//     int j = 0;
//     for(j; j < mida1; j++)
//     {
//         for(int s = 0; s < mida2; s++)
//         {
//             if(vector1[j] == vector2[s]){
//                 return vector1[j;]
//             }
//         }
        
//     }
// }

bool trobarEnVector(int vector[], int valor, int mida)
{
    bool trobat = false;
    for(int i = 0; i < mida; i++)
    {
        if (vector[i] == valor)
        {
            trobat = true;
            i = mida;
        }else if (vector[i] > valor) 
        {
            i = mida;//como estan ordenados pues salto si e smayor
        }
    }
    return trobat;

}

void agregarIModificarVector(int valor, int vector[],int& midaVector)
{
    midaVector++;
    vector[midaVector-1] = valor;
}

void interseccioVectorsOrdenats(int vector1[], int mida1, int vector2[], int mida2, int vectorInterseccio[], int& midaInterseccio)
{
    midaInterseccio = 0;
    int j = 0;
    while(j < mida1){

        int valor_V1 = vector1[j];
        if(trobarEnVector(vector2, valor_V1, mida2))
        {
            agregarIModificarVector(valor_V1, vectorInterseccio, midaInterseccio);
        }
        j++;
    }

}
