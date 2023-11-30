/*
author: Marco Giorgis
date: 02/10/2023
es. 3
testo
*/

#include <stdio.h>
#include <stdlib.h>

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
    int k = 0; 
    for(int *p = vett; p < vett + n; p++){
        printf("inserire il valore in posizione [%d]: ", k);
        scanf("%d", p);
        k++;
    }
}
void scambio(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int vett[], int n){
    int *k, *kmin, *j;
    for (k = vett; k < vett + n-1; k++){
        kmin = k;
        for (j = k+1; j < vett + n; j++){
            if (*kmin > *j) // confronti
                kmin = j;
        }
        if (kmin != k){
            scambio(k, kmin); // scambi
        }
    }
    return;
}
void selectionSort(int v[], int n)
{
    int k, kmin, j;
    for (k = 0; k < n - 1; k++)
    {
        kmin = k;
        for (j = k + 1; j < n; j++)
        {
            if (*(v + kmin) > *(v + j)) // confronti
                kmin = j;
        }
        if (kmin != k)
            scambio((v + k), (v + kmin)); // scambi
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
    stampaVettore(vett, dim);
    selectionSort(vett, dim);
    stampaVettore(vett, dim);
    return 0;
}