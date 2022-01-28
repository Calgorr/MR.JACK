#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
void delay1(float number_of_seconds)
{
    float milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
typedef struct
{
    char sit[3];
    int JW;
}cell;
cell board[9][13];
void assign_map_struct1();
void assign_map_struct2();
void print_map();
void multi_map()
{
    system("cls");
    printf("So We Have Two Maps That You Can Choose Based On Your Prefrences !!\n");
    delay1(3.0);
    assign_map_struct1();
    print_map();
    printf("\n--------------------------------------------------------------------------------------------\n--------------------------------------------------------------------------------------------\n");
    assign_map_struct2();
    print_map();
    printf("\nWhich One Would You Like To Go With ?First One Or The 2nd One\n");
    int input;
    scanf("%d",&input);
    if(input==1)
    {
        assign_map_struct1();
        system("cls");
        return ;
    }
    assign_map_struct2();
    system("cls");
    return ;
}
void assign_map_struct1()
{
    FILE *fpin;
    fpin=fopen("Map_Code_1.txt","r");
    int x,y;
    char str[3]="";
    for(int i=0;i<9*13;i++)
    {
        fscanf(fpin,"%d %d %s",&x,&y,str);
        strcpy(board[x][y].sit,str);
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<13;j++)
            board[i][j].JW=1;
    }

}
void assign_map_struct2()
{
    FILE *fpin;
    fpin=fopen("Map_Code_2.txt","r");
    int x,y;
    char str[3]="";
    for(int i=0;i<9*13;i++)
    {
        fscanf(fpin,"%d %d %s",&x,&y,str);
        strcpy(board[x][y].sit,str);
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<13;j++)
            board[i][j].JW=1;
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
                else if(strlen(board[x][y].sit)==2)
                    printf("%s ",board[x][y].sit);
                else
                    printf("%s",board[x][y].sit);
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
