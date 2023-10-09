/*
author: Marco Giorgis
date: 18/09/2023
es. 1
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30
#define NR 30

typedef struct{
    int num;
    char nomeFilm[DIM];
    char tipoFilm[DIM];
    int anno;
    char disp[DIM]; //disponibilità
} Struttura;
/*
void caricaStruttura(Struttura film[]){ //strtok funzione delle stringhe e serve per spezzare una frase
    char nomeFile[DIM] = "listafilm.csv";
    int k = 0;
    FILE *fp;
    fp = fopen(nomeFile, "r");
        while(fscanf(fp, "%d", &film[k].num)!=EOF){
            fscanf(fp,"%s %s %d %s", film[k].nomeFilm, film[k].tipoFilm, &film[k].anno, film[k].disp);
            k++;
        }
    fclose(fp);
}
*/
void caricaStruttura(Struttura film[]){
    char nomeFile[DIM] = "listafilm.csv";
    int k = 0;
    char riga[DIM];
    FILE *fp;
    fp = fopen(nomeFile, "r");
    char *tok;
    while(fgets(riga, DIM, nomeFile) != NULL){
        tok = strtok(riga, ",");
        film[k].num = atoi(tok);
        tok = strtok(NULL, ",");
        strcpy(film[k].nomeFilm, tok);
        tok = strtok(NULL, ",");
        strcpy(film[k].tipoFilm, tok);
        tok = strtok(NULL, ",");
        film[k].anno = atoi(tok);
        tok = strtok(NULL, ",");
        strcpy(film[k].disp, tok);
        k++;
    }
    fclose(fp);
}

void stampaStruttura(Struttura film[], int n){
    for(int k = 0; k < n; k++){
        printf("%d %s %s %d %s\n", film[k].num, film[k].nomeFilm, film[k].tipoFilm, film[k].anno, film[k].disp);
    }
}

main(){
    Struttura film[DIM];
    caricaStruttura(film);
    stampaStruttura(film, DIM);
}
