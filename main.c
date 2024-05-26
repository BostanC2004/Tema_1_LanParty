#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

int main()
{
    FILE *f =fopen ("date/t5/d.in", "r"); //deschidem fisierul
    if (f ==NULL)
    {
        printf ("eroare6"); //verificare daca se deschide
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

    Queue *matchQueue = createQueue();
    StackNode *castigatori =NULL;
    StackNode *pierzatori = NULL;
    Node *curent = head;
    while (curent !=NULL && curent ->next != NULL)
    {
        enQueue (matchQueue, curent, curent ->next);
        curent =curent->next->next;
    }
    while (!isQueueEmpty(matchQueue))
    {
        FILE *fr = fopen ("r3.out", "a");
        if (fr == NULL)
        {
            printf("eroare7");
            exit (1);
        }
        fprintf (fr, "Meciuri: \n");
        QueueNode *match;
        while ((match = deQueue(matchQueue))!=NULL)
        {
            fprintf (fr, "%s vs %s \n", match ->echipa1->numeechipa, match ->echipa2->numeechipa);
            if (match ->echipa1->punctetotale >=match ->echipa2->punctetotale )
            {
                match->echipa1->punctetotale +=1;
                push (&castigatori, match ->echipa1);
                push (&pierzatori, match ->echipa2);
            }
            else
            {
                match ->echipa2->punctetotale +=1;
                push (&castigatori, match ->echipa2);
                push (&pierzatori, match ->echipa1);
            }
        }
        fclose (fr);
    }
    FILE *frezultat = fopen("results(3).out", "w");
    if (frezultat ==NULL)
    {
        printf ("eroare8");
        exit (1);
    }
    fprintf (frezultat, "\nCastigatorii turneului: \n");
    while (!isStackEmpty(castigatori))
    {
        Node *castigatori = pop (&castigatori);
        fprintf (frezultat, "%s\n",castigatori->numeechipa);
    }
    fprintf (frezultat, "\nPierzatorii turneului: \n");
    while (!isStackEmpty(pierzatori))
    {
        Node *pierzatori = pop (&pierzatori);
        fprintf (frezultat, "%s\n", pierzatori->numeechipa);
    }
    fclose(frezultat);
    deleteQueue(matchQueue);
    deleteStack(&castigatori);
    deleteStack (&pierzatori);


    return 0;
}

