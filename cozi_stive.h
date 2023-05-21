#include "liste.h"
struct Match
{
    Node *team1,
         *team2;
    struct Match *next;
};
typedef struct Match Match;

struct Q
{
   Match *front, *rear;
};
typedef struct Q Queue;

Queue* createQueue();

int QueueisEmpty(Queue*q);

void enQueue(Queue*q, Node *team1, Node *team2);

void deQueue(Queue*q, FILE* fisR, Node **team1, Node **team2) ;

void push(Node**top, Node *t);

int StiveisEmpty(Node *top);

void popQualified(Node**top,Queue *q, FILE *fisR);


void popEliminated(Node**top, Node**head,int no_teams);

void afisWinners(Node *top, FILE *fisR);
void freeNode_char (Node ** n);
