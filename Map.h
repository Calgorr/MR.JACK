#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
//the header that is used to print the map or to assign the main struct
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
void assign_map_struct();
void print_map();
void multi_map()
{
    system("cls");
    printf("So We Have Two Options That You Can Choose Based On Your Prefrences !! The Map Or A New Map ?\n");
    delay1(3.0);
    assign_map_struct();
    print_map();
    printf("\nWhich One Would You Like To Go With ?First One Or The 2nd One\n");
    int input;
    scanf("%d",&input);
    if(input==1)
    {
        system("cls");
        return ;
    }
    system("cls");
    printf("Remember That You Can Not Change The Tunnels In Any Way And You Delete Or Add Any Other Characters To The Game\n");
    delay1(5.0);
    system("cls");
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<13;j++)
        {
            print_map();
            printf("\nPlease Enter The String That You Would Like To Be Saved In The Map For Index : %d-%d\n",i,j);
            scanf("%s",board[i][j].sit);
            system("cls");
        }
    }
    printf("Is This Map Ok Or You Want To Do Something Else If Yes Enter 1 Otherwise 0\n");
    int undo;
    scanf("%d",&undo);
    if(undo)
        multi_map();
    return ;
}
void assign_map_struct()
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
