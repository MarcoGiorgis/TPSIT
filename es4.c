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

#define DIM 100

int chiediDim(int dim_max){
    int x;
    do{
        printf("inserire la dimensione del vettore: ");
        scanf("%d", &x);
    } while (x < 0 || x > dim_max);
    return x;
}

void caricaVettore(int vett[], int n){
    for(int k = 0; k < n; k++){
        printf("inserire il valore in posizione [%d]:", k);
        scanf("%d", (vett + k));
    }
}

void scambio(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort3(int vett[], int n) {
    int k,sup,sca;
    sup= n-1 ;
    while ( sup>0 ) {
        sca=0 ;
        for (k = 0; k < sup ; k++) {
            if (*(vett + k) > *(vett + k+1)){
                scambio((vett + k), (vett + k+1)); //si annullano &*
                sca=k ;
                }
            }
        sup=sca ;
        }
}
void stampaVettore(int vett[], int n){
    for(int k = 0; k < n; k++){
        printf("%d ", *(vett + k));
    }
}
int main(){
    int vett[DIM];
    int dim = chiediDim(DIM);
    caricaVettore(vett, dim);
    bubbleSort3(vett, dim);
    stampaVettore(vett, dim);
    return 0;
}