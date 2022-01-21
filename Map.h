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
#endif // MAP_H_INCLUDED
