#include "task1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *createNode (char *numeechipa, int nrjucatori, int punctetotale) //functie pentru a crea noduri in lista
{
    Node *newNode = (Node *) malloc(sizeof (Node)); //alocarea memoriei pentru noduri
    if (newNode==NULL) //verificare daca se aloca
    {
        printf ("eroare1");
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
    FILE *fr = fopen ("r3.out","w");
    if (fr==NULL)
    {
        printf ("eroare2");
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

//Functiile pentru coada

Queue *createQueue()
{
    Queue *q = (Queue *)malloc (sizeof(Queue));
    if (q == NULL)
    {
        printf ("eroare3");
        exit(1);
    }
    q->fata =q ->spate = NULL;
    return q;
}

void enQueue (Queue *q, Node *echipa1, Node *echipa2)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode ==NULL)
    {
        printf ("eroare4");
        exit(1);
    }
    newNode ->echipa1=echipa1;
    newNode ->echipa2=echipa2;
    newNode ->next == NULL;
    if (q ->spate ==NULL)
    {
        q ->fata = q->spate =newNode;
        return NULL;
    }
    q ->spate ->next =newNode;
    q ->spate = newNode;
}

QueueNode *deQueue (Queue *q)
{
    if (q->fata == NULL) return NULL;
    QueueNode *temp = q->fata;
    q->fata =q->fata->next;
    if (q ->fata ==NULL) q->spate =NULL;
    return temp;
}

int isQueueEmpty (Queue *q)
{
    return q->fata ==NULL;
}

void deleteQueue (Queue *q)
{
    while (!isQueueEmpty(q))
    {
        QueueNode *temp = deQueue (q);
        free (temp);
    }
    free (q);
}

//Functiile pentru stiva
void push (StackNode **top, Node *echipa)
{
    StackNode *newNode = (StackNode *)malloc (sizeof(StackNode));
    if(newNode == NULL)
    {
        printf ("eroare5");
        exit(1);
    }
    newNode ->echipa = echipa;
    newNode ->next = *top;
    *top =newNode;
}

Node *pop (StackNode **top)
{
    if (*top == NULL) return NULL;
    StackNode *temp = top;
    *top = (*top)->next;
    Node *echipa =temp -> echipa;
    free (temp);
    return echipa;
}

int isStackEmpty (StackNode *top)
{
    return top == NULL;
}

void deleteStack (StackNode **top)
{
    while (!isStackEmpty(*top))
    {
        StackNode *temp = *top;
        *top = (*top) ->next;
        free(temp);
    }
}
