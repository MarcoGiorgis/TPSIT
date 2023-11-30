/*
author: Marco Giorgis
date: 13/11/2023
es. lista 
testo somma in una lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct El
{
    int dato;
    struct El* next;   
}Elemento;

int sommaLista(Elemento* lista, int multiplo){
    int somma = 0;
    Elemento* l = lista;
    int tro = -1;
    while (l != NULL)
    {
        tro = 1;
        if(l->dato % multiplo == 0){
            somma += l->dato;
        }
        l = l->next;
    }
    if(tro == -1){
        somma = -1;
    }
    return somma;
}

void stampaLista(Elemento* lista){
    Elemento* l = lista;
    while (l != NULL)
    {
        printf("%d ", l->dato);
        l = l->next;
    }
}

int main(){
    int n;
    int multiplo;
    Elemento* lista = NULL;
    Elemento* l;
    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Elemento*) malloc(sizeof(Elemento));
                l = lista;
            } else {
                l->next = (Elemento*) malloc(sizeof(Elemento));
                l = l->next;
            }
            l->dato = n;
            l->next = NULL;
        }
    } while (n >= 0);
    stampaLista(lista);
    printf("Inserire un valore: ");
    scanf("%d", &multiplo);
    int somma = sommaLista(lista, multiplo);
    if(somma == -1)
        printf("Nessun dato inserito all'interno della lista");
    else
        printf("\nSomma: %d", somma);
    return 0;
}