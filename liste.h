#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Player
{
    char *firstName;
    char *secondName;
    int points;
};
struct Node
{
    char *teamName;
    struct Player *team;
    struct Node   *next;
    int no_players;
    float score;
};


typedef struct Node Node;
typedef struct Player Player;


Player* read_teamates (int no_players, FILE *fisD, char *firstName, char *secondName);

int isletter (char c);

void addAtBeginning(Node **head,int no_teams,char *name_team,char *firstName, char *secondName,FILE *fisD);

void addNewList (Node **head, char*name_team, float score);

void display(Node *head,FILE *fisR);

void CalculateScore (Node **head);

int powof2 (int no_teams);

Node* LowestScore (Node *head,float score_min);

void RemoveTeambyAdress ( Node **head, Node *del,int *no_teams);

void RemoveTeambyValue ( Node **head, char *name_team);
