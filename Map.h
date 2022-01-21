#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
typedef struct
{
    char sit[3];
}cell;
cell board[9][13];
void assign_map_struct()
{
    FILE *fpin;
    fpin=fopen("Map_Code.txt","r");
    int x,y;
    char str[3]="";
    for(int i=0;i<9*13;i++)
    {
        fscanf(fpin,"%d %d %s",&x,&y,str);
        strcpy(board[x][y].sit,str);
    }

}
void print_map()
{
    int x,y;
    char c,d;
    FILE *fpin;
    fpin=fopen("Grid(1).txt","r");
    while(1)
    {
        if(feof(fpin))
            break;
        fscanf(fpin,"%c",&c);
        if(48<=c&&c<=56)
        {
            x=atoi(&c);
            fscanf(fpin,"%c%c",&c,&d);
            if(48<=c&&c<=56&&48<=d&&d<=56)
            {
                y=atoi(&d);
                y=(y%10)*10+y/10;
                if(strlen(board[x][y].sit)==1)
                    printf("%s  ",board[x][y].sit);
                else
                    printf("%s ",board[x][y].sit);
            }
            else
            {
                y=atoi(&c);
                fseek(fpin,-1,SEEK_CUR);
                if(strlen(board[x][y].sit)==1)
                    printf("%s ",board[x][y].sit);
                else
                    printf("%s",board[x][y].sit);
            }
        }
        else
            printf("%c",c);
    }
}
#endif // MAP_H_INCLUDED
