#ifndef BIN_FILE_LOAD_H_INCLUDED
#define BIN_FILE_LOAD_H_INCLUDED
void load_file()
{
    FILE * fpin;
    fpin=fopen("saved_game.bin","rb");
    fread(&round1,sizeof(int),1,fpin);
    fread(&jack,sizeof(int),1,fpin);
    fread(&turn,sizeof(int),1,fpin);
    fread(&cnt_zoj,sizeof(int),1,fpin);
    fread(&cnt_fard,sizeof(int),1,fpin);
    fread(&JWx,sizeof(int),1,fpin);
    fread(&JWy,sizeof(int),1,fpin);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<13;j++)
            fread(&board[i][j],sizeof(board),1,fpin);
    }
    load=1;
    assign_character();
    assign_node();
    if(jack==1)
    {
        player[0].jack=1;
        player[0].detective=0;
        player[1].jack=0;
        player[1].detective=1;
    }
    else
    {
        player[0].jack=0;
        player[0].detective=1;
        player[1].jack=1;
        player[1].detective=0;
    }
    player_j_random();
    flag_1=1;
    Round();
}


#endif // BIN_FILE_LOAD_H_INCLUDED
