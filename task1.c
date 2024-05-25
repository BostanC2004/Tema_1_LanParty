#include "task1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *createNode (char *numeechipa, int nrjucatori, int punctetotale) //functie pentru a crea noduri in lista
{
    Node *newNode = (Node *) malloc(sizeof (Node)); //alocarea memoriei pentru noduri
    if (newNode==NULL) //verificare daca se aloca
    {
        printf ("eroare");
        exit(1);
    }
    newNode->numeechipa =strdup(numeechipa); //duplicam numele echipei
    newNode->nrjucatori=nrjucatori;
    newNode->punctetotale=punctetotale;
    newNode -> next =NULL; //nodul nou va fi ultimul in lista
    return newNode;
}

void addAtBeginning (Node **head, char *numeechipa, int nrjucatori, int punctetotale) //functie de adaugat un nod la inceputul listei
{
    Node *newNode = createNode (numeechipa, nrjucatori, punctetotale); //cream un nod nou
    newNode->next=*head;
    *head=newNode; //actualizam adresa listei
}

void rezultate (Node*head) //functie pentru a scrie in fisier rezultatele
{
FILE *fr = fopen ("/home/student/TemaPa/LanParty/r1.out","w");
if (fr==NULL)
{
        printf ("eroare");
        exit(1);
    }
    Node *curent=head;
    while (curent !=NULL)
    {
    fprintf (fr, "%s", curent->numeechipa);
    curent = curent->next;
    }
    fclose (fr);
}

int numarechipe (Node *head) //functie de numarat echipele din lista
{
    int cnt=0;
    Node *curent =head;
    while (curent != NULL)
    {
        cnt++;
        curent=curent->next;
    }
    return cnt;
}

void scoateechipeslabe (Node **head) //functie de a elimina echipa cu cele mai putine puncte
{
    Node *temp =*head, *prev=NULL;
    Node *minNode = *head, *minPrev = NULL;
    while (temp !=NULL) //cautam echipa cu cele mai putine puncte
    {
        if (temp ->punctetotale < minNode -> punctetotale)
        {
            minNode =temp;
            minPrev=prev;
        }
        prev=temp;
        temp = temp ->next;
    }
    if (minPrev==NULL) //eliminam echipa pe care o gasim
    {
        *head = minNode ->next;
    }
    else minPrev->next =minNode->next;
}
