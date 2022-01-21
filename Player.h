#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Character.h"
typedef struct
{
    int jack;
    int detective;
    char jack_name[50];
}Player;
Player player[2];
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
