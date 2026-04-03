#ifndef INTERSECCIO_H
#define INTERSECCIO_H


//partA;
bool cercaElement (int vector[], int mida, int valor);
void interseccioVectors(int vector1[], int& mida1,int vector2[], int mida2);
void eliminaElement (int vector[], int& mida, int index);

//partb
bool trobarEnVector(int vector[], int valor, int mida);
void agregarIModificarVector(int valor, int vector[],int& midaVector);
void interseccioVectorsOrdenats(int vector1[], int mida1, int vector2[], int mida2, int vectorInterseccio[], int& midaInterseccio);




#endif
