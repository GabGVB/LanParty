#include "liste.h"

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
        fprintf (fisR,"%s", head->teamName);
        head=head->next;
    }
    printf("\n");
}
