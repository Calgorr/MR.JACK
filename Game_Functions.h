#ifndef GAME_FUNCTIONS_H_INCLUDED
#define GAME_FUNCTIONS_H_INCLUDED
#include "Player.h"
#include "Lobby.h"
int is_in(int x,int y);
int jack_jw();
void tunnel();
void update_tunnel();
void hidden_JW();
void delete_suspect();
void map_exit(int t,int q);
void check_arrest(int t,int q);
int str_index(char str[3]);
void find_character(char str[3],int *x,int *y);
int range[]={0,1,2,3,4,5,6,7};
int JWx,JWy;
int check_cell(char str[4],int x,int y);
int arr[8][2]={{1,11},{6,2},{0,5},{2,0},{3,5},{4,12},{5,7},{8,7}};
void JS()
{
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
        printf("Which Light Would You Like To Turn On\n");
        scanf("%s",Ln);
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
        while(strlen(str)<1||strlen(str)>3)
        {
            printf("1 to 3 moves");
            scanf("%s",str);
        }
        system("cls");
        int t=x,q=y;
        while(check_cell(str,x,y))
        {
            scanf("%s",str);
            while(strlen(str)<1||strlen(str)>3)
            {
                printf("1 to 3 moves");
                scanf("%s",str);
            }
        }
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
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
    {
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
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"JS");
    }
    if(is_in(x,y))
    {
        update_tunnel();
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
        while(strlen(str)<1||strlen(str)>3)
        {
            printf("1 to 3 moves");
            scanf("%s",str);
        }
        system("cls");
        while(check_cell(str,x,y))
        {
            scanf("%s",str);
            while(strlen(str)<1||strlen(str)>3)
            {
                printf("1 to 3 moves");
                scanf("%s",str);
            }
        }
        int t=x,q=y;
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
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
    {
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
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"JS");
    }
    if(is_in(x,y))
    {
        update_tunnel();
    }
        system("cls");
        print_map();
        printf("\nnow you can see the changes!");
        char LL[3],Ln[3];
        printf("\nwhich light would you like to turn of ?\n");
        scanf("%s",LL);
        printf("which ligth would you like to turn on\n");
        scanf("%s",Ln);
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
    while(strlen(str)<1||strlen(str)>3)
    {
        printf("1 to 3 moves\n");
        scanf("%s",str);
    }
    while(check_cell(str,x,y))
    {
        scanf("%s",str);
        while(strlen(str)<1||strlen(str)>3)
        {
            printf("1 to 3 moves\n");
            scanf("%s",str);
        }
    }
    system("cls");
    int t=x,q=y;
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
    map_exit(t,q);
    if(board[t][q].sit[0]=='T')
    {
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"IL");
    }
    else
    {
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"IL");
    }
    if(is_in(x,y))
    {
        update_tunnel();
    }
    system("cls");
    print_map();
    char N[3],n[3];
    printf("\nWhich One Of The Exits Would You Like To Block ?\n");
    scanf("%s",N);
    printf("Which One Of The Exits Would You Like To Open\n");
    scanf("%s",n);
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
    delay1(4.0);
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
    while(strlen(str)<1||strlen(str)>4)
    {
        printf("1 to 4 moves\n");
        scanf("%s",str);
    }
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
    if(board[t][q].sit[0]!='S')
        MS();
    system("cls");
    check_arrest(t,q);
    if(board[t][q].sit[0]=='T')
    {
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"MS");
    }
    else
    {
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"MS");
    }
    if(is_in(x,y))
    {
        update_tunnel();
    }
    print_map();
    printf("\nNow You Can See The Changes On The Map !!");
    delay1(5.0);
}
void JB()
{
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
        printf("Which Tunnel Would You Like To Open ?\n");
        scanf("%s",TB);
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
        while(strlen(str)<1||strlen(str)>3)
        {
            printf("1 to 3 moves");
            scanf("%s",str);
        }
        system("cls");
        int t=x,q=y;
        while(check_cell(str,x,y))
        {
            scanf("%s",str);
            while(strlen(str)<1||strlen(str)>3)
            {
                printf("1 to 3 moves");
                scanf("%s",str);
            }
        }
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
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
    {
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"JB");
    }
    else
    {
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"JB");
    }
    if(is_in(x,y))
    {
        update_tunnel();
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
        while(strlen(str)<1||strlen(str)>3)
        {
            printf("1 to 3 moves");
            scanf("%s",str);
        }
        system("cls");
        while(check_cell(str,x,y))
        {
            scanf("%s",str);
            while(strlen(str)<1||strlen(str)>3)
            {
                printf("1 to 3 moves");
                scanf("%s",str);
            }
        }
        int t=x,q=y;
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
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
    {
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"JB");
    }
    else
    {
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"JB");
    }
    if(is_in(x,y))
    {
        update_tunnel();
    }
        system("cls");
        print_map();
        printf("\nNow You Can See the Changes!");
        delay1(4.0);
        char T[3],TB[3];
        printf("\nWhich Tunnel Would You Like To Block ?\n");
        scanf("%s",T);
        printf("Which Tunnel Would You Like To Open ?\n");
        scanf("%s",TB);
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
        delay1(5.0);
        system("cls");
    }
}
void WG()
{
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
        while(strlen(str)<1||strlen(str)>3)
        {
            printf("1 to 3 moves");
            scanf("%s",str);
        }
        system("cls");
        while(check_cell(str,x,y))
        {
            scanf("%s",str);
            while(strlen(str)<1||strlen(str)>3)
            {
                printf("1 to 3 moves");
                scanf("%s",str);
            }
        }
        int t=x,q=y;
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
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
    {
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"WG");
    }
    else
    {
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"WG");
    }
    if(is_in(x,y))
    {
        update_tunnel();
    }
        system("cls");
        print_map();
        delay1(5.0);
    }
}
void JW()
{
    int x,y;
    find_character("JW",&x,&y);
    JWx=x;
    JWy=y;
    char str[4];
    print_map();
    printf("\nPlease Enter The Path You Want To Go Through\n");
    scanf("%s",str);
    while(strlen(str)<1||strlen(str)>3)
    {
        printf("1 to 3 moves\n");
        scanf("%s",str);
    }
    while(check_cell(str,x,y))
    {
        scanf("%s",str);
        while(strlen(str)<1||strlen(str)>3)
        {
            printf("1 to 3 moves\n");
            scanf("%s",str);
        }
    }
    int t=x,q=y;
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
    map_exit(t,q);
    if(board[t][q].sit[0]=='T')
    {
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"JW");
    }
    else
    {
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"JW");
    }
    if(is_in(x,y))
    {
        update_tunnel();
    }
    print_map();
    printf("\nNow You Can See The Changes");
    delay1(5.0);
    system("cls");
    int direction;
    printf("Now You Have To Set The Direction Of JW\nRemember That It Will Be Used At The End Of Every Round\n");
    scanf("%d",&direction);
    board[t][q].JW=direction;
}
void SG()
{
    int x,y;
    find_character("JW",&x,&y);
    int input;
    print_map();
    printf("Would You Like To Use Your Ability First Or Not? 1 For Yes 0 For No\n");
    scanf("%d",&input);
    system("cls");
    if(input)
    {
        int ccnt;
        printf("How Many Character Would You Like To Use Your Ability on ?\n");
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
            while(strlen(str)<1||strlen(str)>3)
            {
                printf("1 to 3 moves");
                scanf("%s",str);
            }
            while(check_cell(str,x1,y1))
            {
                scanf("%s",str);
                while(strlen(str)<1||strlen(str)>3)
                {
                    printf("\n1 to 3 moves\n");
                    scanf("%s",str);
                }
            }
            for(int i=0;i<strlen(str);i++)
            {
            if(str[i]=='A')
                t1--;
            else if(str[i]=='D')
                t1++;
            else if(str[i]=='W')
            {
                if(q1%2)
                {
                    t1--;
                    q1++;
                }
                else
                    q1++;

            }
            else if(str[i]=='E')
            {
                if(q1%2)
                    q1++;
                else
                {
                    q1++;
                    t1++;
                }
            }
            else if(str[i]=='Z')
            {
                if(q1%2)
                {
                    t1--;
                    q1--;
                }
                else
                    q1--;
            }
            else if(str[i]=='X')
            {
                if(q1%2)
                    q1--;
                else
                {
                    q1--;
                    t1++;
                }
            }
        }
        strcpy(board[x1][y1].sit,board[t1][q1].sit);
        strcpy(board[t1][q1].sit,name);
        system("cls");
        print_map();
        printf("\n%s Has Been Moved\n",name);
        delay1(5.0);
        system("cls");
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
                            printf("2 Moves Only\n");
                            scanf("%s",str[k]);
                        }
                    }
                    else
                    {
                        while(strlen(str[k])!=1)
                        {
                            printf("1 Move Only\n");
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
                            printf("2 Moves Only\n");
                            scanf("%s",str[k]);
                        }
                    }
                    else
                    {
                        while(strlen(str[k])!=1)
                        {
                            printf("1 Move Only\n");
                            scanf("%s",str[k]);
                        }
                    }

                }
                for(int i=0;i<strlen(str[k]);i++)
                {
                    if(str[k][i]=='A')
                        t1--;
                    else if(str[k][i]=='D')
                        t1++;
                    else if(str[k][i]=='W')
                    {
                        if(q1%2)
                        {
                            t1--;
                            q1++;
                        }
                        else
                            q1++;

                    }
                    else if(str[k][i]=='E')
                    {
                        if(q1%2)
                            q1++;
                        else
                        {
                            q1++;
                            t1++;
                        }
                    }
                    else if(str[k][i]=='Z')
                    {
                        if(q1%2)
                        {
                            t1--;
                            q1--;
                        }
                        else
                            q1--;
                    }
                    else if(str[k][i]=='X')
                    {
                        if(q1%2)
                            q1--;
                        else
                        {
                            q1--;
                            t1++;
                        }
                    }
                }
                strcpy(board[x1][y1].sit,board[t1][q1].sit);
                strcpy(board[t1][q1].sit,name[k]);
        }
        system("cls");
        print_map();
        delay1(5.0);
        system("cls");

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
                printf("\n1 move only\n");
                scanf("%s",str[j]);
            }
            while(check_cell(str[j],x1,y1))
            {
                scanf("%s",str[j]);
                while(strlen(str[j])!=1)
                {
                    printf("\n1 move only\n");
                    scanf("%s",str[j]);
                }

            }
            for(int i=0;i<strlen(str[j]);i++)
            {
                if(str[j][i]=='A')
                    t1--;
                else if(str[j][i]=='D')
                    t1++;
                else if(str[j][i]=='W')
                {
                    if(q1%2)
                    {
                        t1--;
                        q1++;
                    }
                    else
                        q1++;
                    }
            else if(str[j][i]=='E')
                {
                    if(q1%2)
                        q1++;
                    else
                    {
                        q1++;
                    t1++;
                    }
                }
                else if(str[j][i]=='Z')
                {
                    if(q1%2)
                    {
                            t1--;
                        q1--;
                    }
                    else
                        q1--;
                }
                else if(str[j][i]=='X')
                {
                    if(q1%2)
                        q1--;
                    else
                    {
                        q1--;
                        t1++;
                    }
                }
            }
        strcpy(board[x1][y1].sit,board[t1][q1].sit);
        strcpy(board[t1][q1].sit,name[j]);
        }
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
    while(strlen(str)<1||strlen(str)>3)
    {
        printf("1 to 3 moves");
        scanf("%s",str);
    }
    system("cls");
    while(check_cell(str,x,y))
    {
        scanf("%s",str);
        while(strlen(str)<1||strlen(str)>3)
        {
            printf("1 to 3 moves");
            scanf("%s",str);
        }
    }
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
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
    {
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"SG");
    }
    else
    {
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"SG");
    }
    if(is_in(x,y))
    {
        update_tunnel();
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
            while(strlen(str)<1||strlen(str)>3)
            {
                printf("1 to 3 moves");
                scanf("%s",str);
            }
            system("cls");
            while(check_cell(str,x,y))
            {
                scanf("%s",str);
                while(strlen(str)<1||strlen(str)>3)
                {
                    printf("1 to 3 moves");
                    scanf("%s",str);
                }
            }
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
                map_exit(t,q);
                if(board[t][q].sit[0]=='T')
    {
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No");
        int input;
        scanf("%d",&input);
        if(input)
            tunnel(&t,&q);
        strcpy(board[x][y].sit,"S");
        strcpy(board[t][q].sit,"SG");
    }
    else
    {
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"SG");
    }
    if(is_in(x,y))
    {
        update_tunnel();
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
                    while(strlen(str)<1||strlen(str)>3)
                    {
                        printf("1 to 3 moves");
                        scanf("%s",str);
                    }
                    while(check_cell(str,x1,y1))
                    {
                        scanf("%s",str);
                        while(strlen(str)<1||strlen(str)>3)
                        {
                            printf("\n1 to 3 moves\n");
                            scanf("%s",str);
                        }
                    }
                    for(int i=0;i<strlen(str);i++)
                    {
                    if(str[i]=='A')
                        t1--;
                    else if(str[i]=='D')
                        t1++;
                    else if(str[i]=='W')
                    {
                        if(q1%2)
                        {
                            t1--;
                            q1++;
                        }
                        else
                            q1++;

                    }
                    else if(str[i]=='E')
                    {
                        if(q1%2)
                            q1++;
                        else
                        {
                            q1++;
                            t1++;
                        }
                    }
                    else if(str[i]=='Z')
                    {
                        if(q1%2)
                        {
                            t1--;
                            q1--;
                        }
                        else
                            q1--;
                    }
                    else if(str[i]=='X')
                    {
                        if(q1%2)
                            q1--;
                        else
                        {
                            q1--;
                            t1++;
                        }
                    }
                }
                strcpy(board[x1][y1].sit,board[t1][q1].sit);
                strcpy(board[t1][q1].sit,name);
                system("cls");
                print_map();
                printf("\n%s Has Been Moved\n",name);
                delay1(5.0);
                system("cls");
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
                                printf("2 Moves Only\n");
                                scanf("%s",str[k]);
                            }
                        }
                        else
                        {
                            while(strlen(str[k])!=1)
                            {
                                printf("1 Move Only\n");
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
                                printf("2 Moves Only\n");
                                scanf("%s",str[k]);
                            }
                        }
                        else
                        {
                            while(strlen(str[k])!=1)
                            {
                                printf("1 Move Only\n");
                                scanf("%s",str[k]);
                            }
                        }

                    }
                    for(int i=0;i<strlen(str[k]);i++)
                    {
                        if(str[k][i]=='A')
                            t1--;
                        else if(str[k][i]=='D')
                            t1++;
                        else if(str[k][i]=='W')
                        {
                            if(q1%2)
                            {
                                t1--;
                                q1++;
                            }
                            else
                                q1++;

                        }
                        else if(str[k][i]=='E')
                        {
                            if(q1%2)
                                q1++;
                            else
                            {
                                q1++;
                                t1++;
                            }
                        }
                        else if(str[k][i]=='Z')
                        {
                            if(q1%2)
                            {
                                t1--;
                                q1--;
                            }
                            else
                                q1--;
                        }
                        else if(str[k][i]=='X')
                        {
                            if(q1%2)
                                q1--;
                            else
                            {
                                q1--;
                                t1++;
                            }
                        }
                    }
                    strcpy(board[x1][y1].sit,board[t1][q1].sit);
                    strcpy(board[t1][q1].sit,name[k]);
            }
            system("cls");
            print_map();
            delay1(5.0);
            system("cls");

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
                printf("\n1 move only\n");
                scanf("%s",str[j]);
            }
            while(check_cell(str[j],x1,y1))
            {
                scanf("%s",str[j]);
                while(strlen(str[j])!=1)
                {
                    printf("\n1 move only\n");
                    scanf("%s",str[j]);
                }

            }
            for(int i=0;i<strlen(str[j]);i++)
            {
                if(str[j][i]=='A')
                    t1--;
                else if(str[j][i]=='D')
                    t1++;
                else if(str[j][i]=='W')
                {
                    if(q1%2)
                    {
                        t1--;
                        q1++;
                    }
                    else
                        q1++;
                    }
            else if(str[j][i]=='E')
                {
                    if(q1%2)
                        q1++;
                    else
                    {
                        q1++;
                    t1++;
                    }
                }
                else if(str[j][i]=='Z')
                {
                    if(q1%2)
                    {
                            t1--;
                        q1--;
                    }
                    else
                        q1--;
                }
                else if(str[j][i]=='X')
                {
                    if(q1%2)
                        q1--;
                    else
                    {
                        q1--;
                        t1++;
                    }
                }
            }
        strcpy(board[x1][y1].sit,board[t1][q1].sit);
        strcpy(board[t1][q1].sit,name[j]);
        }
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
    while(strlen(str)<1||strlen(str)>3)
    {
        printf("1 to 3 moves\n");
        scanf("%s",str);
    }
    system("cls");
    while(check_cell(str,x,y))
    {
        scanf("%s",str);
        while(strlen(str)<1||strlen(str)>3)
        {
            printf("1 to 3 moves\n");
            scanf("%s",str);
        }
    }
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
        map_exit(t,q);
        if(board[t][q].sit[0]=='T')
    {
        print_map();
        printf("\nYou Are On A Tunnel Would You Like To Use It ?1 For Yes 0 For No");
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
    {
        update_tunnel();
    }
        system("cls");
        print_map();
        printf("\nNow you Can See The Changes On The Map!!");
        delay1(5.0);
        system("cls");
        delete_suspect();
        delay1(5.0);
}
int check_cell(char str[4],int x,int y)
{
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
    printf("%s Deleted From Suspects List",jack_pile[r]);
    strcpy(jack_pile[r],"NULL");
}
void check_arrest(int t ,int q)
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
                printf("MR.JACK won");
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
    if(board[i-1][j].sit[0]=='L'||(str_index(board[i-1][j].sit)>-1&&str_index(board[i-1][j].sit)<8))
        flag++;
    else if(board[i+1][j].sit[0]=='L'||(str_index(board[i+1][j].sit)>-1&&str_index(board[i+1][j].sit)<8))
        flag++;
    if(j%2)
    {
        if(board[i-1][j+1].sit[0]=='L'||(str_index(board[i-1][j+1].sit)>-1&&str_index(board[i-1][j+1].sit)<8))
            flag++;
        if(board[i][j+1].sit[0]=='L'||(str_index(board[i][j+1].sit)>-1&&str_index(board[i][j+1].sit)<8))
            flag++;
        if(board[i][j-1].sit[0]=='L'||(str_index(board[i][j-1].sit)>-1&&str_index(board[i][j-1].sit)<8))
            flag++;
        if(board[i-1][j-1].sit[0]=='L'||(str_index(board[i-1][j-1].sit)>-1&&str_index(board[i-1][j-1].sit)<8))
            flag++;
    }
    else
    {
        if(board[i][j+1].sit[0]=='L'||(str_index(board[i][j+1].sit)>-1&&str_index(board[i][j+1].sit)<8))
            flag++;
        if(board[i+1][j+1].sit[0]=='L'||(str_index(board[i+1][j+1].sit)>-1&&str_index(board[i+1][j+1].sit)<8))
            flag++;
        if(board[i+1][j-1].sit[0]=='L'||(str_index(board[i+1][j-1].sit)>-1&&str_index(board[i+1][j-1].sit)<8))
            flag++;
        if(board[i][j-1].sit[0]=='L'||(str_index(board[i][j-1].sit)>-1&&str_index(board[i][j-1].sit)<8))
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
                    if(-1<str_index(board[j-1][k-1].sit)&&13>str_index(board[j-1][k-1].sit))
                        range[str_index(board[j-1][k-1].sit)]=-1;
                    if(-1<str_index(board[j-1][k].sit)&&13>str_index(board[j-1][k].sit))
                        range[str_index(board[j-1][1].sit)]=-1;
                    if(-1<str_index(board[j-1][k+1].sit)&&13>str_index(board[j-1][k+1].sit))
                        range[str_index(board[j-1][k+1].sit)]=-1;
                    if(-1<str_index(board[j][k+1].sit)&&13>str_index(board[j][k+1].sit))
                        range[str_index(board[j][k+1].sit)]=-1;
                    if(-1<str_index(board[j+1][k].sit)&&13>str_index(board[j+1][k].sit))
                        range[str_index(board[j+1][k].sit)]=-1;
                    if(-1<str_index(board[j][k-1].sit)&&13>str_index(board[j][k-1].sit))
                        range[str_index(board[j][k-1].sit)]=-1;
                }
                else
                {
                    if(-1<str_index(board[j][k-1].sit)&&13>str_index(board[j][k-1].sit))
                        range[str_index(board[j][k-1].sit)]=-1;
                    if(-1<str_index(board[j-1][k].sit)&&13>str_index(board[j-1][k].sit))
                        range[str_index(board[j-1][1].sit)]=-1;
                    if(-1<str_index(board[j][k+1].sit)&&13>str_index(board[j][k+1].sit))
                        range[str_index(board[j][k+1].sit)]=-1;
                    if(-1<str_index(board[j+1][k+1].sit)&&13>str_index(board[j+1][k+1].sit))
                        range[str_index(board[j+1][k+1].sit)]=-1;
                    if(-1<str_index(board[j+1][k].sit)&&13>str_index(board[j+1][k].sit))
                        range[str_index(board[j+1][k].sit)]=-1;
                    if(-1<str_index(board[j+1][k-1].sit)&&13>str_index(board[j+1][k-1].sit))
                        range[str_index(board[j+1][k-1].sit)]=-1;
                }
            }
            else if(str_index(board[j][k].sit)>-1)
            {
                if(k%2)
                {
                    if(-1<str_index(board[j-1][k-1].sit)&&13>str_index(board[j-1][k-1].sit))
                        range[str_index(board[j-1][k-1].sit)]=-1;
                    if(-1<str_index(board[j-1][k].sit)&&13>str_index(board[j-1][k].sit))
                        range[str_index(board[j-1][k].sit)]=-1;
                    if(-1<str_index(board[j-1][k+1].sit)&&13>str_index(board[j-1][k+1].sit))
                        range[str_index(board[j-1][k+1].sit)]=-1;
                    if(-1<str_index(board[j][k+1].sit)&&13>str_index(board[j][k+1].sit))
                        range[str_index(board[j][k+1].sit)]=-1;
                    if(-1<str_index(board[j+1][k].sit)&&13>str_index(board[j+1][k].sit))
                        range[str_index(board[j+1][k].sit)]=-1;
                    if(-1<str_index(board[j][k-1].sit)&&13>str_index(board[j][k-1].sit))
                        range[str_index(board[j][k-1].sit)]=-1;
                }
                else
                {
                    if(-1<str_index(board[j][k-1].sit)&&13>str_index(board[j][k-1].sit))
                        range[str_index(board[j][k-1].sit)]=-1;
                    if(-1<str_index(board[j-1][k].sit)&&13>str_index(board[j-1][k].sit))
                        range[str_index(board[j-1][k].sit)]=-1;
                    if(-1<str_index(board[j][k+1].sit)&&13>str_index(board[j][k+1].sit))
                        range[str_index(board[j][k+1].sit)]=-1;
                    if(-1<str_index(board[j+1][k+1].sit)&&13>str_index(board[j+1][k+1].sit))
                        range[str_index(board[j=1][k+1].sit)]=-1;
                    if(-1<str_index(board[j+1][k].sit)&&13>str_index(board[j+1][k].sit))
                        range[str_index(board[j+1][k].sit)]=-1;
                    if(-1<str_index(board[j+1][k-1].sit)&&13>str_index(board[j+1][k-1].sit))
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
                range[str_index(board[x][JWx].sit)]=-1;
            x--;
        }
    }
    else if(J==4)
    {
        int x=JWx+1;
        while(x<13)
        {
            if(!strcmp(board[x][JWy].sit,"SH")||!strcmp(board[x][JWy].sit,"JS")||!strcmp(board[x][JWy].sit,"IL")||!strcmp(board[x][JWy].sit,"MS")||!strcmp(board[x][JWy].sit,"SG")||!strcmp(board[x][JWy].sit,"WG")||!strcmp(board[x][JWy].sit,"JB"))
                range[str_index(board[x][JWx].sit)]=-1;
            x++;
        }
    }
    else if(J==2)
    {
        int t=JWx,q=JWy;
        while(t>-1&&q<9&&q>-1&&q<13)
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
        while(t>-1&&q<9&&q>-1&&q<13)
        {
                if(q%2)
                {
                    q++;
                    if(!strcmp(board[t][q].sit,"SH")||!strcmp(board[t][q].sit,"JS")||!strcmp(board[t][q].sit,"IL")||!strcmp(board[t][q].sit,"MS")||!strcmp(board[t][q].sit,"SG")||!strcmp(board[t][q].sit,"WG")||!strcmp(board[t][q].sit,"JB"))
                        range[str_index(board[t][q].sit)]=-1;
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
        while(t>-1&&q<9&&q>-1&&q<13)
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
        while(t>-1&&q<9&&q>-1&&q<13)
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
    printf("please enter the other tunnel's name that you want to go through!!you shoud consider the fact that you can not get out of a blocked tunnel");
    char input[3];
    scanf("%s",input);
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
}
void map_exit(int t,int q)
{
    if(board[t][q].sit[0]=='N')
    {
        system("cls");
        printf("MR.JACK Won");
        exit(0);
    }
    return ;
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
        while(x<13)
        {
            if(!strcmp(board[x][JWy].sit,player[jack].jack_name))
                flag++;
            x++;
        }
    }
    else if(J==2)
    {
        int t=JWx,q=JWy;
        while(t>-1&&q<9&&q>-1&&q<13)
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
        while(t>-1&&q<9&&q>-1&&q<13)
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
        while(t>-1&&q<9&&q>-1&&q<13)
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
        while(t>-1&&q<9&&q>-1&&q<13)
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
#endif // GAME_FUNCTIONS_H_INCLUDED
