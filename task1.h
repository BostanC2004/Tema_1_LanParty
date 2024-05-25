#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node //structura pentru un nod din lista
{
    int nrjucatori;
    char *numeechipa;
    int punctetotale;
    struct Node *next;
};
typedef struct Node Node;

Node *createNode (char *numeechipa, int nrjucatori, int punctetotale); //functie pentru a crea noduri in lista
void addAtBeginning (Node **head, char *numeechipa, int nrjucatori, int punctetotale); //functie pentru a adauga noduri la inceputul listei
void rezultate (Node*head); //functie pentru a scrie in fisier rezultatele
int numarechipe (Node *head); //functie de numarat echipele din lista
void scoateechipeslabe (Node **head); //functie de a elimina echipa cu cele mai putine puncte
