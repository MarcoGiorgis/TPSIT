/*
author: Marco Giorgis
date: 13/11/2023
es. 2 lista
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct El
{
    int s;
    struct El *next;
} ElementoLista;

void stampaLista(ElementoLista* lista){
    ElementoLista* l = lista;
    while (l != NULL)
    {
        printf("%d ", l->s);
        l = l->next;
    }
}

int funzioneFirstEven(ElementoLista* lista){
    ElementoLista* l = lista;
    int pos = 0;
    while (l != NULL)
    {
        if(l->s % 2 == 0){
            return pos;
        }
        else{
            l = l->next;
        }
        pos++;
    }  
    return NULL;     
}

int main()
{
    int n;
    ElementoLista* lista = NULL;
    ElementoLista* l;
    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (ElementoLista*) malloc(sizeof(ElementoLista));
                l = lista;
            } else {
                l->next = (ElementoLista*) malloc(sizeof(ElementoLista));
                l = l->next;
            }
            l->s = n;
            l->next = NULL;
        }
    } while (n >= 0);
    stampaLista(lista);
    int pos = funzioneFirstEven(lista);
    if(pos == NULL)
        printf("non sono presenti elementi pari nella lista");
    else
        printf("Posizione primo elemento pari: %d", pos);
    return 0;
}