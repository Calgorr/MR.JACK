#ifndef GAME_FUNCTIONS_H_INCLUDED
#define GAME_FUNCTIONS_H_INCLUDED
void find_character(char str[3],int *x,int *y);
int check_cell(char str[4],int x,int y);
void JS()
{
    int input;
    printf("would you like to us your ability first or not? 1 for yes 0 for no\n");
    scanf("%d",&input);
    if(input)
    {
        char LL[3],Ln[3];
        printf("which light would you like to turn of ?\n");
        scanf("%s",LL);
        printf("which ligth would you like to turn on");
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
        printf("\nnow you can see the changes on the map");
        delay(5);
        system("cls");
        print_map();
        printf("\nplease enter the path that you want to go!but be careful about the rules of crossing the streets\n");
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
        strcpy(board[x][y].sit,board[t][q].sit);
        strcpy(board[t][q].sit,"JS");
        system("cls");
        print_map();
    }


    else
    {
        int x,y;
        find_character("JS",&x,&y);
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
        strcpy(board[x][y].sit,board[t][q].sit);
        strcpy(board[t][q].sit,"JS");
        system("cls");
        print_map();
        printf("\nnow you can see the changes!");
        char LL[3],Ln[3];
        printf("\nwhich light would you like to turn of ?\n");
        scanf("%s",LL);
        printf("\nwhich ligth would you like to turn on");
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

    }
}
void IL()
{
    system("cls");
    assign_map_struct();
    print_map();
    printf("\nplease enter the path that you want to go!but be careful about the rules of crossing the streets\n");
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
    printf("%d %d",t,q);
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"IL");
    system("cls");
    print_map();
    char N[3],n[3];
    printf("\nwhich one of the exits would you like to block ?\n");
    scanf("%s",N);
    printf("\nnwhich one of the exits would you like to open");
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

}
void MS()
{
    system("cls");
    assign_map_struct();
    int x,y;
    find_character("MS",&x,&y);
    int t=x,q=y;
    print_map();
    printf("\nso now you have to enter the path that yo wan to go through remeber you have 1 to 4 moves \nand you can cross any hex!!");
    printf("\nremeber that you can only stop on the street\n");
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
    strcpy(board[x][y].sit,board[t][q].sit);
    strcpy(board[t][q].sit,"MS");
    print_map();
}
void JB()
{
    assign_map_struct();
    int input;
    printf("would you like to us your ability first or not? 1 for yes 0 for no\n");
    scanf("%d",&input);
    if(input)
    {
        char TB[3],T[3];
        printf("which tunnel would you like to block ?\n");
        scanf("%s",T);
        printf("which tunnel would you like to open");
        scanf("%s",TB);
        int x,y;
        find_character("JB",&x,&y);
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
        system("cls");
        print_map();
        printf("\nnow you can see the changes on the map");
        delay(5);
        system("cls");
        print_map();
        printf("\nplease enter the path that you want to go!but be careful about the rules of crossing the streets\n");
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
        strcpy(board[x][y].sit,board[t][q].sit);
        strcpy(board[t][q].sit,"JB");
        system("cls");
        print_map();
    }


    else
    {
        int x,y;
        find_character("JB",&x,&y);
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
        strcpy(board[x][y].sit,board[t][q].sit);
        strcpy(board[t][q].sit,"JB");
        system("cls");
        print_map();
        printf("\nnow you can see the changes!");
        char T[3],TB[3];
        printf("\nwhich tunnel would you like to block ?");
        scanf("%s",T);
        printf("\nwhich tunnel would you like to open\n");
        scanf("%s",TB);
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
        system("cls");
        print_map();

    }
}
void WG()
{
    assign_map_struct();
    int x,y;
    find_character("WG",&x,&y);
    int input;
    printf("as you know you can either use your ability or move!!1 for ability 0 for moving\n");
    scanf("%d",&input);
    system("cls");
    if(input)
    {
        int c=0;
        char str[3];
        printf("please enter the character's name\n");
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

    }
    else
    {
        int x,y;
        find_character("WG",&x,&y);
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
        strcpy(board[x][y].sit,board[t][q].sit);
        strcpy(board[t][q].sit,"WG");
        system("cls");
        print_map();
    }
}
int check_cell(char str[4],int x,int y)
{
    int t=x,q=y;
    for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='A')
            {
                if(!strcmp(board[t-1][q].sit,"H")||!strcmp(&board[t-1][q].sit[0],"L")||!strcmp(&board[t-1][q].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                t--;
            }
            else if(str[i]=='D')
            {
                if(!strcmp(board[t+1][q].sit,"H")||!strcmp(&board[t+1][q].sit[0],"L")||!strcmp(&board[t+1][q].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                t++;
            }
            else if(str[i]=='W')
            {
                if(q%2){
                if(!strcmp(board[t-1][q+1].sit,"H")||!strcmp(&board[t-1][q+1].sit[0],"L")||!strcmp(&board[t-1][q+1].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                q++;
                t--;}
                else
                {
                   if(!strcmp(board[t][q+1].sit,"H")||!strcmp(&board[t][q+1].sit[0],"L")||!strcmp(&board[t][q+1].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                q++;
                }
            }
            else if(str[i]=='E')
            {
                if(q%2){
                if(!strcmp(board[t][q+1].sit,"H")||!strcmp(&board[t][q+1].sit[0],"L")||!strcmp(&board[t][q+1].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                q++;}
                else
                {
                    if(!strcmp(board[t+1][q+1].sit,"H")||!strcmp(&board[t+1][q+1].sit[0],"L")||!strcmp(&board[t+1][q+1].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                t++;
                q++;
                }
            }
            else if(str[i]=='Z')
            {
                if(q%2){
                if(!strcmp(board[t-1][q-1].sit,"H")||!strcmp(&board[t-1][q-1].sit[0],"L")||!strcmp(&board[t-1][q-1].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                t--;
                q--;}
                else
                {
                    if(!strcmp(board[t][q-1].sit,"H")||!strcmp(&board[t][q-1].sit[0],"L")||!strcmp(&board[t][q-1].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                q--;
                }
            }
            else if(str[i]=='X')
             {
                 if(q%2){
                if(!strcmp(board[t][q-1].sit,"H")||!strcmp(&board[t][q-1].sit[0],"L")||!strcmp(&board[t][q-1].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                q--;}
                else
                {
                    if(!strcmp(board[t+1][q-1].sit,"H")||!strcmp(&board[t+1][q-1].sit[0],"L")||!strcmp(&board[t+1][q-1].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
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
#endif // GAME_FUNCTIONS_H_INCLUDED
