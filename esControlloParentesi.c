/*
author: Marco Giorgis
date: 04/12/2023
es. pila 
testo creazione di una pila
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

typedef struct node{
    char parentesi; //char parentesiTonda, parentesiQuadra, parentesiGraffa
    struct node* next;
} Node;

int is_empty(Node* head){
    if(head == NULL)
        return 1;
    else
        return 0;
}

void push(Node **head, Node *element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    } else {
        element->next = *head;
        *head = element;
    }
}

Node* pop(Node** head){
    Node* ret = *head;
    if(is_empty(*head)){
        return NULL;
    } else {
        *head = ret->next;
    }
    return ret;
}

void stampaPila(Node* head){
    Node* l = head;
    while(l != NULL){
        printf("%c\n", l->parentesi);
        l = l->next;
    }
}

void controlloParentesi(char espressione[], int dim){
    Node* head = NULL;
    for(int k = 0; k < dim; k++){ //for(int* k = espressione; k < espressione + dim; k++){
        if(espressione[k] == '(' || espressione[k] == '[' || espressione[k] == '{'){
            Node* element = (Node*) malloc(sizeof(Node));
            element->parentesi = espressione[k];
            push(&head, element);
        } else if (espressione[k] == ')' || espressione[k] == ']' || espressione[k] == '}'){
            if (is_empty(head)){
                exit(1);
            } else {
                Node* removed = pop(&head);
                if((espressione[k] == '(' && removed->parentesi != ')') ||
                    (espressione[k] == '[' && removed->parentesi != ']') ||
                    (espressione[k] == '{' && removed->parentesi != '}'))
                    exit(1);
            }
        }
    }
    stampaPila(head);
    if(is_empty(head))
        printf("\nPARENTESI CORRETTE");
    else
        printf("\nPARENTESI NON CORRETTE");
}
/*
void controlloParentesi(char *espressione, int dim){
    Node* head = NULL;
    for(int *k = espressione; k < espressione + dim; k++){ //for(int* k = espressione; k < espressione + dim; k++){
        if(*k == '(' || *k == '[' || *k == '{'){
            Node* element = (Node*) malloc(sizeof(Node));
            element->parentesi = *k;
            push(&head, element);
        } else if (*k == ')' || *k == ']' || *k == '}'){
            if (is_empty(head)){
                exit(1);
            } else {
                Node* removed = pop(&head);
                if((*k == '(' && removed->parentesi != ')') ||
                    (*k == '[' && removed->parentesi != ']') ||
                    (*k == '{' && removed->parentesi != '}'))
                    exit(1);
            }
        }
    }
    stampaPila(head);
    if(is_empty(head))
        printf("\nPARENTESI CORRETTE");
    else
        printf("\nPARENTESI NON CORRETTE");
}

int lunghezzaStringa(char espressione[]){
    int lung = 0;
    for(int k = 0; espressione[k] != '\0'; k++){
        lung++;
    }
    return lung;
}
*/
int main(){
    char* espressione;
    espressione = (char*) malloc(DIM * sizeof(char));
    printf("inserire un espressione: ");
    scanf("%s", espressione);
    printf("%s\n", espressione);
    int lung = lunghezzaStringa(espressione);
    printf("lung: %d\n", lung);
    controlloParentesi(espressione, lung);
    return 0;
}
