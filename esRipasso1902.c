#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo
{
    int dato;
    struct Nodo *prossimo;
} Nodo;

typedef struct Coda
{
    Nodo *inizio;
    Nodo *fine;
} Coda;

typedef struct Pila
{
    Nodo *cima;
} Pila;

bool is_empty(Nodo *head)
{
    return head == NULL;
}

void enqueue(Nodo **head, Nodo **tail, Nodo *elem)
{
    if (is_empty(*head))
    {
        *head = elem;
    }
    else
    {
        (*tail)->prossimo = elem;
    }
    *tail = elem;
    elem->prossimo = NULL;
}

Nodo *dequeue(Nodo **head, Nodo **tail)
{
    Nodo *ret = *head;
    if (is_empty(*head))
    {
        printf("\nErrore coda vuota");
        return NULL;
    }
    else
    {
        *head = ret->prossimo;
    }
    if (*head == NULL)
    {
        *tail = NULL;
    }
    return ret;
}

bool is_empty_pila(Nodo *head)
{
    return head == NULL;
}

void push(Nodo **head, Nodo *element)
{
    if (is_empty_pila(*head))
    {
        *head = element;
        element->prossimo = NULL;
    }
    else
    {
        element->prossimo = *head;
        *head = element;
    }
}

Nodo *pop(Nodo **head)
{
    Nodo *ret = *head;
    if (is_empty_pila(*head))
    {
        return NULL;
    }
    else
    {
        *head = ret->prossimo;
    }
    return ret;
}

// Funzione per confrontare due code
int equalsCoda(Coda *coda1, Coda *coda2)
{
    Nodo *nodo1 = coda1->inizio;
    Nodo *nodo2 = coda2->inizio;

    while (nodo1 != NULL && nodo2 != NULL)
    {
        if (nodo1->dato != nodo2->dato)
        {
            return 0;

            nodo1 = nodo1->prossimo;
            nodo2 = nodo2->prossimo;
        }

        return nodo1 == NULL && nodo2 == NULL;
    }
}

int main()
{
    Coda coda1, coda2;
    Pila pila;

    inizializzaCoda(&coda1);
    inizializzaCoda(&coda2);
    inizializzaPila(&pila);

    // Operazioni di inserimento ed estrazione
    inserisciCoda(&coda1, 1);
    inserisciCoda(&coda1, 2);
    inserisciCoda(&coda1, 3);

    inserisciPila(&pila, 3);
    inserisciPila(&pila, 2);
    inserisciPila(&pila, 1);

    printf("Coda 1: %d, %d, %d\n", estraiCoda(&coda1), estraiCoda(&coda1), estraiCoda(&coda1));
    printf("Pila: %d, %d, %d\n", estraiPila(&pila), estraiPila(&pila), estraiPila(&pila));

    // Operazione di confronto
    if (equalsCoda(&coda1, &coda2))
    {
        printf("Le code sono uguali\n");
    }
    else
    {
        printf("Le code non sono uguali\n");
    }

    return 0;
}
