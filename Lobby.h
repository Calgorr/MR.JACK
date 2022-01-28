#ifndef LOBBY_H_INCLUDED
#define LOBBY_H_INCLUDED
#include "Game_Leading_header.h"
#include "bin_file_load.h"
void setting();
void print_menu();
void change_color(int Color_counter);
static int Color_counter;
void Welcome()
{
    char str[1000]="Welcome To MR.JACK\nPress Enter To Continue\n";
    for(int i=0;i<strlen(str);i++)
    {
        printf("%c",str[i]);
        if(i<32||(i>53&&i<76))
            continue;
        delay1(0.07);
    }
    gets(str);
    system("cls");
    print_menu();
}
void print_menu()
{
    printf("1)Start A New Game\n");
    printf("2)Load An Existing Game\n");
    printf("3)Tutorial\n");
    printf("4)Setings\n");
    printf("5)Quit\n");
    int input;
    scanf("%d",&input);
    switch (input)
    {
        case 1:
            multi_map();
            assign_character();
            assign_node();
            player_assign();
            Round();
            break;
        case 2:
            assign_character();
            assign_node();
            load_file();
            break;
        case 3:{
            system("cls");
            char str[]="So First We Are Going To Talk About The Abbreviations That Will Be Used In The Game\nL Stands For Lamp AND l For An Off Lamp\n\
T Is For Tunnel and t Is For A Blocked Tunnel As Well As N Which Stands For NULL (Means Out of Map) and n Is for Blocked Exits\n\
And The Number Used In Front Of These Characters Are Just For Specifying Each Character\n\
For John H. Watson We Have 6 Directions 1 Is North 2 North East 3 South East 4 South 5 South West And 6 North West\n\
When You Want To Move You Will Give The Program A String Of 6 Different Character,Each One Represents A Specific Direction\n\
A Is North W North East E South East D South X South West And Z North West\nThat Is All Enjoy The Game";
            for(int i=0;i<strlen(str);i++)
            {
                printf("%c",str[i]);
                delay1(0.052);
            }
            delay1(5.0);
            int input1;
            printf("\n****Would You Like To Get Back To The Main Menu? If Yes Please Enter 1 Otherwise 0\n");
            scanf("%d",&input1);
            if(input1)
                {system("cls");print_menu();}
            }
            break;
        case 4:
            setting();
            break;
        case 5:
            exit(0);
    }
}
void setting()
{
    char str[5][500];
    strcpy(str[0],"Behind every successful fortune there is a crime");
    strcpy(str[1],"I have learned more in the streets than in any classroom");
    strcpy(str[2],"Keep your friends close but your enemies closer");
    strcpy(str[3],"There’s no such thing as good money or bad money. There's just money");
    strcpy(str[4],"I am an undisputed gangster. To me, that means playing by my own rules");
    system("cls");
    printf("1)A Random Quote Said By MR.JACK\n");
    printf("2)Change The Color\n");
    printf("3)Return Back to The Main Menu\n");
    int input;
    scanf("%d",&input);
    switch (input)
    {
        case 1:{
            int i;
            srand(time(NULL));
            i=rand()%5;
            system("cls");
            printf("%s\n",str[i]);
            delay1(10.0);
            system("cls");
            print_menu();
            break;}
        case 2:
            Color_counter++;
            Color_counter%=4;
            change_color(Color_counter);
            setting();
            break;
        case 3:
            system("cls");
            print_menu();

    }
}
void change_color(int Color_counter)
{
    switch (Color_counter)
    {
        case 0:
            system("Color 0C");
            break;
        case 1:
            system("Color 0E");
            break;
        case 2:
            system("Color 0D");
            break;
        case 3:
            system("Color 0B");
    }
}
#endif // LOBBY_H_INCLUDED
