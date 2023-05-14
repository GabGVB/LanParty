#include "liste.h"
void RemoveTeam ( Node **head, Node *del,int *no_teams)
{
    Node *headcopy=*head;
    if(*head==del)
    {
        *head=(*head)->next;
        (*no_teams)--;
        free(headcopy);
        return;
    }

    while (headcopy!=NULL)
    {

        if(headcopy->next==del)
        {
            headcopy->next=del->next;
            free(del);
            (*no_teams)--;
            return;

        }
        headcopy=headcopy->next;
    }

}
Node* LowestScore (Node *head,float score_min)
{
    Node *del;
    while(head!=NULL)
    {
        if(head->score<score_min)
        {
            score_min=head->score;
            del=head;
        }
        head=head->next;
    }
    return del;
}

int powof2 (int no_teams)
{
    int pow2=1;
    while(pow2<no_teams>>1)
        pow2=pow2<<1;
    return pow2;
}

void CalculateScore (Node **head)
{
    Node *aux;
    aux=*head;
    while (aux!=NULL)
    {
        aux->score=0;
        for (int i=0; i<aux->no_players; i++)
            aux->score+=aux->team[i].points;
        aux->score/=aux->no_players;
        //printf("%.2f\n",aux->score);
        aux=aux->next;
    }
}

Player* read_teamates (int no_players, FILE *fisD, char *firstName, char *secondName)
{
    Player *Player_stats=(Player*) malloc(sizeof(Player)*no_players);
    int i;
    for (i=0; i<no_players; i++)
    {
        fscanf(fisD,"%s%s%d",firstName,secondName,&Player_stats[i].points);
        Player_stats[i].firstName= strdup(firstName);
        Player_stats[i].secondName= strdup(secondName);
    }
    return Player_stats;
}

void addAtBeginning(Node **head,int no_teams,char *name_team,char *firstName, char *secondName,FILE *fisD)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    int no_players;
    fscanf(fisD,"%d",&no_players);
    fgetc(fisD);
    fgets(name_team,100,fisD);
    name_team[strlen(name_team)-1]='\0';
    newNode->teamName=strdup(name_team);
    newNode->team =read_teamates(no_players, fisD, firstName, secondName);
    newNode->no_players=no_players;
    newNode->next = *head;
    *head = newNode;
}

void display(Node *head, FILE *fisR)
{
    while (head!=NULL)
    {
        fprintf (fisR,"%s\n",head->teamName);
        head=head->next;
    }
}
