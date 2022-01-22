#ifndef GAME_FUNCTIONS_H_INCLUDED
#define GAME_FUNCTIONS_H_INCLUDED
void find_character(char str[3],int *x,int *y);
int check_cell(char str[4],int x,int y);
void JS()
{
    int input;
    printf("would you like to us your ability first or not? 1 for yes 0 for no");
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
                q++;
            else if(str[i]=='E')
                {t++;q++;}
            else if(str[i]=='Z')
                q--;
            else if(str[i]=='X')
                {t++;q--;}
        }
        strcpy(board[x][y].sit,board[t][q].sit);
        strcpy(board[t][q].sit,"JS");
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
                q++;
            else if(str[i]=='E')
                {t++;q++;}
            else if(str[i]=='Z')
                q--;
            else if(str[i]=='X')
                {t++;q--;}
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
                if(!strcmp(board[t][q+1].sit,"H")||!strcmp(&board[t][q+1].sit[0],"L")||!strcmp(&board[t][q+1].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                q++;
            }
            else if(str[i]=='E')
            {
                if(!strcmp(board[t+1][q+1].sit,"H")||!strcmp(&board[t+1][q+1].sit[0],"L")||!strcmp(&board[t+1][q+1].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                t++;
                q++;
            }
            else if(str[i]=='Z')
            {
                if(!strcmp(board[t][q-1].sit,"H")||!strcmp(&board[t][q-1].sit[0],"L")||!strcmp(&board[t][q-1].sit[0],"l"))
                {
                    printf("you can not go through this path please enter a new path\n");
                    return 1;
                }
                q--;
            }
            else if(str[i]=='X')
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
