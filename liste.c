#include "liste.h"

void freePlayer(Player **p, int no_player)
{
    for (int i=0; i<no_player; i++)
    {
        free((*p)[i].firstName);
        free((*p)[i].secondName);
    }
}
void freeNode (Node **n)
{
    freePlayer(&(*n)->team,(*n)->no_players);
    free((*n)->team);
    free((*n)->teamName);
    free(*n);
}
void deleteList ( Node ** head )
{
    Node * headcopy ;
    while (* head != NULL )
    {
        headcopy =(* head ) -> next ;
        free (* head );
        * head = headcopy ;
    }
    * head = NULL ;
}
void RemoveTeambyAdress ( Node **head, Node *del,int *no_teams)
{
    Node *headcopy=*head;
    if(*head==del)
    {
        *head=(*head)->next;
        (*no_teams)--;
        freeNode(&headcopy);
        return;
    }

    while (headcopy!=NULL)
    {

        if(headcopy->next==del)
        {
            headcopy->next=del->next;
            freeNode(&del);
            (*no_teams)--;
            return;
        }
        headcopy=headcopy->next;
    }
}

void RemoveTeambyValue ( Node **head, char *name_team)
{
    if (*head==NULL) return;
    Node *headcopy=*head;
    if(strcmp((*head)->teamName,name_team)==0)
    {
        *head=(*head)->next;
        // (*no_teams)--;
        freeNode(&headcopy);
        return;
    }

    Node *prev=*head;
    while (headcopy!=NULL)
    {

        if(strcmp(headcopy->teamName,name_team)!=0)
        {
            prev=headcopy;
            headcopy=headcopy->next;
        }
        else
        {
            prev->next=headcopy->next;
            freeNode(&headcopy);
            return;
        }
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
    while(pow2<=no_teams>>1)
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

int charinvalid (char c)
{
    if (c>='a'&&c<='z') return 0;
    if (c>='A'&&c<='Z') return 0;
    if (c>='0'&&c<='9') return 0;
    return 1;
}
void addAtBeginning(Node **head,int no_teams,char *name_team,char *firstName, char *secondName,FILE *fisD)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    int no_players;
    fscanf(fisD,"%d",&no_players);
    fgetc(fisD);
    fgets(name_team,100,fisD);
    int len=strlen(name_team)-1;
    while (charinvalid(name_team[len]))
    {
        name_team[len]='\0';
        len--;
    }

    newNode->teamName=strdup(name_team);
    newNode->team =read_teamates(no_players, fisD, firstName, secondName);
    newNode->no_players=no_players;
    newNode->next = *head;
    *head = newNode;
}


void addNewList (Node **head, char*name_team, float score)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    //printf("%s\n",name_team);
    newNode->teamName=strdup(name_team);
    //printf("%s\n",newNode->teamName);
    newNode->score=score;
    newNode->next=*head;
    *head=newNode;
}

void display(Node *head, FILE *fisR)
{
    while (head!=NULL)
    {
        fprintf (fisR,"%s\n",head->teamName);
        head=head->next;
    }
}
