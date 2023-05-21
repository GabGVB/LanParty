#include "cozi_stive.h"
struct arbore
{
    int height;
    char *teamName;
    float score;
    struct arbore *left, *right;
};
typedef struct arbore NodArb;

NodArb * newNode ( float score , char *name_team );

NodArb * insert ( NodArb * node, float score, char *name_team);

void inordine(NodArb*root, FILE *fisR);

int nodeHeight ( NodArb* root );

int max ( int a, int b );

NodArb * rightRotation ( NodArb * z );


NodArb * AVLinsert ( NodArb * node, float score, char *name_team );

void afisAVL(NodArb*root, FILE *fisR);
NodArb* moveBTStoAVL(NodArb*root, FILE *fisR, NodArb *rootAVL);

void swap(Node **a,Node **b);


void bubbleSort(struct Node **start);

void deleteArbore (NodArb **root);
