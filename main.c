#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

int main()
{
    FILE *f =fopen ("/home/student/TemaPa/LanParty/date/t5/d.in", "r"); //deschidem fisierul
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
        int punctetotale=0;
        for(int j=0; j< nrjucatori; j++)
        {
            char nume[50], prenume [50];
            int punctejucator;
            fscanf (f, "%s %s %d", nume, prenume, &punctejucator);
            punctetotale += punctejucator; //calculam punctajul total al echipei
        }
        addAtBeginning(&head, numeechipa, nrjucatori, punctetotale); //adaugam echipa la inceputul listei
    }
    fclose(f); //inchidem fisierul
    int echipetotale = numarechipe (head); //numaram echipele din lista
    int n=1;
    while (n*2 <=echipetotale)
    {
        n *= 2;
    } //determinam cea mai mare putere a lui 2 mai mica sau egala cu numarul de echipe
    while (numarechipe(head)>n) //scoatem echipele cu cele mai putine puncte pana ramanem cu n echipe
    {
    scoateechipeslabe (&head);
    }
    rezultate (head); //scriem rezultatele
    Node *curent = head;
    while (curent != NULL)
    {
        printf ("%s", curent->numeechipa); //afisam numele echipelor ramase
        curent =curent->next;
    }
    return 0;
}

