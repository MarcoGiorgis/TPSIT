/*
author:
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM_RIGA 200
#define NUM_RIGHE 20000

typedef struct {
    int numero;
    char* titolo;
    char* genere;
    int anno;
    char* disponibilita;
} Film;

void cercaAnno(Film array_film[], int anno, int n){
    for(int k = 0; k < n; k++){
        if(array_film[k].anno == anno){
            printf("%d %s %s %d %s", array_film[k].numero, array_film[k].titolo, array_film[k].genere, array_film[k].anno, array_film[k].disponibilita);
        }
    }
}
int main() {
    char filename[] = "listafilm.csv";
    char riga[DIM_RIGA];
    FILE *fp;
    char* campo;
    Film array_film[NUM_RIGHE];
    int counter = 0;
    int annoScelto;

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("il file %s non esiste\n", filename);
        exit(1); //per uscire dal programma e ritorna 1
    }
    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga,","); //legge fino alla virgola
        array_film[counter].numero = atoi(campo); //per convertire una stringa a intero ATUF per convertire la stringa a float
        campo = strtok(NULL,",");
        array_film[counter].titolo = strdup(campo); //funzione che ritorna una copia
        campo = strtok(NULL, ",");
        array_film[counter].genere = strdup(campo);
        campo = strtok(NULL, ",");
        array_film[counter].anno = atoi(campo);
        campo = strtok(NULL, ",");
        array_film[counter].disponibilita = strdup(campo);
        counter++;
    }
    for(int k = 0; k < counter; k++){
        printf("%d %s %s %d %s\n", array_film[k].numero, array_film[k].titolo, array_film[k].genere, array_film[k].anno, array_film[k].disponibilita);
    }
    printf("inserire un anno: ");
    scanf("%d", &annoScelto);
    cercaAnno(array_film, annoScelto, counter);
    return (0);
}
