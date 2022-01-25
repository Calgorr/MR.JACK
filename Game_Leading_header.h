#ifndef GAME_LEADING_HEADER_H_INCLUDED
#define GAME_LEADING_HEADER_H_INCLUDED
#include "Linked_List.h"
#include "Character.h"
#include "Game_Functions.h"
static int round1=1;
static int cnt_fard;
static int cnt_zoj;
int s=1;
void assign_player2();
void assign_player1();
void Round()
{
    if (round1>8)
    {
        system("cls");
        printf("MR.JACK Won!!");
        return;
    }
    if((s++)<5)
    {
        system("cls");
        printf("Would You Like To See Who is Not Guilty ?1 For Yes 0 For No\n");
        int input;
        scanf("%d",&input);
        if(input)
        {
            system("cls");
            print_map();
            printf("\n");
            hidden();
            not_guilty();
        }
        printf("------------------------ROUND %d------------------------\n",round1);
        delay1(8.0);
        assign_player1();
    }
    if(s==5)
        round1++;
    else if((s++)<9)
    {
        system("cls");
        printf("Would You Like To See Who is Not Guilty ?1 For Yes 0 For No\n");
        int input;
        scanf("%d",&input);
        if(input)
        {
            system("cls");
            print_map();
            printf("\n");
            not_guilty();
        }
        system("cls");
        printf("------------------------ROUND %d------------------------\n",round1);
        delay1(8.0);
        assign_player2();
    }
    if(s==9)
        round1++;
    s=1;
    assign_node();
    Round();
}
void assign_player1()
{
    system("cls");
    print_map();
    if(cnt_fard%4==0||cnt_fard%4==3)
        printf("\nIt Is Detective's Turn\n");
    else
        printf("\nIt Is MR.JACK's Turn\n");
    printf("Please Enter The Character's Name That You Are Going To Take\nAccording To The Information Down Below\n");
    print_list(head1);
    char input[3];
    scanf("%s",input);
    if(!strcmp(character[0].abrv,input))
    {
        system("cls");
        SH();
        delete_node(&head1,"SH");
        cnt_fard++;
        Round();
    }
    else if(!strcmp(character[1].abrv,input))
    {
        system("cls");
        JW();
        delete_node(&head1,"JW");
        cnt_fard++;
        Round();
    }
    else if(!strcmp(character[2].abrv,input))
    {
        system("cls");
        JS();
        delete_node(&head1,"JS");
        cnt_fard++;
        Round();
    }
    else if(!strcmp(character[3].abrv,input))
    {
        system("cls");
        IL();
        delete_node(&head1,"IL");
        cnt_fard++;
        Round();
    }
    else if(!strcmp(character[4].abrv,input))
    {
        system("cls");
        MS();
        delete_node(&head1,"MS");
        cnt_fard++;
        Round();
    }
    else if(!strcmp(character[5].abrv,input))
    {
        system("cls");
        SG();
        delete_node(&head1,"SG");
        cnt_fard++;
        Round();
    }
    else if(!strcmp(character[6].abrv,input))
    {
        system("cls");
        WG();
        delete_node(&head1,"WG");
        cnt_fard++;
        Round();
    }
    else if(!strcmp(character[7].abrv,input))
    {
        system("cls");
        JB();
        delete_node(&head1,"JB");
        cnt_fard++;
        Round();
    }

}
void assign_player2()
{
    system("cls");
    print_map();
    if(cnt_zoj%4==0||cnt_zoj%4==3)
        printf("\nMR.JACK Should Choose His Card First\n");
    else
        printf("\nThe Detective Should Choose His Card First\n");
    print_list(head2);
    char input[3];
    scanf("%s",input);
    if(!strcmp(character[0].abrv,input))
    {
        system("cls");
        SH();
        delete_node(&head2,"SH");
        cnt_zoj++;
        Round();
    }
    else if(!strcmp(character[1].abrv,input))
    {
        system("cls");
        JW();
        delete_node(&head2,"JW");
        cnt_zoj++;
        Round();
    }
    else if(!strcmp(character[2].abrv,input))
    {
        system("cls");
        JS();
        delete_node(&head2,"JS");
        cnt_zoj++;
        Round();
    }
    else if(!strcmp(character[3].abrv,input))
    {
        system("cls");
        IL();
        delete_node(&head2,"IL");
        cnt_zoj++;
        Round();
    }
    else if(!strcmp(character[4].abrv,input))
    {
        system("cls");
        MS();
        delete_node(&head2,"MS");
        cnt_zoj++;
        Round();
    }
    else if(!strcmp(character[5].abrv,input))
    {
        system("cls");
        SG();
        delete_node(&head2,"SG");
        cnt_zoj++;
        Round();
    }
    else if(!strcmp(character[6].abrv,input))
    {
        system("cls");
        WG();
        delete_node(&head2,"WG");
        cnt_zoj++;
        Round();
    }
    else if(!strcmp(character[7].abrv,input))
    {
        system("cls");
        JB();
        delete_node(&head2,"JB");
        cnt_zoj++;
        Round();
    }

}
void not_guilty()
{
    int x=jack_hidden();
    if(x)
    {
       for(int i=0;i<8;i++)
       {
           if(!strcmp(player[jack].jack_name,character[i].abrv)||range[i]==-1)
            {
                if(!strcmp(player[jack].jack_name,character[i].abrv))
                    range[i]=-1;
                continue;
            }
           printf("%s Is Not Guilty\n",character[i].abrv);
       }
    }
    else
    {
        for(int k=0;k<8;k++)
        {
            if(range[k]!=-1)
                continue;
            printf("%s Is Not Guilty\n",character[k].abrv);
        }
    }
    delay1(15.0);
    system("cls");
}
#endif // GAME_LEADING_HEADER_H_INCLUDED
