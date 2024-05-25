#include "task1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *createNode (char *numeechipa, int nrjucatori) //functie sa cream un nod nou in lista
{
    Node *newNode = (Node *) malloc(sizeof (Node)); //alocarea memoriei pentru nod
    if (newNode==NULL) //verificare alocare
    {
        printf ("eroare");
        exit(1);
    }
    newNode->numeechipa =strdup(numeechipa); //duplicam numele echipei
    newNode->nrjucatori=nrjucatori;
    newNode -> next =NULL; //nodul nou va fi ultimul in lista
    return newNode;
}

void addAtBeginning (Node **head, char *numeechipa, int nrjucatori) //functie de adaugat un nod la inceput
{
    Node *newNode = createNode (numeechipa, nrjucatori); //cream un nod nou
    newNode->next=*head;
    *head=newNode; //actualizam adresa listei
}

void rezultate (Node*head)
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
