#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node //structura pentru un nod din lista
{
    int nrjucatori;
    char *numeechipa;
    struct Node *next;
};
typedef struct Node Node;

Node *createNode (char *numeechipa, int nrjucatori);
void addAtBeginning (Node **head, char *numeechipa, int nrjucatori);
void rezultate (Node*head);
