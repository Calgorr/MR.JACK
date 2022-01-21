#ifndef GAME_FUNCTIONS_H_INCLUDED
#define GAME_FUNCTIONS_H_INCLUDED
#include "Map.h"
void JS()
{
    int input;
    printf("would you like to us your ability first or not? 1 for yes 0 for no");
    scanf("%d",&input);
    if(input)
    {
        printf("which light would you like to turn of and which one would you like to turn on?\n");
        char LL[3],Ln[3];
        scanf("%s",Ln);
        scanf("%s",LL);
        int x,y;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<13;j++)
            {
                if(!strcmp(board[i][j].sit,Ln))
                    strcpy(board[i][j].sit,LL);
                if(!strcmp(board[i][j].sit,LL))
                   strcpy(board[i][j].sit,Ln);
                if(!strcmp(board[i][j].sit,"JS"))
                {
                    x=i;
                    y=j;
                }
            }
        }
        char str[4];
        scanf("%s",str);
        while(strlen(str)<1||strlen(str)>3)
        {
            printf("1 to 3 moves");
            scanf("%s",str);
        }
        int t=x,q=y;
        while(1)
        {
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
        if(!strcmp(board[t][q].sit,"S"))
            break;
        }

        strcpy(board[x][y].sit,board[t][q].sit);
        strcpy(board[t][q].sit,"JS");
    }
}
#endif // GAME_FUNCTIONS_H_INCLUDED
