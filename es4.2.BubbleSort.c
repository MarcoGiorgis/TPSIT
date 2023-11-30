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
    for(int *p = vett; p < vett + n; p++){
        printf("inserire il valore in posizione [%d]:", p);
        scanf("%d", p);
    }
}

void scambio(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort3(int vett[], int n) {
    int *k,sup,sca;
    sup= n-1 ;
    while ( sup>0 ) {
        sca=0 ;
        for (k = vett; k < vett + sup ; k++) {
            if ((*k) > *(k+1)){
                scambio(k, k+1); //si annullano &*
                sca = k - vett;
                }
            }
        sup=sca ;
        }
}
void stampaVettore(int vett[], int n){
    for(int *p = vett; p < vett + n; p++){
        printf("%d ", *p);
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