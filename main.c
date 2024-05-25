#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

int main()
{
    FILE *f =fopen ("/home/student/TemaPa/LanParty/date/t1/d.in", "r"); //deschidem fisierul
    if (f ==NULL)
    {
        printf ("eroare"); //verificare daca se deschide
        exit (1);
    }
    int nrechipe;
    fscanf(f,"%d", &nrechipe); //cititm cate echipe sunt in fisier
    Node *head=NULL; //initializam lista
    for(int i=0; i< nrechipe; i++) //citim si adaugam echipa la inceputul listei pentru fiecare echipa din fisier
    {
        int nrjucatori;
        char numeechipa[100];
        fscanf(f, "%d", &nrjucatori);
        fgets(numeechipa,100,f);
        for(int j=0; j< nrjucatori; j++)
        {
            char nume[50], prenume [50];
            int punctejucator;
            fscanf (f, "%s %s %d", nume, prenume, &punctejucator);
        }
        addAtBeginning(&head, numeechipa, nrjucatori); //adaugam echipa la inceputul listei
    }
    fclose(f); //inchidem fisierul
    Node *curent = head;
    while (curent != NULL)
    {
        printf ("%s", curent->numeechipa);
        curent =curent->next;
    }
    return 0;
}

