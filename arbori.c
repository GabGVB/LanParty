#include "arbori.h"
NodArb * newNode ( float score, char *name_team )
{
    //printf("%f %s\n",score,name_team);
    NodArb * node = ( NodArb*) malloc ( sizeof ( NodArb));
    node -> score = score ;
    node ->teamName=strdup(name_team);
    node -> left = node -> right = NULL ;
    return node ;
}
NodArb * insert ( NodArb * node, float score, char *name_team )
{
    //printf("%s\n",name_team);
    if ( node == NULL ) return newNode ( score, name_team );

    if ( score < node -> score )
        node -> left = insert ( node -> left, score, name_team );
    else if ( score > node -> score )
        node -> right = insert ( node -> right, score, name_team );
    else if (strcmp(name_team,node->teamName)<0)
        node -> left = insert ( node -> left, score, name_team );
    else
        node -> right = insert ( node -> right, score, name_team );

    return node ;
}

void inordine(NodArb*root, FILE *fisR)
{
    if (root)
    {
        inordine(root->right,fisR);

        fprintf(fisR,"%-34s-",root->teamName);
        if (root->score<10.00)
            fprintf(fisR,"%6.2f\n",root->score);
        else
            fprintf(fisR,"%7.2f\n",root->score);
        inordine(root->left,fisR);
    }
}

