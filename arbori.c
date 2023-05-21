#include "arbori.h"
void deleteArbore (NodArb **root)
{
    if (*root)
    {
        deleteArbore(&(*root)->left);
        deleteArbore(&(*root)->right);
        free((*root)->teamName);
        free(*root);
    }

}

void swap(Node **a,Node **b)
{
    float temp = (*a)->score;
    (*a)->score = (*b)->score;
    (*b)->score = temp;

    char *aux;
    aux=strdup ((*a)->teamName);
    free((*a)->teamName);
    (*a)->teamName=strdup((*b)->teamName);
    free((*b)->teamName);
    (*b)->teamName=strdup(aux);
    free(aux);

}

void bubbleSort(struct Node **start)
{
    int swapped, i;
    Node *ptr1;
    Node *lptr = NULL;

    /* Checking for empty list */
    if (*start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = *start;

        while (ptr1->next != lptr)
        {
            if (ptr1->score < ptr1->next->score)
            {
                //printf("%s <-> %s\n",ptr1->teamName, ptr1->next->teamName);
                swap(&ptr1, &ptr1->next);
                swapped = 1;
            }

            if (ptr1->score == ptr1->next->score)
                if (strcmp(ptr1->teamName, ptr1->next->teamName)<0)
                {
                    //  printf("%s <---> %s\n",ptr1->teamName, ptr1->next->teamName);
                    swap(&ptr1, &ptr1->next);
                    swapped = 1;
                }

            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void afisAVL(NodArb*root, FILE *fisR)
{
    NodArb *root_left, *root_right;
    if (root->right!=NULL)
    {
        root_right=root->right;
        if (root_right->right!=NULL)
            fprintf(fisR,"%s\n",root_right->right->teamName);
        if (root_right->left!=NULL)
            fprintf(fisR,"%s\n",root_right->left->teamName);

    }
    if (root->left!=NULL)
    {
        root_left=root->left;
        if (root_left->right!=NULL)
            fprintf(fisR,"%s\n",root_left->right->teamName);
        if (root_left->left!=NULL)
            fprintf(fisR,"%s\n",root_left->left->teamName);
    }
}
int nodeHeight ( NodArb * root )
{
    if ( root == NULL ) return -1;
    else return root -> height ;
}

int max ( int a, int b )
{
    return (( a > b )? a : b );
}



NodArb * rightRotation ( NodArb * z ) //Singura rotatie necesara
{
    NodArb * y = z -> left ;
    NodArb * T3 = y -> right ;
    y -> right = z ;
    z -> left = T3 ;
    z -> height = max ( nodeHeight (z -> left ),
                        nodeHeight (z -> right ))+1;
    y -> height = max ( nodeHeight (y -> left ),
                        nodeHeight (y -> right ))+1;
    return y ;
}
NodArb * newNode ( float score, char *name_team )
{
    NodArb * node = ( NodArb*) malloc ( sizeof ( NodArb));
    node -> score = score ;
    node -> height = 0;
    node ->teamName=strdup(name_team);
    node -> left = node -> right = NULL ;
    return node ;
}
NodArb * AVLinsert ( NodArb * node, float score, char *name_team )
{
    if ( node == NULL ) return newNode ( score, name_team );

    node -> left = AVLinsert ( node -> left, score, name_team );
    //Va fi pus cu siguranta in stanga deoarece datele introduse sunt ordonate descrescator
    node -> height = 1 + max ( nodeHeight ( node -> left ),
                               nodeHeight ( node -> right ));
    int k = ( nodeHeight ( node -> left ) -
              nodeHeight ( node -> right ));
    if ( k > 1)
        return rightRotation ( node );
//Coditie suficienta deoarece se introduc elemente astfel incat arborele se poate dezechilibra doar spre stanga.
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


NodArb* moveBTStoAVL(NodArb*root, FILE *fisR, NodArb *rootAVL)
{
    if (root)
    {
        moveBTStoAVL(root->left,fisR,rootAVL);
        moveBTStoAVL(root->right,fisR,rootAVL);
        rootAVL=AVLinsert(rootAVL,root->score,root->teamName);
    }
    return rootAVL;
}


