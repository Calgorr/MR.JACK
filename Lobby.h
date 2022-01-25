#ifndef LOBBY_H_INCLUDED
#define LOBBY_H_INCLUDED
#include "Game_Leading_header.h"
void setting();
void print_menu();
static int Color_counter;
void change_color(int Color_counter);
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
    printf("3)Setings\n");
    printf("4)Quit\n");
    int input;
    scanf("%d",&input);
    switch (input)
    {
        case 1:
            assign_character();
            assign_map_struct();
            assign_node();
            player_assign();
            Round();
            break;
        case 2:
            break;
        case 3:
            setting();
            break;
        case 4:
            exit(0);
    }
}
void setting()
{
    system("cls");
    printf("1)Delete All The Existing Maps\n");
    printf("2)Stop The Song\n");
    printf("3)Change The Color\n");
    printf("4)Return Back to The Main Menu\n");
    int input;
    scanf("%d",&input);
    switch (input)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            Color_counter++;
            Color_counter%=4;
            change_color(Color_counter);
            setting();
            break;
        case 4:
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
/*void delay(float number_of_seconds)
{
    float milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}*/
#endif // LOBBY_H_INCLUDED
