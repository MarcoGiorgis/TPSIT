/*
author: Marco Giorgis
date: 02/10/2023
es. 3
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 10

void caricaVettore(int vett[], int n){
    for(int *p = vett; p < vett+n; p++){
        printf("inserire il valore in posizione [%d]:", p);
        scanf("%d", p);
    }
}
int sommaVettore(int vett[], int n){
    int somma = 0;
    for(int *p = vett; p < vett + n; p++){
        somma = somma + *p;
    }
    return somma;
}
int main(){
    int risultato;
    int vett[DIM];
    caricaVettore(vett, DIM);
    risultato = sommaVettore(vett, DIM);
    printf("il risultato = %d", risultato);
    return 0;
}