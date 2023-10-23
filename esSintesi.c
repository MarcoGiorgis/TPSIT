/*
author: Marco Giorgis
date: 17/10/2023
es. sintesi
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100


typedef struct{
    char nome[DIM];
    char cognome[DIM];
    int giorno;
    int mese;
    int anno;
} Struttura;

int contaRighe(char nomeFile[]){
    int k = 0;
    FILE *fp;
    char riga[DIM];
    fp = fopen(nomeFile, "r");
    if (fp == NULL){
        printf("file non presente");
    }
    else {
        while (fgets(riga, DIM, fp) != NULL){
            k++;
        }
        fclose(fp);
    }
    return k;
}

int main(){
    char nomeFile[DIM] ="sintesi.csv";
    int dim = contaRighe(nomeFile);
    Struttura *elenco;
    elenco = (Struttura*) malloc(dim * sizeof(Struttura));
    FILE *fp;
    char* campo;
    char* riga;
    int counter = 0;

    fp = fopen(nomeFile, "r");
    if(fp == NULL){
        printf("il file %s non esiste\n", nomeFile);
        exit(1); //per uscire dal programma e ritorna 1
    }
    while(fgets(riga, DIM, fp)){
        campo = strtok(riga," "); //legge fino alla virgola
        (elenco + counter)->nome = strdup(campo); //per convertire una stringa a intero ATUF per convertire la stringa a float
        campo = strtok(NULL," ");
        (elenco + counter)->cognome = strdup(campo); //funzione che ritorna una copia
        campo = strtok(NULL, " ");
        (elenco + counter)->giorno = atoi(campo);
        campo = strtok(NULL, " ");
        (elenco + counter)->mese = atoi(campo);
        campo = strtok(NULL, " ");
        (elenco + counter)->anno = atoi(campo);
        counter++;
    }
    for(int *k = elenco; k < elenco + dim; k++){
        printf("%s %s %d %d %d", k.nome, k.cognome, k.giorno, k.mese, k.anno);
    }
    return 0;
}