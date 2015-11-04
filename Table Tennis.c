/*************************************************************** 
*    TableTennis.C                                             *   
*    Enter winners and show's who won the game at the end      * 
*    Sheel Shah                                                *         
*    12/11/2014                                                * 
****************************************************************/  
#include <stdio.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
#include <string.h>  
  
#define LIM 30  
#define PLAYERS 16  
#define WON 15  
#define WINNER 8  
#define SEMI 4  
#define FINALS 2  
  
/* User defined functions list */  
void getPlayersNames(int x,char players[][LIM]);  
void getMenu(int x, int score[5], int score1[5],char players[][LIM],char winner[][LIM], char semi[][LIM],char finals[][LIM], char champ[][LIM]);  
void getMatchOne(int x,int score[5], int score1[5], char players[][LIM], char winner[][LIM]);  
void roundOne(int x,int score[5], int score1[5], char players[][LIM],char winner[][LIM]);  
void getQuaterFinals(int x,int score[5], int score1[5],char players[][LIM],char winner[][LIM], char semi[][LIM]);  
void roundTwo(int x,int score[5], int score1[5], char players[][LIM],char winner[][LIM], char semi[][LIM]);  
void getSemiFinals(int x,int score[5], int score1[5], char players[][LIM],char winner[][LIM], char semi[][LIM],char finals[][LIM]);  
void roundThree(int x,int score[5], int score1[5], char players[][LIM],char winner[][LIM], char semi[][LIM],char finals[][LIM]);  
void getFinals(int x,int score[5], int score1[5],char players[][LIM],char winner[][LIM], char semi[][LIM],char finals[][LIM], char champ[][LIM]);  
void roundFour(int x,int score[5], int score1[5], char players[][LIM],char winner[][LIM], char semi[][LIM],char finals[][LIM], char champ[][LIM]);   /* User Defined Fuction*/  
  
int main(void)  
{  
    char players[PLAYERS][LIM], winner[PLAYERS/2][LIM],semi[WINNER/2][LIM],finals[SEMI/2][LIM],champ[FINALS/2][LIM];  
    int x;  
    int menu2 = 0;   
    int score[5];  
    int score1[5];  
  
      
    getPlayersNames(x,players);  
    system("cls");  
    while(menu2 !=8)  
    {  
    printf("\n______________________________________________________________________________");  
    printf("\t\t\t\t 1. Enter Game Result \n");  
    printf("\t\t\t 2. Qualifiers winners \n");  
    printf("\t\t\t 3.Quarter winners \n");  
    printf("\t\t\t 4.Semi Final \n");  
    printf("\t\t\t 5.Final winners\n");  
    printf("\t\t\t 6. Display the previous round \n");  
    printf("\t\t\t 7. Return to Main Menu\n\n");  
    printf("\n______________________________________________________________________________");  
    do  
    {  
    printf("\nOption: ");  
    scanf("%i", &menu2);  
    }while(menu2 == '1' && menu2 == '2' && menu2 == '3' && menu2 == '4' && menu2 == '5' && menu2 == '6' && menu2 == '7' && menu2 == '8');  /* Code taken from my previous coursework, ".0 the cost for paint" , a Do while loop so they can only enter them numbers*/  
       
    switch (menu2)   
    {  
        case 1:   
        {          
            getMatchOne(x,score,score1,players,winner); /*Enter results*/  
            roundOne(x,score,score1,players,winner);              
            getQuaterFinals(x,score,score1,players,winner,semi);  
            roundTwo(x,score,score1,players,winner,semi);  
            getSemiFinals(x,score,score1,players,winner,semi,finals);  
            roundThree(x,score,score1,players,winner,semi,finals);  
            getFinals(x,score,score1,players,winner,semi,finals,champ);  
            roundFour(x,score,score1,players,winner,semi,finals,champ);  
              
            break;  
        }  
        case 2:   
        {  
            roundOne(x,score,score1,players,winner); /*Displays round 1 result*/  
            break;  
        }  
        case 3:   
        {  
            roundTwo(x,score,score1,players,winner,semi); /*Displays round 2 result*/  
            break;  
        }  
        case 4:   
        {  
            roundThree(x,score,score1,players,winner,semi,finals); /*Displays round 3 result*/  
            break;  
        }  
        case 5:   
        {  
            roundFour(x,score,score1,players,winner,semi,finals,champ);/*Displays round 4 result*/  
            break;  
        }  
        case 6:   
        {  
            for (x = 16; x > 0 ; x--)  /*Displays previous round result*/  
            roundFour(x,score,score1,players,winner,semi,finals,champ);  
            roundThree(x,score,score1,players,winner,semi,finals);  
            roundTwo(x,score,score1,players,winner,semi);  
            roundOne(x,score,score1,players,winner);  
            break;  
        }  
        case 7:   
        {  
            menu2 = 1;  
            break;  
        }  
        default:   
        {  
        }  
    }  
}  
return 0;  
}  
  
void getPlayersNames(int x, char players[][LIM])   
{  
  
    printf("\n______________________________________________________________________________");   
    printf("\n\t\tPlease enter all 16 participants names"); /*Entering 16 names*/  
    printf("\n______________________________________________________________________________");  
    for (x = 1 ; x < 17; x++)  
    {  
        printf("\nParticipants %d name: ",x);  
        scanf("%s",players[x]);  
        fflush(stdin);  
    }  
  
}  
  
void getMatchOne(int x, int score[5], int score1[5],char players[][LIM], char winner[][LIM]) /*First Round */  
{        
    for (x = 0; x < 16; x += 2)  
    {        
        system("cls");  
        printf("\n______________________________________________________________________________");  
        printf("\n\t\t\t\tParticipant %s",players[x]);  
        printf("\n\t\t\t\t VERSUS");  
        printf("\n\t\t\t\tParticipant %s",players[x+1]);  
        printf("\n______________________________________________________________________________");  
        printf("\nPlease enter the scores for player %s in the form of V,W,X,Y,Z,...\n Player %s: ",players[x],players[x]);  
        scanf("%d,%d,%d,%d,%d",&score[1],&score[2],&score[3],&score[4],&score[5]);  
        fflush(stdin);  
        printf("\nPlease enter the scores for player %s in the form of V,W,X,Y,Z...\nPlayer %s: ",players[x+1],players[x+1]);  
        scanf("%d,%d,%d,%d,%d",&score1[1],&score1[2],&score1[3],&score1[4],&score1[5]);  
        fflush(stdin);  
        printf("[%d] | [%d] | [%d] | [%d] | [%d]  ",score[1],score[2],score[3],score[4],score[5]);/*printf("\nPlayer %s has won ,winner[x*2]);*/
			
        printf("\n[%d] | [%d] | [%d] | [%d] | [%d]  ",score1[1],score1[2],score1[3],score1[4],score1[5]);  
        if(score[1]+score[2]+score[3]+score[4]+score[5] > score1[1]+score1[2]+score1[3]+score1[4]+score1[5])  
        {  
            									/*printf("player %s has won!", winner[x]); Copies Players into a winners array ( Winners only ))*/  
            strcpy(winner[x],players[x]);  
        }  
        else if(score[1]+score[2]+score[3]+score[4]+score[5] < score1[1]+score1[2]+score1[3]+score1[4]+score1[5])  
        {  
            printf("Player %s as won!", winner[x+1]);  
            strcpy(winner[x+1],players[x+1]);  
        }  
        printf("\n");  
        system("pause");  
        system("cls");  
    }  
         
}  
   
void getQuaterFinals(int x,int score[5], int score1[5], char players[][LIM],char winner[][LIM], char semi[][LIM])  
{   
    system("cls");  
    for (x = 1; x <8; x += 2) /* Gets all the names from winner[x] and  [x+1]. */  
    {        
        printf("\n______________________________________________________________________________");  
        printf("\n\t\t\tQuater Finals Participant %s",winner[x]);  
        printf("\n\t\t\t\t VERSUS");  
        printf("\n\t\t\tQuater Finals Participant %s",winner[x+1]);  
        printf("\n______________________________________________________________________________");  
         
        printf("\nPlease enter the scores for player %s in the form of V,W,X,Y,Z,...\n Player %s: ",winner[x],winner[x]);  
        scanf("%d,%d,%d,%d,%d",&score[1],&score[2],&score[3],&score[4],&score[5]);  
        fflush(stdin);  
        printf("\nPlease enter the scores for player %s in the form of V,W,X,Y,Z...\nPlayer %s: ",winner[x+1],winner[x+1]);  
        scanf("%d,%d,%d,%d,%d",&score1[1],&score1[2],&score1[3],&score1[4],&score1[5]);  
        fflush(stdin);  
        printf("[%d] | [%d] | [%d] | [%d] | [%d]  ",score[1],score[2],score[3],score[4],score[5]);  
        printf("\n[%d] | [%d] | [%d] | [%d] | [%d]  ",score1[1],score1[2],score1[3],score1[4],score1[5]);  
        if(score[1+2+3+4+5] > score1[1+2+3+4+5])  
        {  
            /*winner[x]=players[x];*/  
            strcpy(semi[x],winner[x]);  /* Transfers the winner[2x] to semi[x] which is a smaller array */  
            printf("\nPlayer %s has won ",semi[x]);                      
        }  
        else if(score[1+2+3+4+5] < score1[1+2+3+4+5])  
        {        
            strcpy(semi[x+1],winner[x+1]);  
            printf("\nPlayer %s has won",semi[x+1]);  
        }             
    printf(" \n");  
    system("pause");  
    system("cls");  
    }            
                         
}        
   
void getSemiFinals(int x,int score[5], int score1[5], char players[][LIM],char winner[][LIM], char semi[][LIM],char finals[][LIM])  
   
{  
    for (x = 1; x < 4; x +=2) /* 4 players are held */  
    {      
        system("cls");  
        printf("\n______________________________________________________________________________");  
        printf("\n\t\t\tSemi Finals Participant %s",semi[x]);  
        printf("\n\t\t\t\t VERSUS");  
        printf("\n\t\t\tSemi Finals Participant %s",semi[x+1]);  
        printf("\n______________________________________________________________________________");  
         
        printf("\nPlease enter the scores for player %s in the form of V,W,X,Y,Z,...\n Player %s: ",semi[x],semi[x]);  
        scanf("%d,%d,%d,%d,%d",&score[1],&score[2],&score[3],&score[4],&score[5]);  
        fflush(stdin);  
        printf("\nPlease enter the scores for player %s in the form of V,W,X,Y,Z...\nPlayer %s: ",semi[x+1],semi[x+1]);  
        scanf("%d,%d,%d,%d,%d",&score1[1],&score1[2],&score1[3],&score1[4],&score1[5]);  
        fflush(stdin);  
        printf("[%d] | [%d] | [%d] | [%d] | [%d]  ",score[1],score[2],score[3],score[4],score[5]);  
        printf("\n[%d] | [%d] | [%d] | [%d] | [%d]  ",score1[1],score1[2],score1[3],score1[4],score1[5]);  
   
   
        if(score[1+2+3+4+5] > score1[1+2+3+4+5])  
        {  
           /*winner[x]=players[x];*/  
            strcpy(finals[x],semi[x]);  
            printf("\nPlayer %s has won ",finals[x]);  /*Semi array is transferred to Finals*/                        
        }  
                 
        else if(score[1+2+3+4+5] < score1[1+2+3+4+5])  
        {  
            strcpy(finals[x+1],semi[x+1]);  
            printf("\nPlayer %s has won",finals[x+1]);  
        }  
        printf(" \n");  
        system("pause");  
        system("cls");  
    }            
}          
   
void getFinals(int x, int score[5], int score1[5],char players[][LIM],char winner[][LIM], char semi[][LIM],char finals[][LIM], char champ[][LIM])  
   
{  
    for(x = 1; x < 2 ; x++)    
    {  
      
        system("cls");  
        printf("\n______________________________________________________________________________");  
        printf("\n\t\t\t\tFinals Participant %s",finals[x]); /* No for statement needed as only 2 players are left. They will go into Final[x] or Final[x+1]*/  
        printf("\n\t\t\t\t VERSUS");  
        printf("\n\t\t\t\tFinals Participant %s",finals[x+1]);  
        printf("\n______________________________________________________________________________");  
         
        printf("\nPlease enter the scores for player %s in the form of V,W,X,Y,Z,...\n Player %s: ",finals[x],finals[x]);  
        scanf("%d,%d,%d,%d,%d",&score[1],&score[2],&score[3],&score[4],&score[5]);  
        printf("\nPlease enter the scores for player %s in the form of V,W,X,Y,Z...\nPlayer %s: ",finals[x+1],finals[x+1]);  
        fflush(stdin);  
        scanf("%d,%d,%d,%d,%d",&score1[1],&score1[2],&score1[3],&score1[4],&score1[5]);  
        fflush(stdin);  
        printf("[%d] | [%d] | [%d] | [%d] | [%d]  ",score[1],score[2],score[3],score[4],score[5]);  
        printf("\n[%d] | [%d] | [%d] | [%d] | [%d]  ",score1[1],score1[2],score1[3],score1[4],score1[5]);  
                  
        if(score[1+2+3+4+5] > score1[1+2+3+4+5])  
        {  
            strcpy(champ[x],finals[x]);  
            printf("\nPlayer %s has won! Congratulations!",champ[x]);                          
        }  
                 
        else if(score[1+2+3+4+5] < score1[1+2+3+4+5])  
        {  
            strcpy(champ[x+1],finals[x+1]);  
            printf("\nPlayer %s has won! Congratulations!",champ[x+1]);  
        }  
    return;  
                
    }            
                                 
}  
  
/* This section shows who won per round at the end of the overall match*/  
void roundOne(int x,int score[5], int score1[5],char players[][LIM],char winner[][LIM])     /*Qualifiers*/  
{  
      
  
    for (x = 1; x <17; x +=2)   
    {  
        if (score[1+2+3+4+5] > score1[1+2+3+4+5])   
        {  
              
            strcpy(winner[x],players[x]);  
            printf("\nPlayer %s has won ",winner[x]);  
        }  
        else if (score[1+2+3+4+5] < score1[1+2+3+4+5])   
        {  
            strcpy(winner[x+1],players[x+1]);  
            printf("\nPlayer %s has won",winner[x+1]);  
        }  
      
    }  
        system("pause");  
        printf(" \n");  
        system("cls");  
        return;  
      
}  
void roundTwo(int x,int score[5], int score1[5], char players[][LIM],char winner[][LIM], char semi[][LIM]) /* Quatar Finals*/  
{  
    for (x = 0; x <8; x +=2)  
    {  
        if (score[1+2+3+4+5] > score1[1+2+3+4+5])   
        {  
              
            strcpy(semi[x],winner[x]);  
            printf("\nPlayer %s has won ",semi[x]);  
        }  
        else if (score[1+2+3+4+5] < score1[1+2+3+4+5])   
        {  
            strcpy(semi[x+1],winner[x]);  
            printf("\nPlayer %s has won",semi[x+1]);  
        }  
    }  
    system("pause");  
    printf(" \n");  
    system("cls");  
    return;  
}  
void roundThree(int x,int score[5], int score1[5], char players[][LIM],char winner[][LIM], char semi[][LIM],char finals[][LIM])/* Semi Finals*/  
{  
    for (x = 0; x < 4; x +=2)  
    {  
        if (score[1+2+3+4+5] > score1[1+2+3+4+5])   
        {  
          
            strcpy(finals[x],semi[x]);  
            printf("\nPlayer %s has won ",finals[x]);  
        }  
        else if (score[1+2+3+4+5] < score1[1+2+3+4+5])   
        {  
            strcpy(finals[x+1],semi[x]);  
            printf("\nPlayer %s has won",finals[x+1]);  
        }     
    }  
        system("pause");  
        printf(" \n");  
        system("cls");  
        return;  
      
}  
void roundFour(int x,int score[5], int score1[5], char players[][LIM],char winner[][LIM], char semi[][LIM],char finals[][LIM], char champ[][LIM])/*Finals*/  
{  
  
  
    for (x = 0; x < 2; x +=2)  
    {   
          
        if (score[1+2+3+4+5] > score1[1+2+3+4+5])   
        {  
          
            strcpy(champ[x],finals[x]);  
            printf("\nPlayer %s has won! Congratulations",champ[x]);  
        }  
        else if (score[1+2+3+4+5] < score1[1+2+3+4+5])   
        {  
            strcpy(champ[x+1],finals[x]);  
            printf("\nPlayer %s has won! Congratulations",champ[x+1]);  
        }  
    }  
        system("pause");  
        printf(" \n");  
        system("cls");  
        return;  
      
}  

