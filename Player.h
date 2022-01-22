#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Character.h"
typedef struct
{
    int jack;
    int detective;
    char jack_name[50];
    char player1[3];
}Player;
Player player[2];
void player_assign()
{
    printf("The First Player Is Going To Be : 1 For MR.JACK 2 For Detective\n");
            int input;
            scanf("%d",&input);
            if(input==1)
            {
                player[0].jack=1;
                player[0].detective=0;
                player[1].jack=0;
                player[1].detective=1;
            }
            else
            {
                player[0].jack=0;
                player[0].detective=1;
                player[1].jack=1;
                player[1].detective=0;
            }
}
char jack_pile[7][4];
void player_j_random()
{
    system("cls");
    if(player[0].jack)
    {
        int index=0;
        int i;
        srand(time(NULL));
        i=rand()%8;
        strcpy(player[0].jack_name,character[i].name);
        for(int j=0;j<8;j++)
        {
            if(j==i)
                continue;
            strcpy(jack_pile[index],character[0].abrv[j]);
            index++;
        }
    }
    else
    {
        int index;
        int i;
        srand(time(NULL));
        i=rand()%8;
        strcpy(player[1].jack_name,character[i].name);
        for(int j=0;j<8;j++)
        {
            if(j==i)
                continue;
            strcpy(jack_pile[index],character[0].abrv[j]);
            index++;
        }
    }
}
#endif // PLAYER_H_INCLUDED
