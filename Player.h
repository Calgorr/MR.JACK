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
void player_j_random()
{
    system("cls");
    if(player[0].jack)
    {
        int i;
        srand(time(NULL));
        i=rand()%8;
        strcpy(player[0].jack_name,character[i].name);
    }
    else
    {
        int i;
        srand(time(NULL));
        i=rand()%8;
        strcpy(player[1].jack_name,character[i].name);
    }
}
#endif // PLAYER_H_INCLUDED
