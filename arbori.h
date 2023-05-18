#include "cozi_stive.h"
struct clasament
{
    char *teamName;
    float score;
    struct clasament *left, *right;
};
typedef struct clasament NodArb;

NodArb * newNode ( float score , char *name_team );

NodArb * insert ( NodArb * node, float score, char *name_team);


void inordine(NodArb*root, FILE *fisR);
