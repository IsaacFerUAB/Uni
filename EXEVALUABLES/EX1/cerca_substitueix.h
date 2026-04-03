#ifndef CERCA_SUBSTITUEIX_H
#define CERCA_SUBSTITUEIX_H

const int MAX_STRING = 100;

int cercaSubstitueix(char text[], char stringCerca[], char nouString[]);
bool cercaString(char text[], char str[], int& posicio);
void substitueixString(char text[], int posicio, char stringOriginal[], char nouString[]);
#endif
