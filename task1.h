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

//structura pentru un nod din coada
struct QueueNode
{
    Node *echipa1;
    Node *echipa2;
    struct QueueNode *next;
};
typedef struct QueueNode QueueNode;

//structura pentru coada
struct Queue
{
    QueueNode *fata, *spate;
};
typedef struct Queue Queue;

//structura pentru un nod idn stiva
struct StackNode
{
    Node *echipa;
    struct StackNode *next;
};
typedef struct StackNode StackNode;

Node *createNode (char *numeechipa, int nrjucatori, int punctetotale); //functie pentru a crea noduri in lista
void addAtBeginning (Node **head, char *numeechipa, int nrjucatori, int punctetotale); //functie pentru a adauga noduri la inceputul listei
void rezultate (Node*head); //functie pentru a scrie in fisier rezultatele
int numarechipe (Node *head); //functie de numarat echipele din lista
void scoateechipeslabe (Node **head); //functie de a elimina echipa cu cele mai putine puncte

//functiile pentru coada
Queue *createQueue();
void enQueue (Queue  *q, Node *echipa1, Node *echipa2);
QueueNode *deQueue (Queue *q);
int isQueueEmpty (Queue *q);
void deleteQueue (Queue *q);

//functii pentru stiva
void push (StackNode **top, Node *echipa);
Node *pop (StackNode **top);
int isStackEmpty (StackNode *top);
void deleteStack (StackNode **top);
