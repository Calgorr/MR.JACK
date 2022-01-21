#ifndef GAME_LEADING_HEADER_H_INCLUDED
#define GAME_LEADING_HEADER_H_INCLUDED
#include "Linked_List.h"
#include "Character.h"
static int round=1;
static int cnt_fard;
static int cnt_zoj;
void round()
{
    if((round++)%2)
        assign_player1();
    else if(!(round++))
        assign_player2()
}
void assign_player1()
{
    system("cls");
    if(cnt_fard%4==0||cnt_fard%4==3)
        printf("The detective Should Choose his card first");
    else
        printf("The MR.JACK Should Choose his card first");
    print_list(head1);
    char input[3];
    scanf("%s",input);
    if(!strcmp(character[0].abrv,input))
    {
        SH();
        delete_node(head2,"SH");
    }
    else if(!strcmp(character[1].abrv,input))
    {
        JW();
        delete_node(head2,"JW");
    }
    else if(!strcmp(character[2].abrv,input))
    {
        JS();
        delete_node(head2,"JS");
    }
    else if(!strcmp(character[3].abrv,input))
    {
        IL();
        delete_node(head2,"IL");
    }
    else if(!strcmp(character[4].abrv,input))
    {
        MS();
        delete_node(head2,"MS");
    }
    else if(!strcmp(character[5].abrv,input))
    {
        SG();
        delete_node(head2,"SG");
    }
    else if(!strcmp(character[6].abrv,input))
    {
        WG();
        delete_node(head2,"WG");
    }
    else if(!strcmp(character[7].abrv,input))
    {
        JB();
        delete_node(head2,"JB");
    }
    cnt_fard++;

}
void assign_player2()
{
    system("cls");
    if(cnt_zoj%4==0||cnt_zoj%4==3)
        printf("The MR.JACK Should Choose his card first");
    else
        printf("The detective Should Choose his card first");
    print_list(head1);
    char input[3];
    scanf("%s",input);
    if(!strcmp(character[0].abrv,input))
    {
        SH();
        delete_node(head2,"SH");
    }
    else if(!strcmp(character[1].abrv,input))
    {
        JW();
        delete_node(head2,"JW");
    }
    else if(!strcmp(character[2].abrv,input))
    {
        JS();
        delete_node(head2,"JS");
    }
    else if(!strcmp(character[3].abrv,input))
    {
        IL();
        delete_node(head2,"IL");
    }
    else if(!strcmp(character[4].abrv,input))
    {
        MS();
        delete_node(head2,"MS");
    }
    else if(!strcmp(character[5].abrv,input))
    {
        SG();
        delete_node(head2,"SG");
    }
    else if(!strcmp(character[6].abrv,input))
    {
        WG();
        delete_node(head2,"WG");
    }
    else if(!strcmp(character[7].abrv,input))
    {
        JB();
        delete_node(head2,"JB");
    }
    cnt_zoj++;

}
#endif // GAME_LEADING_HEADER_H_INCLUDED
