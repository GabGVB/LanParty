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
};

typedef struct Node Node;
typedef struct Player Player;


Player* read_teamates (int no_players, FILE *fisD, char *firstName, char *secondName);

void addAtBeginning(Node **head,int no_teams,char *name_team,char *firstName, char *secondName,FILE *fisD);

void display(Node *head,FILE *fisR);