#ifndef GAME_FUNCTIONS_H_INCLUDED
#define GAME_FUNCTIONS_H_INCLUDED
#include "Player.h"
#include "Lobby.h"
int is_in(int x,int y);
int jack_jw();
void undo_char(char str[3],int x,int y,int t,int q);
void tunnel();
void update_tunnel();
void hidden_JW();
void delete_suspect();
void map_exit(int t,int q);
void check_arrest(int t,int q);
int str_index(char str[3]);
void find_character(char str[3],int *x,int *y);
int check_cell(char str[4],int x,int y);
int range[]={0,1,2,3,4,5,6,7};//I am using this array to show the not guilty ones
int JWx,JWy;
//the array down below is used for updating the tunnels
int arr[8][2]={{1,11},{6,2},{0,5},{2,0},{3,5},{4,12},{5,7},{8,7}};
//from this line to the 1230th line we are going to have the functions written for the characters in the game
void JS()
{
    system("cls");
    int input;
    print_map();
    printf("\nWould You Like To Use Your Ability First Or Not? 1 For Yes 0 For No\n");
    scanf("%d",&input);
    system("cls");
    if(input)
    {
        system("cls");
        char LL[3],Ln[3];
        print_map();
        printf("\nWhich Light Would You Like To Turn Of ?\n");
        scanf("%s",LL);
        while(LL[0]!='L')
        {
            if(LL[0]=='l')
            {
                printf("This Light Is Already Turned Of Please Enter A New One\n");
                scanf("%s",LL);
            }
            else
            {
                printf("It Seems That You Haven't Been Careful Enough Try Again\n");
                scanf("%s",LL);
            }
        }
        printf("Which Light Would You Like To Turn On\n");
        scanf("%s",Ln);
        while(Ln[0]!='l')
        {
            if(Ln[0]=='L')
            {
                printf("This Light Is Already Turned One Please Enter A New One\n");
                scanf("%s",Ln);
            }
            else
            {
                printf("It Seems That You Haven't Been Careful Enough Try Again\n");
                scanf("%s",Ln);
            }
        }
        int x,y;
        find_character("JS",&x,&y);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<13;j++)
            {
                if(!strcmp(board[i][j].sit,Ln))
                    strcpy(board[i][j].sit,LL);
                else if(!strcmp(board[i][j].sit,LL))
                   strcpy(board[i][j].sit,Ln);
            }
        }
        system("cls");
        print_map();
        printf("\nNow You Can See The Changes On The Map");
        delay1(5.0);
        system("cls");
        print_map();
        printf("\nPlease Enter The Path That You Want To Go!But Be Careful About The Rules Of Crossing The Streets\n");
        char str[4];
        scanf("%s",str);
        int t=x,q=y;
        while(check_cell(str,x,y))
            scanf("%s",str);
        move_character(&t,&q,str);
        check_arrest(t,q);
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
        {
            system("cls");
            print_map();
            printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No\n");
            int input;
            scanf("%d",&input);
            if(input)
                tunnel(&t,&q);
            strcpy(board[x][y].sit,"S");
            strcpy(board[t][q].sit,"JS");
        }
        else
        {
            if(board[t][q].sit[0]=='t')
            {
                strcpy(board[x][y].sit,"S");
                strcpy(board[t][q].sit,"JS");
            }
            else
            {
                strcpy(board[x][y].sit,board[t][q].sit);
                strcpy(board[t][q].sit,"JS");
            }
        }
        if(is_in(x,y))
            update_tunnel();
        system("cls");
        print_map();
        int undo;
        printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
        scanf("%d",&undo);
        if(undo)
        {
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<13;j++)
                {
                    if(!strcmp(board[i][j].sit,Ln))
                        strcpy(board[i][j].sit,LL);
                    else if(!strcmp(board[i][j].sit,LL))
                       strcpy(board[i][j].sit,Ln);
                }
            }
            undo_char("JS",x,y,t,q);
            JS();
        }
        system("cls");
        print_map();
        delay1(5.0);
        system("cls");
    }


    else
    {
        system("cls");
        int x,y;
        find_character("JS",&x,&y);
        print_map();
        printf("\nPlease Enter The Path That You Want To Go!But Be Careful About The Rules Of Crossing The Streets\n");
        char str[4];
        scanf("%s",str);
        system("cls");
        while(check_cell(str,x,y))
            scanf("%s",str);
        int t=x,q=y;
        move_character(&t,&q,str);
        check_arrest(t,q);
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
        {
            system("cls");
            print_map();
            printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No");
            int input;
            scanf("%d",&input);
            if(input)
                tunnel(&t,&q);
            strcpy(board[x][y].sit,"S");
            strcpy(board[t][q].sit,"JS");
        }
        else
        {
            if(board[t][q].sit[0]=='t')
            {
                strcpy(board[x][y].sit,"S");
                strcpy(board[t][q].sit,"JS");
            }
            else
            {
                strcpy(board[x][y].sit,board[t][q].sit);
                strcpy(board[t][q].sit,"JS");
            }
        }
        if(is_in(x,y))
            update_tunnel();
        system("cls");
        print_map();
        printf("\nNow You Can See The Changes!");
        char LL[3],Ln[3];
        printf("\nWhich Light Would You Like To Turn Of ?\n");
        scanf("%s",LL);
        while(LL[0]!='L')
        {
            if(LL[0]=='l')
            {
                printf("This Light Is Already Turned Of Please Enter A New One\n");
                scanf("%s",LL);
            }
            else
            {
                printf("It Seems That You Haven't Been Careful Enough Try Again\n");
                scanf("%s",LL);
            }
        }
        printf("Which Ligth Would You Like To Turn On\n");
        scanf("%s",Ln);
        while(Ln[0]!='l')
        {
            if(Ln[0]=='L')
            {
                printf("This Light Is Already Turned One Please Enter A New One\n");
                scanf("%s",Ln);
            }
            else
            {
                printf("It Seems That You Haven't Been Careful Enough Try Again");
                scanf("%s",Ln);
            }
        }
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<13;j++)
            {
                if(!strcmp(board[i][j].sit,Ln))
                    strcpy(board[i][j].sit,LL);
                else if(!strcmp(board[i][j].sit,LL))
                   strcpy(board[i][j].sit,Ln);
            }
        }
        system("cls");
        print_map();
        int undo;
        printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
        scanf("%d",&undo);
        if(undo)
        {
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<13;j++)
                {
                    if(!strcmp(board[i][j].sit,Ln))
                        strcpy(board[i][j].sit,LL);
                    else if(!strcmp(board[i][j].sit,LL))
                       strcpy(board[i][j].sit,Ln);
                }
            }
            undo_char("JS",x,y,t,q);
            JS();
        }
        system("cls");
        print_map();
        delay1(5.0);
        system("cls");

    }
}
void IL()
{
    system("cls");
    print_map();
    printf("\nPlease Enter The Path That You Want To  Through!But Be Careful About The Rules Of Crossing The Streets\n");
    int x,y;
    find_character("IL",&x,&y);
    char str[4];
    scanf("%s",str);
    while(check_cell(str,x,y))
        scanf("%s",str);
    system("cls");
    int t=x,q=y;
    move_character(&t,&q,str);
    check_arrest(t,q);
    map_exit(t,q);
    if(board[t][q].sit[0]=='T')
    {
        system("cls");
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No\n");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"IL");
    }
    else
    {
        if(board[t][q].sit[0]=='t')
            {
                strcpy(board[x][y].sit,"S");
                strcpy(board[t][q].sit,"IL");
            }
            else
            {
                strcpy(board[x][y].sit,board[t][q].sit);
                strcpy(board[t][q].sit,"IL");
            }
    }
    if(is_in(x,y))
        update_tunnel();
    system("cls");
    print_map();
    char N[3],n[3];
    printf("\nWhich One Of The Exits Would You Like To Block ?\n");
    scanf("%s",N);
    while(N[0]!='N')
    {
        if(N[0]=='n')
        {
            printf("This Exit Is Already Blocked Please Enter A New One\n");
            scanf("%s",N);
        }
        else
        {
            printf("It Seems That You Haven't Been Careful Enough Try Again\n");
            scanf("%s",N);
        }
    }
    printf("Which One Of The Exits Would You Like To Open\n");
    scanf("%s",n);
    while(n[0]!='n')
    {
        if(n[0]=='N')
        {
            printf("This Exit Is Already Open Please Enter A New One\n");
            scanf("%s",n);
        }
        else
        {
            printf("It Seems That You Haven't Been Careful Enough Try Again\n");
            scanf("%s",n);
        }
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(!strcmp(board[i][j].sit,N))
                strcpy(board[i][j].sit,n);
            else if(!strcmp(board[i][j].sit,n))
                strcpy(board[i][j].sit,N);
        }
    }
    system("cls");
    print_map();
    int undo;
    printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
    scanf("%d",&undo);
    if(undo)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<13;j++)
            {
                if(!strcmp(board[i][j].sit,n))
                    strcpy(board[i][j].sit,N);
                else if(!strcmp(board[i][j].sit,N))
                    strcpy(board[i][j].sit,n);
            }
        }
        undo_char("IL",x,y,t,q);
        IL();
    }
    system("cls");
    print_map();
    delay1(4.0);
    system("cls");
}
void MS()
{
    system("cls");
    int x,y;
    find_character("MS",&x,&y);
    int t=x,q=y;
    print_map();
    printf("\nPlease Enter The Path That You Want To  Through! Remember You Have 1 To 4 Moves \nAnd You Can Cross Any Hex!!");
    printf(" But You Can Only Stop On The Street\n");
    char str[5];
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='A')
            t--;
        else if(str[i]=='D')
            t++;
        else if(str[i]=='W')
        {
            if(q%2)
            {
                t--;
                q++;
            }
            else
                q++;

        }
        else if(str[i]=='E')
        {
            if(q%2)
                q++;
            else
            {
                q++;
                t++;
            }
        }
        else if(str[i]=='Z')
        {
            if(q%2)
            {
                t--;
                q--;
            }
            else
                q--;
        }
        else if(str[i]=='X')
        {
            if(q%2)
                q--;
            else
            {
                q--;
                t++;
            }
        }
    }
    check_arrest(t,q);
    if(board[t][q].sit[0]!='S')
        MS();
    system("cls");
    if(board[t][q].sit[0]=='T')
    {
        system("cls");
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No\n");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"MS");
    }
    else
    {
        if(board[t][q].sit[0]=='t')
            {
                strcpy(board[x][y].sit,"S");
                strcpy(board[t][q].sit,"MS");
            }
            else
            {
                strcpy(board[x][y].sit,board[t][q].sit);
                strcpy(board[t][q].sit,"MS");
            }
    }
    if(is_in(x,y))
        update_tunnel();
    print_map();
    int undo;
    printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
    scanf("%d",&undo);
    if(undo)
    {
        undo_char("MS",x,y,t,q);
        MS();
    }
    system("cls");
    print_map();
    printf("\nNow You Can See The Changes On The Map !!");
    delay1(5.0);
}
void JB()
{
    system("cls");
    int input;
    print_map();
    printf("\nWould You Like To Use Your Ability First Or Not? 1 For Yes 0 For No\n");
    scanf("%d",&input);
    system("cls");
    if(input)
    {
        system("cls");
        print_map();
        char TB[3],T[3];
        printf("\nWhich Tunnel Would You Like To Block ?\n");
        scanf("%s",T);
        while(T[0]!='T')
        {
            if(T[0]=='t')
            {
                printf("This Tunnel Is Already Blocked Please Enter A New One\n");
                scanf("%s",T);
            }
            else
            {
                printf("It Seems That You Haven't Been Careful Enough Try Again\n");
                scanf("%s",T);
            }
        }
        printf("Which Tunnel Would You Like To Open ?\n");
        scanf("%s",TB);
        while(TB[0]!='t')
        {
            if(TB[0]=='T')
            {
                printf("This Tunnel Is Already Open Please Enter A New One\n");
                scanf("%s",TB);
            }
            else
            {
                printf("It Seems That You Haven't Been Careful Enough Try Again\n");
                scanf("%s",TB);
            }
        }
        int x,y;
        find_character("JB",&x,&y);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<13;j++)
            {
                if(!strcmp(board[i][j].sit,TB))
                {
                    strcpy(board[i][j].sit,T);
                    if(!strcmp(T,"T1"))
                   {
                       arr[2][0]=i;
                       arr[2][1]=j;
                   }
                   else if(!strcmp(T,"T2"))
                   {
                       arr[3][0]=i;
                       arr[3][1]=j;
                   }
                   else if(!strcmp(T,"T3"))
                   {
                       arr[4][0]=i;
                       arr[4][1]=j;
                   }
                   else if(!strcmp(T,"T4"))
                   {
                       arr[5][0]=i;
                       arr[5][1]=j;
                   }
                   else if(!strcmp(T,"T5"))
                   {
                       arr[6][0]=i;
                       arr[6][1]=j;
                   }
                   else if(!strcmp(T,"T6"))
                   {
                       arr[7][0]=i;
                       arr[7][1]=j;
                   }
                }
                else if(!strcmp(board[i][j].sit,T))
                {
                   strcpy(board[i][j].sit,TB);
                   if(!strcmp(TB,"t1"))
                   {
                       arr[0][0]=i;
                       arr[0][1]=j;
                   }
                   else if(!strcmp(T,"t2"))
                   {
                       arr[1][0]=i;
                       arr[1][1]=j;
                   }
                }
            }
        }
        system("cls");
        print_map();
        printf("\nNow You Can See The Changes On The Map!!");
        delay1(5.0);
        system("cls");
        print_map();
        printf("\nPlease Enter The Path That You Want To Go Through!But Be Careful About The Rules Of Crossing The Streets\n");
        char str[4];
        scanf("%s",str);
        system("cls");
        int t=x,q=y;
        while(check_cell(str,x,y))
            scanf("%s",str);
        move_character(&t,&q,str);
        check_arrest(t,q);
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
        {
            system("cls");
            print_map();
            printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No\n");
            int input;
            scanf("%d",&input);
            if(input)
                tunnel(&t,&q);
            strcpy(board[x][y].sit,"S");
            strcpy(board[t][q].sit,"JB");
        }
        else
        {
            if(board[t][q].sit[0]=='t')
            {
                strcpy(board[x][y].sit,"S");
                strcpy(board[t][q].sit,"JB");
            }
            else
            {
                strcpy(board[x][y].sit,board[t][q].sit);
                strcpy(board[t][q].sit,"JB");
            }
        }
        if(is_in(x,y))
            update_tunnel();
        print_map();
        int undo;
        printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
        scanf("%d",&undo);
        if(undo)
        {
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<13;j++)
                {
                    if(!strcmp(board[i][j].sit,TB))
                        strcpy(board[i][j].sit,T);
                    else if(!strcmp(board[i][j].sit,T))
                        strcpy(board[i][j].sit,TB);
                }
            }
            undo_char("JB",x,y,t,q);
            JB();
        }
        system("cls");
        print_map();
        delay1(5.0);
    }
    else
    {
        system("cls");
        print_map();
        int x,y;
        find_character("JB",&x,&y);
        char str[4];
        printf("\nPlease Enter The Path That You Want To Go Through!But Be Careful About The Rules Of Crossing The Streets\n");
        scanf("%s",str);
        system("cls");
        while(check_cell(str,x,y))
            scanf("%s",str);
        int t=x,q=y;
        move_character(&t,&q,str);
        check_arrest(t,q);
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
        {
            system("cls");
            print_map();
            printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No\n");
            int input;
            scanf("%d",&input);
            if(input)
                tunnel(&t,&q);
            strcpy(board[x][y].sit,"S");
            strcpy(board[t][q].sit,"JB");
        }
        else
        {
            if(board[t][q].sit[0]=='t')
            {
                strcpy(board[x][y].sit,"S");
                strcpy(board[t][q].sit,"JB");
            }
            else
            {
                strcpy(board[x][y].sit,board[t][q].sit);
                strcpy(board[t][q].sit,"JB");
            }
        }
        if(is_in(x,y))
            update_tunnel();
        system("cls");
        print_map();
        printf("\nNow You Can See the Changes!");
        delay1(4.0);
        char T[3],TB[3];
        printf("\nWhich Tunnel Would You Like To Block ?\n");
        scanf("%s",T);
        while(T[0]!='T')
        {
            if(T[0]=='t')
            {
                printf("This Tunnel Is Already Blocked Please Enter A New One\n");
                scanf("%s",T);
            }
            else
            {
                printf("It Seems That You Haven't Been Careful Enough Try Again\n");
                scanf("%s",T);
            }
        }
        printf("Which Tunnel Would You Like To Open ?\n");
        scanf("%s",TB);
        while(TB[0]!='t')
        {
            if(TB[0]=='T')
            {
                printf("This Tunnel Is Already Open Please Enter A New One\n");
                scanf("%s",TB);
            }
            else
            {
                printf("It Seems That You Haven't Been Careful Enough Try Again\n");
                scanf("%s",TB);
            }
        }
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<13;j++)
            {
                if(!strcmp(board[i][j].sit,TB))
                {
                    strcpy(board[i][j].sit,T);
                    if(!strcmp(T,"T1"))
                   {
                       arr[2][0]=i;
                       arr[2][1]=j;
                   }
                   else if(!strcmp(T,"T2"))
                   {
                       arr[3][0]=i;
                       arr[3][1]=j;
                   }
                   else if(!strcmp(T,"T3"))
                   {
                       arr[4][0]=i;
                       arr[4][1]=j;
                   }
                   else if(!strcmp(T,"T4"))
                   {
                       arr[5][0]=i;
                       arr[5][1]=j;
                   }
                   else if(!strcmp(T,"T5"))
                   {
                       arr[6][0]=i;
                       arr[6][1]=j;
                   }
                   else if(!strcmp(T,"T6"))
                   {
                       arr[7][0]=i;
                       arr[7][1]=j;
                   }
                }
                else if(!strcmp(board[i][j].sit,T))
                {
                   strcpy(board[i][j].sit,TB);
                   if(!strcmp(TB,"t1"))
                   {
                       arr[0][0]=i;
                       arr[0][1]=j;
                   }
                   else if(!strcmp(T,"t2"))
                   {
                       arr[1][0]=i;
                       arr[1][1]=j;
                   }
                }
            }
        }
        system("cls");
        print_map();
        int undo;
        printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
        scanf("%d",&undo);
        if(undo)
        {
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<13;j++)
                {
                    if(!strcmp(board[i][j].sit,TB))
                        strcpy(board[i][j].sit,T);
                    else if(!strcmp(board[i][j].sit,T))
                        strcpy(board[i][j].sit,TB);
                }
            }
            undo_char("JB",x,y,t,q);
            JB();
        }
        system("cls");
        print_map();
        delay1(5.0);
        system("cls");
    }
}
void WG()
{
    system("cls");
    int x,y;
    find_character("WG",&x,&y);
    int input;
    print_map();
    printf("\nAs You Know You Can Either Use Your Ability Or Move!!1 For Ability 0 For Moving\n");
    scanf("%d",&input);
    system("cls");
    if(input)
    {
        int c=0;
        char str[3];
        print_map();
        printf("\nPlease Enter The Character's Name\n");
        scanf("%s",str);
        int i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<13;j++)
            {
                if(!strcmp(board[i][j].sit,str))
                {
                    c++;
                    break;
                }
            }
            if(c)
                break;
        }
        strcpy(board[x][y].sit,board[i][j].sit);
        strcpy(board[i][j].sit,"WG");
        system("cls");
        print_map();
        int undo;
        printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
        scanf("%d",&undo);
        if(undo)
        {
            strcpy(board[i][j].sit,board[x][y].sit);
            strcpy(board[x][y].sit,"WG");
            WG();
        }
        system("cls");
        print_map();
        delay1(5.0);
    }
    else
    {
        int x,y;
        find_character("WG",&x,&y);
        char str[4];
        print_map();
        printf("\nPlease Enter The Path That You Want To Go Through\n");
        scanf("%s",str);
        system("cls");
        while(check_cell(str,x,y))
            scanf("%s",str);
        int t=x,q=y;
        move_character(&t,&q,str);
        check_arrest(t,q);
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
        {
            system("cls");
            print_map();
            printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No\n");
            int input;
            scanf("%d",&input);
            if(input)
                tunnel(&t,&q);
            strcpy(board[x][y].sit,"S");
            strcpy(board[t][q].sit,"WG");
        }
        else
        {
            if(board[t][q].sit[0]=='t')
            {
                strcpy(board[x][y].sit,"S");
                strcpy(board[t][q].sit,"WG");
            }
            else
            {
                strcpy(board[x][y].sit,board[t][q].sit);
                strcpy(board[t][q].sit,"WG");
            }
        }
        if(is_in(x,y))
            update_tunnel();
        system("cls");
        print_map();
        int undo;
        printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
        scanf("%d",&undo);
        if(undo)
        {
            undo_char("WG",x,y,t,q);
            WG();
        }
        system("cls");
        print_map();
        delay1(5.0);
    }
}
void JW()
{
    system("cls");
    int x,y;
    find_character("JW",&x,&y);
    JWx=x;
    JWy=y;
    char str[4];
    print_map();
    printf("\nPlease Enter The Path You Want To Go Through\n");
    scanf("%s",str);
    while(check_cell(str,x,y))
        scanf("%s",str);
    int t=x,q=y;
    move_character(&t,&q,str);
    check_arrest(t,q);
    map_exit(t,q);
    if(board[t][q].sit[0]=='T')
    {
        system("cls");
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No\n");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"JW");
    }
    else
    {
        if(board[t][q].sit[0]=='t')
            {
                strcpy(board[x][y].sit,"S");
                strcpy(board[t][q].sit,"JW");
            }
            else
            {
                strcpy(board[x][y].sit,board[t][q].sit);
                strcpy(board[t][q].sit,"JW");
            }
    }
    if(is_in(x,y))
        update_tunnel();
    system("cls");
    print_map();
    int undo;
    printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
    scanf("%d",&undo);
    if(undo)
    {
        undo_char("JW",x,y,t,q);
        JW();
    }
    system("cls");
    print_map();
    printf("\nNow You Can See The Changes");
    delay1(5.0);
    system("cls");
    int direction;
    print_map();
    printf("\nNow You Have To Set The Direction Of JW\nRemember That It Will Be Used At The End Of Every Round\n");
    scanf("%d",&direction);
    board[t][q].JW=direction;
}
void SG()
{
    int x,y;
    find_character("SG",&x,&y);
    int input;
    print_map();
    printf("\nWould You Like To Use Your Ability First Or Not? 1 For Yes 0 For No\n");
    scanf("%d",&input);
    system("cls");
    if(input)
    {
        int ccnt;
        print_map();
        printf("\nHow Many Character Would You Like To Use Your Ability on ?\n");
        scanf("%d",&ccnt);
        if(ccnt==1)
        {
            system("cls");
            print_map();
            int x1,y1;
            char str[4],name[4];
            printf("\nWhat Is The Chosen Name And The Path Of The Character ?\n");
            scanf("%s",name);
            scanf("%s",str);
            find_character(name,&x1,&y1);
            int t1=x1,q1=y1;
            while(check_cell(str,x1,y1))
                scanf("%s",str);
            move_character(&t1,&q1,str);
            if(board[t1][q1].sit[0]=='T')
            {
                strcpy(board[x1][y1].sit,"S");
                strcpy(board[t1][q1].sit,name);
            }
            else
            {
                if(board[t1][q1].sit[0]=='t')
                {
                    strcpy(board[x1][y1].sit,"S");
                    strcpy(board[t1][q1].sit,name);
                }
                else
                {
                    strcpy(board[x1][y1].sit,board[t1][q1].sit);
                    strcpy(board[t1][q1].sit,name);
                }
            }
            if(is_in(x1,y1))
                update_tunnel();
            system("cls");
            print_map();
            printf("\n%s Has Been Moved\n",name);
            delay1(5.0);
        }
        else if(ccnt==2)
        {
            system("cls");
            int a=0;
            printf("First Please Enter The Name And The Path Of The Character That Is Going To Move Through 2 Hex\nAnd Then The One That Is Going To Move 1 Hex\n");
            delay1(7.0);
            system("cls");
            for(int k=0;k<2;k++)
            {
                system("cls");
                print_map();
                int x1,y1;
                char str[2][4],name[2][4];
                printf("\nWhat Is The Chosen Path And The Name Of The Character ?\n");
                scanf("%s",name[k]);
                scanf("%s",str[k]);
                system("cls");
                find_character(name[k],&x1,&y1);
                int t1=x1,q1=y1;
                if(!(a++))
                {
                    while(strlen(str[k])!=2)
                    {
                        system("cls");
                        print_map();
                        printf("\n2 Moves Only\n");
                        scanf("%s",str[k]);
                    }
                }
                else
                {
                    while(strlen(str[k])!=1)
                    {
                        system("cls");
                        print_map();
                        printf("\n1 Move Only\n");
                        scanf("%s",str[k]);
                    }
                }
                while(check_cell(str[k],x1,y1))
                {
                    scanf("%s",str[k]);
                    if(!(a++))
                    {
                        while(strlen(str[k])!=2)
                        {
                            system("cls");
                            print_map();
                            printf("\n2 Moves Only\n");
                            scanf("%s",str[k]);
                        }
                    }
                    else
                    {
                        while(strlen(str[k])!=1)
                        {
                            system("cls");
                            print_map();
                            printf("\n1 Move Only\n");
                            scanf("%s",str[k]);
                        }
                    }

                }
                move_character(&t1,&q1,str[k]);
                if(board[t1][q1].sit[0]=='T')
                {
                    strcpy(board[x1][y1].sit,"S");
                    strcpy(board[t1][q1].sit,name[k]);
                }
                else
                {
                    if(board[t1][q1].sit[0]=='t')
                    {
                        strcpy(board[x1][y1].sit,"S");
                        strcpy(board[t1][q1].sit,name[k]);
                    }
                    else
                    {
                        strcpy(board[x1][y1].sit,board[t1][q1].sit);
                        strcpy(board[t1][q1].sit,name[k]);
                    }
                }
                if(is_in(x1,y1))
                    update_tunnel();
            }
            system("cls");
            print_map();
            delay1(5.0);

        }
    else if(ccnt==3)
    {
        system("cls");
        printf("Please Enter The Name And The Path Of The 3 Characters That You Want To Move\n");
        delay1(2.5);
        system("cls");
        for(int j=0;j<3;j++)
        {
            print_map();
            int x1,y1;
            char str[3][4],name[3][4];
            printf("\nWhat Is The Name And The Chosen Path Of The Character ?\n");
            scanf("%s",name[j]);
            scanf("%s",str[j]);
            system("cls");
            find_character(name[j],&x1,&y1);
            int t1=x1,q1=y1;
            while(strlen(str[j])!=1)
            {
                print_map();
                printf("\n1 Move Only\n");
                scanf("%s",str[j]);
            }
            while(check_cell(str[j],x1,y1))
            {
                scanf("%s",str[j]);
                while(strlen(str[j])!=1)
                {
                    print_map();
                    printf("\n1 Move Only\n");
                    scanf("%s",str[j]);
                }

            }
            move_character(&t1,&q1,str[j]);
            if(board[t1][q1].sit[0]=='T')
            {
                strcpy(board[x1][y1].sit,"S");
                strcpy(board[t1][q1].sit,name[j]);
            }
            else
            {
                if(board[t1][q1].sit[0]=='t')
                {
                    strcpy(board[x1][y1].sit,"S");
                    strcpy(board[t1][q1].sit,name[j]);
                }
                    else
                {
                    strcpy(board[x1][y1].sit,board[t1][q1].sit);
                    strcpy(board[t1][q1].sit,name[j]);
                }
            }
            if(is_in(x1,y1))
                update_tunnel();
        }
        system("cls");
        print_map();
        delay1(5);
    }
    system("cls");
    int x,y;
    find_character("SG",&x,&y);
    int t=x,q=y;
    char str[4];
    print_map();
    printf("\nPlease Enter The Path That You Want To Go Through\n");
    scanf("%s",str);
    system("cls");
    while(check_cell(str,x,y))
        scanf("%s",str);
    move_character(&t,&q,str);
    check_arrest(t,q);
    map_exit(t,q);
    if(board[t][q].sit[0]=='T')
    {
        system("cls");
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No\n");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"SG");
    }
    else
    {
        if(board[t][q].sit[0]=='t')
        {
            strcpy(board[x][y].sit,"S");
                strcpy(board[t][q].sit,"SG");
        }
            else
        {
            strcpy(board[x][y].sit,board[t][q].sit);
            strcpy(board[t][q].sit,"SG");
        }
    }
    if(is_in(x,y))
        update_tunnel();
    system("cls");
    print_map();
    int undo;
    printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
    scanf("%d",&undo);
    if(undo)
    {
        undo_char("SG",x,y,t,q);
        SG();
    }
    system("cls");
    print_map();
    delay1(5.0);
    system("cls");
    }
    else
    {
        system("cls");
        int x,y;
        find_character("SG",&x,&y);
        int t=x,q=y;
        char str[4];
        print_map();
        printf("\nPlease Enter The Path That You Want To Go Through\n");
        scanf("%s",str);
        system("cls");
        while(check_cell(str,x,y))
            scanf("%s",str);
        move_character(&t,&q,str);
        check_arrest(t,q);
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
        {
            system("cls");
            print_map();
            printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No\n");
            int input;
            scanf("%d",&input);
            if(input)
                tunnel(&t,&q);
            strcpy(board[x][y].sit,"S");
            strcpy(board[t][q].sit,"SG");
        }
        else
        {
            if(board[t][q].sit[0]=='t')
            {
                strcpy(board[x][y].sit,"S");
                strcpy(board[t][q].sit,"SG");
            }
            else
            {
                strcpy(board[x][y].sit,board[t][q].sit);
                strcpy(board[t][q].sit,"SG");
            }
        }
        if(is_in(x,y))
            update_tunnel();
        system("cls");
        print_map();
        int undo;
        printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
        scanf("%d",&undo);
        if(undo)
        {
            undo_char("SG",x,y,t,q);
            SG();
        }
        system("cls");
        print_map();
        delay1(5.0);
        system("cls");
        int ccnt;
        printf("How Many Character Would You Like To Use Your Ability On ?\n");
        scanf("%d",&ccnt);
        if(ccnt==1)
        {
            system("cls");
            print_map();
            int x1,y1;
            char str[4],name[4];
            printf("\nWhat Is The Chosen Name And The Path Of The Character ?\n");
            scanf("%s",name);
            scanf("%s",str);
            find_character(name,&x1,&y1);
            int t1=x1,q1=y1;
            while(check_cell(str,x1,y1))
                scanf("%s",str);
            move_character(&t1,&q1,str);
            if(board[t1][q1].sit[0]=='T')
            {
                strcpy(board[x1][y1].sit,"S");
                strcpy(board[t1][q1].sit,name);
            }
            else
            {
                strcpy(board[x1][y1].sit,board[t1][q1].sit);
                strcpy(board[t1][q1].sit,name);
            }
            if(is_in(x1,y1))
                update_tunnel();
            system("cls");
            print_map();
            printf("\n%s Has Been Moved\n",name);
            delay1(5.0);
        }
        else if(ccnt==2)
        {
            system("cls");
            int a=0;
            printf("First Please Enter The Name And The Path Of The Character That Is Going To Move Through 2 Hex\nAnd Then The One That Is Going To Move 1 Hex\n");
            delay1(7.0);
            system("cls");
            for(int k=0;k<2;k++)
            {
                system("cls");
                print_map();
                int x1,y1;
                char str[2][4],name[2][4];
                printf("\nWhat Is The Chosen Path And The Name Of The Character ?\n");
                scanf("%s",name[k]);
                scanf("%s",str[k]);
                system("cls");
                find_character(name[k],&x1,&y1);
                int t1=x1,q1=y1;
                if(!(a++))
                {
                    while(strlen(str[k])!=2)
                    {
                        system("cls");
                        print_map();
                        printf("\n2 Moves Only\n");
                        scanf("%s",str[k]);
                    }
                }
                else
                {
                    while(strlen(str[k])!=1)
                    {
                        system("cls");
                        print_map();
                        printf("\n1 Move Only\n");
                        scanf("%s",str[k]);
                    }
                }
                while(check_cell(str[k],x1,y1))
                {
                    scanf("%s",str[k]);
                    if(!(a++))
                    {
                        while(strlen(str[k])!=2)
                        {
                            system("cls");
                            print_map();
                            printf("\n2 Moves Only\n");
                            scanf("%s",str[k]);
                        }
                    }
                    else
                    {
                        while(strlen(str[k])!=1)
                        {
                            system("cls");
                            print_map();
                            printf("\n1 Move Only\n");
                            scanf("%s",str[k]);
                        }
                    }

                }
                move_character(&t1,&q1,str[k]);
                if(board[t1][q1].sit[0]=='T')
                {
                    strcpy(board[x1][y1].sit,"S");
                    strcpy(board[t1][q1].sit,name[k]);
                }
                else
                {
                    strcpy(board[x1][y1].sit,board[t1][q1].sit);
                    strcpy(board[t1][q1].sit,name[k]);
                }
                if(is_in(x1,y1))
                    update_tunnel();
            }
            system("cls");
            print_map();
            delay1(5.0);

        }
        else if(ccnt==3)
        {
            system("cls");
            printf("Please Enter The Name And The Path Of The 3 Characters That You Want To Move\n");
            delay1(2.5);
            system("cls");
            for(int j=0;j<3;j++)
            {
                print_map();
                int x1,y1;
                char str[3][4],name[3][4];
                printf("\nWhat Is The Name And The Chosen Path Of The Character ?\n");
                scanf("%s",name[j]);
                scanf("%s",str[j]);
                system("cls");
                find_character(name[j],&x1,&y1);
                int t1=x1,q1=y1;
                while(strlen(str[j])!=1)
                {
                    print_map();
                    printf("\n1 Move Only\n");
                    scanf("%s",str[j]);
                }
                while(check_cell(str[j],x1,y1))
                {
                    scanf("%s",str[j]);
                    while(strlen(str[j])!=1)
                    {
                        print_map();
                        printf("\n1 Move Only\n");
                        scanf("%s",str[j]);
                    }

                }
                move_character(&t1,&q1,str[j]);
                if(board[t1][q1].sit[0]=='T')
                {
                    strcpy(board[x1][y1].sit,"S");
                    strcpy(board[t1][q1].sit,name[j]);
                }
                else
                {
                    strcpy(board[x1][y1].sit,board[t1][q1].sit);
                    strcpy(board[t1][q1].sit,name[j]);
                }
                if(is_in(x1,y1))
                    update_tunnel();
            }
            system("cls");
            print_map();
            delay1(5);
        }
    }
}
void SH()
{
    system("cls");
    print_map();
    int x,y;
    find_character("SH",&x,&y);
    int t=x,q=y;
    printf("\nWhich Path Are You Going To Choose\n");
    char str[4];
    scanf("%s",str);
    system("cls");
    while(check_cell(str,x,y))
        scanf("%s",str);
    move_character(&t,&q,str);
    check_arrest(t,q);
    map_exit(t,q);
    if(board[t][q].sit[0]=='T')
    {
        system("cls");
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No\n");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"SH");
    }
    else
    {
        strcpy(board[x][y].sit,board[t][q].sit);
        strcpy(board[t][q].sit,"SH");
    }
    if(is_in(x,y))
        update_tunnel();
    system("cls");
    print_map();
    int undo;
    printf("\nWould You Like To Undo What you Just Did ? If Yes Enter 1 Otherwise 0\n");
    scanf("%d",&undo);
    if(undo)
    {
        undo_char("SH",x,y,t,q);
        SH();
    }
    system("cls");
    print_map();
    printf("\nNow you Can See The Changes On The Map!!");
    delay1(5.0);
    system("cls");
    delete_suspect();
    delay1(5.0);
}
//from now on we will set the logic of the game
int check_cell(char str[4],int x,int y)
{
    while(strlen(str)>3)
    {
        system("cls");
        print_map();
        printf("\n1 To 3 Moves Only\n");
        scanf("%s",str);
    }
    int t=x,q=y;
    for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='A')
            {
                if(board[t-1][q].sit[0]=='H'||board[t-1][q].sit[0]=='L'||board[t-1][q].sit[0]=='l'||board[t-1][q].sit[0]=='n')
                {
                    printf("You Can Not Go Through This Path Please Enter A New Path\n");
                    delay1(3.0);
                    system("cls");
                    print_map();
                    printf("\n");
                    return 1;
                }
                t--;
            }
            else if(str[i]=='D')
            {
                if(board[t+1][q].sit[0]=='H'||board[t+1][q].sit[0]=='L'||board[t+1][q].sit[0]=='l'||board[t+1][q].sit[0]=='n')
                {
                    printf("You Can Not Go Through This Path Please Enter A New Path\n");
                    delay1(4.0);
                    system("cls");
                    print_map();
                    printf("\n");
                    return 1;
                }
                t++;
            }
            else if(str[i]=='W')
            {
                if(q%2){
                if(board[t-1][q+1].sit[0]=='H'||board[t-1][q+1].sit[0]=='L'||board[t-1][q+1].sit[0]=='l'||board[t-1][q+1].sit[0]=='n')
                {
                    printf("You Can Not Go Through This Path Please Enter A New Path\n");
                    delay1(4.0);
                    system("cls");
                    print_map();
                    printf("\n");
                    return 1;
                }
                q++;
                t--;}
                else
                {
                   if(board[t][q+1].sit[0]=='H'||board[t][q+1].sit[0]=='L'||board[t][q+1].sit[0]=='l'||board[t][q+1].sit[0]=='n')
                {
                    printf("You Can Not Go Through This Path Please Enter A New Path\n");
                    delay1(4.0);
                    system("cls");
                    print_map();
                    printf("\n");
                    return 1;
                }
                q++;
                }
            }
            else if(str[i]=='E')
            {
                if(q%2){
                if(board[t][q+1].sit[0]=='H'||board[t][q+1].sit[0]=='L'||board[t][q+1].sit[0]=='l'||board[t][q+1].sit[0]=='n')
                {
                    printf("You Can Not Go Through This Path Please Enter A New Path\n");
                    delay1(4.0);
                    system("cls");
                    print_map();
                    printf("\n");
                    return 1;
                }
                q++;}
                else
                {
                    if(board[t+1][q+1].sit[0]=='H'||board[t+1][q+1].sit[0]=='L'||board[t+1][q+1].sit[0]=='l'||board[t+1][q+1].sit[0]=='n')
                    {
                    printf("You Can Not Go Through This Path Please Enter A New Path\n");
                    delay1(4.0);
                    system("cls");
                    print_map();
                    printf("\n");
                    return 1;
                    }
                system("cls");
                t++;
                q++;
                }
            }
            else if(str[i]=='Z')
            {
                if(q%2){
                if(board[t-1][q-1].sit[0]=='H'||board[t-1][q-1].sit[0]=='L'||board[t-1][q-1].sit[0]=='l'||board[t-1][q-1].sit[0]=='n')
                {
                    printf("You Can Not Go Through This Path Please Enter A New Path\n");
                    delay1(4.0);
                    system("cls");
                    print_map();
                    printf("\n");
                    return 1;
                }
                t--;
                q--;}
                else
                {
                    if(board[t][q-1].sit[0]=='H'||board[t][q-1].sit[0]=='L'||board[t][q-1].sit[0]=='l'||board[t][q-1].sit[0]=='n')
                {
                    printf("You Can Not Go Through This Path Please Enter A New Path\n");
                    delay1(4.0);
                    system("cls");
                    print_map();
                    printf("\n");
                    return 1;
                }
                q--;
                }
            }
            else if(str[i]=='X')
             {
                 if(q%2){
                if(board[t][q-1].sit[0]=='H'||board[t][q-1].sit[0]=='L'||board[t][q-1].sit[0]=='l'||board[t][q-1].sit[0]=='n')
                {
                    printf("You Can Not Go Through This Path Please Enter A New Path\n");
                    delay1(4.0);
                    system("cls");
                    print_map();
                    printf("\n");
                    return 1;
                }
                q--;}
                else
                {
                    if(board[t+1][q-1].sit[0]=='H'||board[t+1][q-1].sit[0]=='L'||board[t+1][q-1].sit[0]=='l'||board[t+1][q-1].sit[0]=='n')
                {
                    printf("You Can Not Go Through This Path Please Enter A New Path\n");
                    delay1(4.0);
                    system("cls");
                    print_map();
                    printf("\n");
                    return 1;
                }
                t++;
                q--;
                }
            }
        }
    return 0;
}
void find_character(char str[3],int *x,int *y)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(!strcmp(board[i][j].sit,str))
            {
                *x=i;
                *y=j;
            }
        }
    }
}
void delete_suspect()
{
    int r;
    srand(time(NULL));
    r=rand()%7;
    printf("Just The Person That Chose SH Should Look Now\n");
    delay1(5.0);
    while(!strcmp(jack_pile[r],"NULL"))
        r=rand()%7;
    printf("%s Deleted From Suspects List",jack_pile[r]);
    strcpy(jack_pile[r],"NULL");
}
void check_arrest(int t,int q)
{
    for(int i=0;i<8;i++)
    {
        if(!strcmp(board[t][q].sit,character[i].abrv))
        {
            if(!strcmp(character[i].abrv,player[jack].jack_name))
            {
                system("cls");
                printf("Detective Won");
                exit(0);
            }
            else
            {
                system("cls");

                printf("MR.JACK Won");
                exit(0);
            }
        }
    }
    return ;
}
int jack_hidden()
{
    int flag=0;
    extern int jack;
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<13;j++)
        {
            if(!strcmp(player[jack].jack_name,board[i][j].sit)&&(++flag))
                break;
        }
        if(flag)
            break;
    }
    flag=0;
    if((i>0)&&(board[i-1][j].sit[0]=='L'||(str_index(board[i-1][j].sit)>-1&&str_index(board[i-1][j].sit)<8)))
        flag++;
    else if((i<8)&&(board[i+1][j].sit[0]=='L'||(str_index(board[i+1][j].sit)>-1&&str_index(board[i+1][j].sit)<8)))
        flag++;
    if(j%2)
    {
        if((i>0&&j<12)&&(board[i-1][j+1].sit[0]=='L'||(str_index(board[i-1][j+1].sit)>-1&&str_index(board[i-1][j+1].sit)<8)))
            flag++;
        if((j<12)&&(board[i][j+1].sit[0]=='L'||(str_index(board[i][j+1].sit)>-1&&str_index(board[i][j+1].sit)<8)))
            flag++;
        if((j>0)&&(board[i][j-1].sit[0]=='L'||(str_index(board[i][j-1].sit)>-1&&str_index(board[i][j-1].sit)<8)))
            flag++;
        if((i>0&&j>0)&&(board[i-1][j-1].sit[0]=='L'||(str_index(board[i-1][j-1].sit)>-1&&str_index(board[i-1][j-1].sit)<8)))
            flag++;
    }
    else
    {
        if((j<12)&&(board[i][j+1].sit[0]=='L'||(str_index(board[i][j+1].sit)>-1&&str_index(board[i][j+1].sit)<8)))
            flag++;
        if((i<8&&j<12)&&(board[i+1][j+1].sit[0]=='L'||(str_index(board[i+1][j+1].sit)>-1&&str_index(board[i+1][j+1].sit)<8)))
            flag++;
        if((i<8&&j>0)&&(board[i+1][j-1].sit[0]=='L'||(str_index(board[i+1][j-1].sit)>-1&&str_index(board[i+1][j-1].sit)<8)))
            flag++;
        if((j>0)&&(board[i][j-1].sit[0]=='L'||(str_index(board[i][j-1].sit)>-1&&str_index(board[i][j-1].sit)<8)))
            flag++;
    }
    if(flag)
        return 1;
    flag+=jack_jw();
    if(flag)
        return 1;
    return 0;
}
void hidden()
{
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<13;k++)
        {
            if(board[j][k].sit[0]=='L')
            {
                if(k%2)
                {
                    if((j>0&&k>0)&&(-1<str_index(board[j-1][k-1].sit)&&13>str_index(board[j-1][k-1].sit)))
                        range[str_index(board[j-1][k-1].sit)]=-1;
                    if((j>0)&&(-1<str_index(board[j-1][k].sit)&&13>str_index(board[j-1][k].sit)))
                        range[str_index(board[j-1][k].sit)]=-1;
                    if((j>0&&k<12)&&(-1<str_index(board[j-1][k+1].sit)&&13>str_index(board[j-1][k+1].sit)))
                        range[str_index(board[j-1][k+1].sit)]=-1;
                    if((k<12)&&(-1<str_index(board[j][k+1].sit)&&13>str_index(board[j][k+1].sit)))
                        range[str_index(board[j][k+1].sit)]=-1;
                    if((j<8)&&(-1<str_index(board[j+1][k].sit)&&13>str_index(board[j+1][k].sit)))
                        range[str_index(board[j+1][k].sit)]=-1;
                    if((k>0)&&(-1<str_index(board[j][k-1].sit)&&13>str_index(board[j][k-1].sit)))
                        range[str_index(board[j][k-1].sit)]=-1;
                }
                else
                {
                    if((k>0)&&(-1<str_index(board[j][k-1].sit)&&13>str_index(board[j][k-1].sit)))
                        range[str_index(board[j][k-1].sit)]=-1;
                    if((j>0)&&(-1<str_index(board[j-1][k].sit)&&13>str_index(board[j-1][k].sit)))
                        range[str_index(board[j-1][k].sit)]=-1;
                    if((k<12)&&(-1<str_index(board[j][k+1].sit)&&13>str_index(board[j][k+1].sit)))
                        range[str_index(board[j][k+1].sit)]=-1;
                    if((j<8&&k<12)&&(-1<str_index(board[j+1][k+1].sit)&&13>str_index(board[j+1][k+1].sit)))
                        range[str_index(board[j+1][k+1].sit)]=-1;
                    if((j<8&&k>0)&&(-1<str_index(board[j+1][k].sit)&&13>str_index(board[j+1][k].sit)))
                        range[str_index(board[j+1][k].sit)]=-1;
                    if((j<8&&k>0)&&(-1<str_index(board[j+1][k-1].sit)&&13>str_index(board[j+1][k-1].sit)))
                        range[str_index(board[j+1][k-1].sit)]=-1;
                }
            }
            else if(str_index(board[j][k].sit)>-1)
            {
                if(k%2)
                {
                    if((j>0&&k>0)&&(-1<str_index(board[j-1][k-1].sit)&&13>str_index(board[j-1][k-1].sit)))
                        range[str_index(board[j-1][k-1].sit)]=-1;
                    if((j>0)&&(-1<str_index(board[j-1][k].sit)&&13>str_index(board[j-1][k].sit)))
                        range[str_index(board[j-1][k].sit)]=-1;
                    if((j>0&&k<12)&&(-1<str_index(board[j-1][k+1].sit)&&13>str_index(board[j-1][k+1].sit)))
                        range[str_index(board[j-1][k+1].sit)]=-1;
                    if((k<12)&&(-1<str_index(board[j][k+1].sit)&&13>str_index(board[j][k+1].sit)))
                        range[str_index(board[j][k+1].sit)]=-1;
                    if((j<8)&&(-1<str_index(board[j+1][k].sit)&&13>str_index(board[j+1][k].sit)))
                        range[str_index(board[j+1][k].sit)]=-1;
                    if((k>0)&&(-1<str_index(board[j][k-1].sit)&&13>str_index(board[j][k-1].sit)))
                        range[str_index(board[j][k-1].sit)]=-1;
                }
                else
                {
                    if((k>0)&&(-1<str_index(board[j][k-1].sit)&&13>str_index(board[j][k-1].sit)))
                        range[str_index(board[j][k-1].sit)]=-1;
                    if((j>0)&&(-1<str_index(board[j-1][k].sit)&&13>str_index(board[j-1][k].sit)))
                        range[str_index(board[j-1][k].sit)]=-1;
                    if((k<12)&&(-1<str_index(board[j][k+1].sit)&&13>str_index(board[j][k+1].sit)))
                        range[str_index(board[j][k+1].sit)]=-1;
                    if((j<8&&k<12)&&(-1<str_index(board[j+1][k+1].sit)&&13>str_index(board[j+1][k+1].sit)))
                        range[str_index(board[j+1][k+1].sit)]=-1;
                    if((j<8)&&(-1<str_index(board[j+1][k].sit)&&13>str_index(board[j+1][k].sit)))
                        range[str_index(board[j+1][k].sit)]=-1;
                    if((j<8&&k>0)&&(-1<str_index(board[j+1][k-1].sit)&&13>str_index(board[j+1][k-1].sit)))
                        range[str_index(board[j+1][k-1].sit)]=-1;
                }
            }
        }
    }
    hidden_JW();
}
void hidden_JW()
{
    int J=board[JWx][JWy].JW;
    if(J==1)
    {
        int x=JWx-1;
        while(x>-1)
        {
            if(!strcmp(board[x][JWy].sit,"SH")||!strcmp(board[x][JWy].sit,"JS")||!strcmp(board[x][JWy].sit,"IL")||!strcmp(board[x][JWy].sit,"MS")||!strcmp(board[x][JWy].sit,"SG")||!strcmp(board[x][JWy].sit,"WG")||!strcmp(board[x][JWy].sit,"JB"))
                range[str_index(board[x][JWy].sit)]=-1;
            x--;
        }
    }
    else if(J==4)
    {
        int x=JWx+1;
        while(x<9)
        {
            if(!strcmp(board[x][JWy].sit,"SH")||!strcmp(board[x][JWy].sit,"JS")||!strcmp(board[x][JWy].sit,"IL")||!strcmp(board[x][JWy].sit,"MS")||!strcmp(board[x][JWy].sit,"SG")||!strcmp(board[x][JWy].sit,"WG")||!strcmp(board[x][JWy].sit,"JB"))
                range[str_index(board[x][JWy].sit)]=-1;
            x++;
        }
    }
    else if(J==2)
    {
        int t=JWx,q=JWy;
        while(t>-1&&t<9&&q>-1&&q<13)
        {
            if(q%2)
            {
                if(!strcmp(board[t][q].sit,"SH")||!strcmp(board[t][q].sit,"JS")||!strcmp(board[t][q].sit,"IL")||!strcmp(board[t][q].sit,"MS")||!strcmp(board[t][q].sit,"SG")||!strcmp(board[t][q].sit,"WG")||!strcmp(board[t][q].sit,"JB"))
                    range[str_index(board[t][q].sit)]=-1;
                t--;
                q++;
            }
            else
            {
                if(!strcmp(board[t][q].sit,"SH")||!strcmp(board[t][q].sit,"JS")||!strcmp(board[t][q].sit,"IL")||!strcmp(board[t][q].sit,"MS")||!strcmp(board[t][q].sit,"SG")||!strcmp(board[t][q].sit,"WG")||!strcmp(board[t][q].sit,"JB"))
                    range[str_index(board[t][q].sit)]=-1;
                q++;
            }
        }
    }
    else if(J==3)
    {
        int t=JWx,q=JWy;
        while(t>-1&&t<9&&q>-1&&q<13)
        {
                if(q%2)
                {
                    if(!strcmp(board[t][q].sit,"SH")||!strcmp(board[t][q].sit,"JS")||!strcmp(board[t][q].sit,"IL")||!strcmp(board[t][q].sit,"MS")||!strcmp(board[t][q].sit,"SG")||!strcmp(board[t][q].sit,"WG")||!strcmp(board[t][q].sit,"JB"))
                        range[str_index(board[t][q].sit)]=-1;
                    q++;
                }
                else
                {
                    if(!strcmp(board[t][q].sit,"SH")||!strcmp(board[t][q].sit,"JS")||!strcmp(board[t][q].sit,"IL")||!strcmp(board[t][q].sit,"MS")||!strcmp(board[t][q].sit,"SG")||!strcmp(board[t][q].sit,"WG")||!strcmp(board[t][q].sit,"JB"))
                        range[str_index(board[t][q].sit)]=-1;
                    q++;
                    t++;
                }
        }
    }
    else if(J==5)
    {
        int t=JWx,q=JWy;
        while(t>-1&&t<9&&q>-1&&q<13)
        {
            if(q%2)
            {
                if(!strcmp(board[t][q].sit,"SH")||!strcmp(board[t][q].sit,"JS")||!strcmp(board[t][q].sit,"IL")||!strcmp(board[t][q].sit,"MS")||!strcmp(board[t][q].sit,"SG")||!strcmp(board[t][q].sit,"WG")||!strcmp(board[t][q].sit,"JB"))
                    range[str_index(board[t][q].sit)]=-1;
                q--;
            }
            else
            {
                if(!strcmp(board[t][q].sit,"SH")||!strcmp(board[t][q].sit,"JS")||!strcmp(board[t][q].sit,"IL")||!strcmp(board[t][q].sit,"MS")||!strcmp(board[t][q].sit,"SG")||!strcmp(board[t][q].sit,"WG")||!strcmp(board[t][q].sit,"JB"))
                    range[str_index(board[t][q].sit)]=-1;
                q--;
                t++;
            }
        }
    }
    else if(J==6)
    {
        int t=JWx,q=JWy;
        while(t>-1&&t<9&&q>-1&&q<13)
        {
            if(q%2)
                {
                    if(!strcmp(board[t][q].sit,"SH")||!strcmp(board[t][q].sit,"JS")||!strcmp(board[t][q].sit,"IL")||!strcmp(board[t][q].sit,"MS")||!strcmp(board[t][q].sit,"SG")||!strcmp(board[t][q].sit,"WG")||!strcmp(board[t][q].sit,"JB"))
                        range[str_index(board[t][q].sit)]=-1;
                    t--;
                    q--;
                }
                else
                {
                    if(!strcmp(board[t][q].sit,"SH")||!strcmp(board[t][q].sit,"JS")||!strcmp(board[t][q].sit,"IL")||!strcmp(board[t][q].sit,"MS")||!strcmp(board[t][q].sit,"SG")||!strcmp(board[t][q].sit,"WG")||!strcmp(board[t][q].sit,"JB"))
                        range[str_index(board[t][q].sit)]=-1;
                    q--;
                }
        }
    }
}
void tunnel(int *t,int *q)
{
    printf("Please Enter The Other Tunnel's Name That You Want To Go Through!!You Shoud Consider The Fact That You Can Not Get Out Of A Blocked Tunnel\n");
    char input[3];
    scanf("%s",input);
    while(input[0]!='T')
    {
        printf("Invalid Input !!\n");
        scanf("%s",input);
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(!strcmp(board[i][j].sit,input))
            {
                *t=i;
                *q=j;
                return ;
            }
        }
    }
    system("cls");
}
void map_exit(int t,int q)
{
    if(board[t][q].sit[0]=='N'&&jack_hidden())
    {
        system("cls");
        printf("MR.JACK Won");
        exit(0);
    }
    else if(board[t][q].sit[0]=='N'&&!jack_hidden())
    {
        system("cls");
        printf("I'm Afraid That You Have Left The City Without Being Hidden , So That Means That The Detective Saw You And He Won");
        exit(0);
    }
}
int str_index(char str[3])
{
    int i;
    for(i=0;i<8;i++)
    {
        if(!strcmp(character[i].abrv,str))
            return i;
    }
    return -1;
}
int jack_jw()
{
    int flag=0;
    int J=board[JWx][JWy].JW;
    if(J==1)
    {
        int x=JWx-1;
        while(x>-1)
        {
            if(!strcmp(board[x][JWy].sit,player[jack].jack_name))
                flag++;
            x--;
        }
    }
    else if(J==4)
    {
        int x=JWx+1;
        while(x<9)
        {
            if(!strcmp(board[x][JWy].sit,player[jack].jack_name))
                flag++;
            x++;
        }
    }
    else if(J==2)
    {
        int t=JWx,q=JWy;
        while(t>-1&&t<9&&q>-1&&q<13)
        {
            if(q%2)
            {
                if(strcmp(board[t][q].sit,"JW")&&!strcmp(board[t][q].sit,player[jack].jack_name))
                    flag++;
                t--;
                q++;
            }
            else
            {
                if(strcmp(board[t][q].sit,"JW")&&!strcmp(board[t][q].sit,player[jack].jack_name))
                    flag++;
                q++;
            }
        }
    }
    else if(J==3)
    {
        int t=JWx,q=JWy;
        while(t>-1&&t<9&&q>-1&&q<13)
        {
                if(q%2)
                {
                    if(strcmp(board[t][q].sit,"JW")&&!strcmp(board[t][q].sit,player[jack].jack_name))
                        flag++;
                    q++;
                }
                else
                {
                    if(strcmp(board[t][q].sit,"JW")&&!strcmp(board[t][q].sit,player[jack].jack_name))
                        flag++;
                    q++;
                    t++;
                }
        }
    }
    else if(J==5)
    {
        int t=JWx,q=JWy;
        while(t>-1&&t<9&&q>-1&&q<13)
        {
            if(q%2)
            {
                if(strcmp(board[t][q].sit,"JW")&&!strcmp(board[t][q].sit,player[jack].jack_name))
                        flag++;
                q--;
            }
            else
            {
                if(strcmp(board[t][q].sit,"JW")&&!strcmp(board[t][q].sit,player[jack].jack_name))
                        flag++;
                q--;
                t++;
            }
        }
    }
    else if(J==6)
    {
        int t=JWx,q=JWy;
        while(t>-1&&t<9&&q>-1&&q<13)
        {
            if(q%2)
                {
                    if(strcmp(board[t][q].sit,"JW")&&!strcmp(board[t][q].sit,player[jack].jack_name))
                        flag++;
                    t--;
                    q--;
                }
                else
                {
                    if(strcmp(board[t][q].sit,"JW")&&!strcmp(board[t][q].sit,player[jack].jack_name))
                        flag++;
                    q--;
                }
        }
    }
    return flag;
}
void update_tunnel()
{
    if(board[arr[0][0]][arr[0][1]].sit[0]=='S')
        strcpy(board[arr[0][0]][arr[0][1]].sit,"t1");
    if(board[arr[1][0]][arr[1][1]].sit[0]=='S')
        strcpy(board[arr[1][0]][arr[1][1]].sit,"t2");
    if(board[arr[2][0]][arr[2][1]].sit[0]=='S')
        strcpy(board[arr[2][0]][arr[2][1]].sit,"T1");
    if(board[arr[3][0]][arr[3][1]].sit[0]=='S')
        strcpy(board[arr[3][0]][arr[3][1]].sit,"T2");
    if(board[arr[4][0]][arr[4][1]].sit[0]=='S')
        strcpy(board[arr[4][0]][arr[4][1]].sit,"T3");
    if(board[arr[5][0]][arr[5][1]].sit[0]=='S')
        strcpy(board[arr[5][0]][arr[5][1]].sit,"T4");
    if(board[arr[6][0]][arr[6][1]].sit[0]=='S')
        strcpy(board[arr[6][0]][arr[6][1]].sit,"T5");
    if(board[arr[7][0]][arr[7][1]].sit[0]=='S')
        strcpy(board[arr[7][0]][arr[7][1]].sit,"T6");
}
int is_in(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        if(arr[i][0]==x&&arr[i][1]==y)
            return 1;
    }
    return 0;
}
void move_character(int *t,int *q,char str[4])
{
    for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='A')
                (*t)--;
            else if(str[i]=='D')
                (*t)++;
            else if(str[i]=='W')
            {
                if((*q)%2)
                {
                    (*t)--;
                    (*q)++;
                }
                else
                    (*q)++;

            }
            else if(str[i]=='E')
            {
                if((*q)%2)
                    (*q)++;
                else
                {
                    (*q)++;
                    (*t)++;
                }
            }
            else if(str[i]=='Z')
            {
                if((*q)%2)
                {
                    (*t)--;
                    (*q)--;
                }
                else
                    (*q)--;
            }
            else if(str[i]=='X')
            {
                if((*q)%2)
                    (*q)--;
                else
                {
                    (*q)--;
                    (*t)++;
                }
            }
        }
}
void undo_char(char str[3],int x,int y,int t,int q)
{
    if(is_in(t,q))
    {
        if(t==arr[0][0]&&q==arr[0][1])
            {
                strcpy(board[t][q].sit,"t1");
                strcpy(board[x][y].sit,str);
            }
            else if(t==arr[1][0]&&q==arr[1][1])
            {
                strcpy(board[t][q].sit,"t2");
                strcpy(board[x][y].sit,str);
            }
            else if(t==arr[2][0]&&q==arr[2][1])
            {
                strcpy(board[t][q].sit,"T1");
                strcpy(board[x][y].sit,str);
            }
            else if(t==arr[3][0]&&q==arr[3][1])
            {
                strcpy(board[t][q].sit,"T2");
                strcpy(board[x][y].sit,str);
            }
            else if(t==arr[4][0]&&q==arr[4][1])
            {
                strcpy(board[t][q].sit,"T3");
                strcpy(board[x][y].sit,str);
            }
            else if(t==arr[5][0]&&q==arr[5][1])
            {
                strcpy(board[t][q].sit,"T4");
                strcpy(board[x][y].sit,str);
            }
            else if(t==arr[6][0]&&q==arr[6][1])
            {
                strcpy(board[t][q].sit,"T5");
                strcpy(board[x][y].sit,str);
            }
        }
        else
        {
            strcpy(board[t][q].sit,board[x][y].sit);
            strcpy(board[x][y].sit,str);
        }
        system("cls");
        print_map();
        printf("\nVOILA!!");
        delay1(4.0);
}
#endif // GAME_FUNCTIONS_H_INCLUDED
