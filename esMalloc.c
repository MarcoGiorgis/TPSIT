/*
author: Marco Giorgis
date: 21/10/2023
es. malloc
testo
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 100

int chiediDim(int dim_max){
    int x;
    do{
        printf("Inserire la dimensione dell'array: ");
        scanf("%d", &x);
    } while (x < 0 || x > dim_max);
    return x;
}
void caricaVettore(int vett[], int n){
    for(int *k = vett; k < vett + n; k++){
        printf("inserire il valore: ");
        scanf("%d", k);
    }
}
void stampaVettore(int vett[], int n){
    for(int *k = vett; k < vett + n; k++){
        printf("%d ", *k);
    }
}
int main(){
    int dim = chiediDim(DIM);
    int *vett = (int*) malloc(dim * sizeof(int));
    caricaVettore(vett, dim);
    stampaVettore(vett, dim);
    free(vett);
    return 0;
}