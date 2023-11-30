/*
author: Giorgis Marco
date:
es.
testo:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 20000
#define LUNG_RIGA 200

typedef struct
{
    char *titolo;
    char *autore;
    int anno;
} Libreria;

int contaRighe(char riga[], Libreria libro[], int cont) 
{
    int n = 0;
    FILE *fp = fopen("listaLibri.csv", "r");
    if (fp == NULL)
    {
        printf("file non presente");
        exit(1);
    }
    while (fgets(riga, LUNG_RIGA, fp))
    {
        n++;
    }
    fclose(fp);
    return n;
}
void caricaLibri(char file[LUNG_RIGA], Libreria libro[], int n)
{
    char *campo;
    Libreria *cont = libro;
    char riga[LUNG_RIGA];

    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("Il file non presente \n");
        exit(1);
    }
    while (fgets(riga, LUNG_RIGA, fp))
    {
        campo = strtok(riga, ",");
        cont->titolo = strdup(campo);
        campo = strtok(NULL, ",");
        cont->autore = strdup(campo);
        campo = strtok(NULL, ",");
        cont->anno = atoi(campo);
        campo = strtok(NULL, ","); // float atof
        cont++;
    }
    fclose(fp);
}

void stampaLibri(Libreria libri[], int n)
{
    for (Libreria *k = libri; k < libri + n; k++)
    {
        printf("Titolo: %s Autore: %s Anno uscita: %d\n", k->titolo, k->autore, k->anno);
    }
}

void cercaAnno(Libreria libro[], int n, int annoScelta)
{
    printf("libri dell'anno %d", annoScelta);
    for (Libreria *k = libro; k < libro + n; k++)
    {
        if (k->anno == annoScelta)
        {
            printf("Titolo: %s Autore: %s\n", k->titolo, k->autore);
        }
    }
}
void scambio(Libreria *a, Libreria *b)
{
    Libreria c;
    c = *a;
    *a = *b;
    *b = c;
}

void ordinaLibri(Libreria libro[], int cont)
{
    Libreria *k;
    int sup, sca;
    sup = cont - 1;
    int j;
    while (sup > 0)
    {
        j = 0;
        sca = 0;
        for (k = libro; k < libro + sup; k++)
        {
            if (k->anno < (k + 1)->anno)
            {
                scambio(k, (k + 1));
                sca = j;
            }
            j++;
        }
        sup = sca;
    }
}

int main()
{
    Libreria *libro;
    char riga[LUNG_RIGA];
    int anno_scelta;
    char file[LUNG_RIGA] = "listaLibri.csv";
    int scelta;

    int n_righe = contaRighe(riga, libro, DIM); 
    libro = (Libreria *)malloc(n_righe * sizeof(Libreria));
    caricaLibri(file, libro, n_righe);
    printf("%d", n_righe);

    do
    {
        printf("inserire la scelta del menu: \n");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 0:
            break;
        case 1:
            stampaLibri(libro, n_righe);
            break;
        case 2:
            printf("inserire anno: \n");
            scanf("%d", &anno_scelta);
            cercaAnno(libro, n_righe, anno_scelta);
            break;
        case 3:
            ordinaLibri(libro, n_righe);
            stampaLibri(libro, n_righe);
            break;
        }
    } while (scelta != 0);

    free(libro);
    return 0;
}