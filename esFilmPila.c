#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct film{
    char* titolo;
    int anno;
    char* genere;
    struct film* next;
}Film;

int chiediDim(int dim_max){
    int x;
    do{
        printf("inserire il numero massimo [%d]: ", dim_max);
        scanf("%d", &x);
    } while (x > dim_max || x <= 0);
    return x;
}

int is_empty(Film *head)
{
    if(head == NULL)
        return 1;
    else
        return 0;
}

void push(Film **head, Film *element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    } else {
        element->next = *head;
        *head = element;
    }
}

Film* pop(Film** head){
    Film* ret = *head;
    if(is_empty(*head)){
        return NULL;
    } else {
        *head = ret->next;
    }
    return ret;
}

void stampaPila(Film* head){
    Film* l = head;
    while (l != NULL){
        printf("%s ", l->titolo);
        printf("%d ", l->anno);
        printf("%s \n", l->genere);
        l = l->next;
    }
}

int main(){
    int DIM = 100;
    char titolo[DIM];
    int anno;
    int genere[DIM];

    Film* head = NULL;
    int dim = chiediDim(DIM);
    printf("%d\n", dim);

    for(int k = 0; k < dim; k++){
        printf("inserire il titolo, l'anno e il genere: ");
        scanf("%s %d %s", titolo, &anno, genere);
        Film* element = (Film*) malloc(sizeof(Film));
        element->titolo = strdup(titolo);
        element->anno = anno;
        element->genere = strdup(genere);
        push(&head, element);
    }
    
    stampaPila(head);
    Film* removed = pop(&head);
    printf("Elemento rimosso: %s %d %s\n", removed->titolo, removed->anno, removed->genere);
    stampaPila(head);
    return 0;
}