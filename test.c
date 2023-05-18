#include "arbori.h"


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
    char *name_team,*firstName,*secondName;
    name_team=(char*)malloc(sizeof(char)*100);
    firstName=(char*)malloc(sizeof(char)*20);
    secondName=(char*)malloc(sizeof(char)*20);

    fscanf(fisD,"%d",&no_teams);

    for (i=0; i<no_teams; i++)
        addAtBeginning(&head,no_teams,name_team,firstName,secondName,fisD);

    if(rez==1) display(head,fisR);

    CalculateScore(&head);

    int remaining=powof2(no_teams);

    Node *del=NULL;

    while(no_teams>remaining)
    {
        del=LowestScore(head,999);
        RemoveTeambyAdress(&head,del,&no_teams);
    }
    if (rez>=2) display(head,fisR);
//--------------------------------------------------------------------------------------
    Node *top8;
    top8=NULL;
    Node *aux; ///Pointer pentru parcurgeri
    Queue *q =createQueue();        ///Coada meciurilor
    Node *team1, *team2;           ///Pointeri la echipele scoase din coada.
    Node *qualified, *eliminated; ///Stivele cu echipele calificate/eliminate
    qualified=NULL;
    eliminated=NULL;
    if (rez>=3)
    {
        int winnerFound=0,round=0;
        while (!winnerFound)
        {
            no_teams/=2;
            round++;
            aux=head;
            fprintf(fisR,"\n--- ROUND NO:%d\n",round);
            if (round==1)
                while (aux!=NULL&&aux->next!=NULL)
                {
                    enQueue(q,aux,aux->next);
                    aux=aux->next->next;
                }
            if (q->front==q->rear)
                winnerFound=1;
            while (!QueueisEmpty(q))
            {

                deQueue(q,fisR,&team1,&team2);
                if (team1->score>team2->score)
                {


                    push(&qualified,team1);
                    push(&eliminated,team2);
                    if(no_teams==8)
                        addNewList(&top8,team1->teamName,team1->score);

                    //printf("%s\n",top8->teamName);
                }
                else
                {

                    push(&qualified,team2);
                    push(&eliminated,team1);
                    if(no_teams==8)
                        addNewList(&top8,team2->teamName,team2->score);
                }

            }

            fprintf(fisR,"\nWINNERS OF ROUND NO:%d\n",round);
            while (qualified!=NULL)
            {
                popQualified(&qualified,q,fisR);
            }

            while (eliminated!=NULL)
            {
                popEliminated(&eliminated,&head,no_teams);
            }

        }
    }
    //-----------------------------------------------------------------------------


    if (rez==4)
    {
        NodArb * root = NULL;

        aux=top8;
        while(aux!=NULL)
        {
            //printf("%s\n",aux->teamName);
            root=insert(root,aux->score,aux->teamName);
            aux=aux->next;
        }

        fprintf(fisR,"\nTOP 8 TEAMS:\n");
        inordine(root,fisR);
    }
    return 0;
}
