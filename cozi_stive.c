#include "cozi_stive.h"
void freeNode_char (Node ** n)
{
    free((*n)->teamName);
    free(*n);
}

int StiveisEmpty(Node *top)
{
    return top==NULL;
}

void popEliminated(Node**top, Node**head,int no_teams)
{
    if (StiveisEmpty(*top)) return;
    Node *temp=(*top);
    RemoveTeambyValue(&(*head),(*top)->teamName);
    *top=(*top)->next;
    freeNode_char(&temp);
}
int RemainingStive (Node *top)
{
    if (top==NULL) return 0;
    if(top->next!=NULL) return 2;
    return 1;
}
void afisWinners(Node *top, FILE *fisR)
{
    fprintf(fisR,"%-34s-",top->teamName);
    if (top->score<10.00)
        fprintf(fisR,"%6.2f\n",top->score);
    else
        fprintf(fisR,"%7.2f\n",top->score);

}
void popQualified(Node**top,Queue *q, FILE *fisR)
{
    if (!RemainingStive(*top)) return;
    Node *temp=(*top);
    if(RemainingStive(*top)==1)
    {
        afisWinners(*top,fisR);

        *top=(*top)->next;
        freeNode_char(&temp);
    }
    else
    {
        Node *temp1=(*top);
        Node *temp2=temp1->next;
        afisWinners(*top,fisR);
        afisWinners((*top)->next,fisR);

        enQueue(q,*top,(*top)->next);
        *top=(*top)->next->next;
        freeNode_char(&temp1);
        freeNode_char(&temp2);
    }
/**
Stiva cu echipele calificate are numar par de elemente daca nu contine chiar
castigatorul, deci se pot scoate 2 cate 2, formand deja un element al cozii
de la urmatorul pas */

}
void push(Node**top, Node *t)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->teamName= strdup(t->teamName);
    newNode->team=t->team;
    newNode->no_players=t->no_players;
    newNode->score=t->score;
    newNode->next=*top;
    *top=newNode;
}
int QueueisEmpty(Queue*q)
{
    return (q->front==NULL);
}

void copyNode(Node **New, Node *Old)
{
    Node *newNode =(Node*)malloc(sizeof(Node));
    newNode->teamName=strdup(Old->teamName);
    newNode->team=Old->team;
    newNode->no_players=Old->no_players;
    newNode->score=Old->score;
    *New=newNode;
}

void deQueue(Queue*q, FILE* fisR, Node **team1, Node **team2)
{
    Match* aux;
    if (QueueisEmpty(q)) return;

    aux=q->front;
    copyNode(team1,aux->team1);
    copyNode(team2,aux->team2);
    fprintf(fisR,"%-33s-%33s\n",aux->team1->teamName,aux->team2->teamName);
    q->front=(q->front)->next;
    freeNode_char(&aux->team1);
    freeNode_char(&aux->team2);
    free(aux);
}
void enQueue(Queue*q, Node *team1, Node *team2)
{
    Match* newMatch=(Match*)malloc(sizeof(Match));

    if (team1->score>team2->score)
        team1->score+=1;
    else
        team2->score+=1;

    copyNode(&newMatch->team1,team1);
    copyNode(&newMatch->team2,team2);
    newMatch->next=NULL;
    if (q->rear==NULL) q->rear=newMatch;
    else
    {
        (q->rear)->next=newMatch;
        (q->rear)=newMatch;
    }
    if (q->front==NULL) q->front=q->rear;
}
Queue* createQueue()
{
    Queue *q;
    q=(Queue *)malloc(sizeof(Queue));
    if (q==NULL) return NULL;
    q->front=q->rear=NULL;
    return q;
}
