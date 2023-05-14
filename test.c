#include "liste.h"

int main(int argc,char**argv)
{
    FILE *fisC, *fisD, *fisR;
    fisC=fopen(argv[1],"r");
    fisD=fopen(argv[2],"r");
    fisR = fopen(argv[3], "w");

    int rez=0,c,i;
    for(i=0; i<5; i++)
    {
        fscanf(fisC,"%d",&c);
        rez+=c;
    }
    Node *head;
    head=NULL;

    int no_teams;
    char name_team[100],firstName[20],secondName[20];

    fscanf(fisD,"%d",&no_teams);

    for (i=0; i<no_teams; i++)
        addAtBeginning(&head,no_teams,name_team,firstName,secondName,fisD);

    CalculateScore(&head);

    if(rez==1) display(head,fisR);

    int remaining=powof2(no_teams);

    Node *del=NULL;

    while(no_teams>remaining)
    {
        del=LowestScore(head,999);
        RemoveTeam(&head,del,&no_teams);
    }
    if (rez==2) display(head,fisR);
    return 0;


}
