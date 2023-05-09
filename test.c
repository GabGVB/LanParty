#include "liste.h"

int main(int argc,char**argv)
{
    FILE *fisC, *fisD, *fisR;
    fisC=fopen(argv[1],"r");
    fisD=fopen(argv[2],"r");
    fisR = fopen(argv[3], "w");

    Node *head;
    Player *Player_stats;

    head=NULL;
    int no_teams,i;
    char name_team[100],firstName[20],secondName[20];

    fscanf(fisD,"%d",&no_teams);

    for (i=0; i<no_teams; i++)
        addAtBeginning(&head,no_teams,name_team,firstName,secondName,fisD);

    display(head,fisR);
    return 0;


}
