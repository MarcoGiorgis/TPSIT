/*
author: Marco Giorgis
date: 26/01/2024
es. code
testo creazione di una coda
*/


#include <stdio.h>
#include <stdlib.h>

#define DIM 50

struct Persona { // Nodo della coda che rappresenta una persona
    char nome[DIM];
    char cognome[DIM];
    int eta;
    struct Persona* next;
};

struct Coda { // Struttura della coda
    struct Persona* front; // Puntatore all'ultimo elemento
    struct Persona* rear;
};

// Funzione per creare una coda vuota
struct Coda* creaCoda() {
    struct Coda* coda = (struct Coda*)malloc(sizeof(struct Coda));
    coda->front = coda->rear = NULL;
    return coda;
}

// Funzione per verificare se la coda è vuota
int isEmptyCoda(struct Coda* coda) {
    return coda->front == NULL;
}

// Funzione per ottenere la dimensione della coda
int sizeCoda(struct Coda* coda) {
    int count = 0;
    struct Persona* temp = coda->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
// Funzione per inserire una persona nella coda
void inserisciInCoda(struct Coda* coda) {
    struct Persona* nuovaPersona = (struct Persona*)malloc(sizeof(struct Persona));
    printf("Inserisci il nome: ");
    scanf("%s", nuovaPersona->nome);
    printf("Inserisci il cognome: ");
    scanf("%s", nuovaPersona->cognome);
    printf("Inserisci l'eta: ");
    scanf("%d", &nuovaPersona->eta);

    nuovaPersona->next = NULL;

    if (isEmptyCoda(coda)) {
        coda->front = coda->rear = nuovaPersona;
    } else {
        coda->rear->next = nuovaPersona;
        coda->rear = nuovaPersona;
    }

    printf("Persona inserita nella coda.\n");
}

// Funzione per visualizzare le persone presenti nella coda
void visualizzaCoda(struct Coda* coda) {
    if (isEmptyCoda(coda)) {
        printf("La coda è vuota.\n");
    } else {
        struct Persona* temp = coda->front;
        printf("Persone nella coda:\n");
        while (temp != NULL) {
            printf("Nome: %s, Cognome: %s, Età: %d\n", temp->nome, temp->cognome, temp->eta);
            temp = temp->next;
        }
    }
}
// Funzione per rimuovere la persona più anziana dalla coda
void rimuoviDallaCoda(struct Coda* coda) {
    if (isEmptyCoda(coda)) {
        printf("Errore: la coda è vuota\n");
        return;
    }

    struct Persona* temp = coda->front;
    struct Persona* personaAnziana = temp;
    struct Persona* prev = NULL;

    while (temp != NULL) {
        if (temp->eta > personaAnziana->eta) {
            personaAnziana = temp;
            prev = NULL;
        }
        temp = temp->next;
    }

    if (prev == NULL) {
        coda->front = personaAnziana->next;
    } else {
        prev->next = personaAnziana->next;
    }

    if (coda->front == NULL) {
        coda->rear = NULL;
    }

    printf("Persona rimossa dalla coda: Nome: %s, Cognome: %s, Età: %d\n",personaAnziana->nome, personaAnziana->cognome, personaAnziana->eta);

    free(personaAnziana);
}

// Funzione per liberare la memoria e terminare il programma
void uscitaProgramma(struct Coda* coda) {
    struct Persona* temp;
    while (coda->front != NULL) {
        temp = coda->front;
        coda->front = coda->front->next;
        free(temp);
    }
    free(coda);
    exit(0);
}

int main() {
    struct Coda* coda = creaCoda();
    int scelta;

    do {
        printf("\n1. Inserisci persona nella coda\n");
        printf("2. Visualizza coda\n");
        printf("3. Rimuovi persona più anziana\n");
        printf("4. Uscita dal programma\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                inserisciInCoda(coda);
                break;
            case 2:
                visualizzaCoda(coda);
                break;
            case 3:
                rimuoviDallaCoda(coda);
                break;
            case 4:
                uscitaProgramma(coda);
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (1);
    return 0;
}
