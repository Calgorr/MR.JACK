#ifndef BIN_FILE_LOAD_H_INCLUDED
#define BIN_FILE_LOAD_H_INCLUDED
//used for saving the files
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
    fread(&player[jack].jack_name,sizeof(strlen(player[jack].jack_name)),1,fpin);
    printf("%s",player[jack].jack_name);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<13;j++)
            fread(&board[i][j],sizeof(board),1,fpin);
    }
    for(int i=0;i<8;i++)
        fwrite(&range[i],sizeof(int),1,fpin);
    if(!(round1%2))
    {
        for(int j=0;j<4;j++)
            fread(&r2[j],sizeof(int),1,fpin);
    }
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
    flag_l=1;
    flag_1=1;
    flag_2=1;
    assign_node();
    Round();
}


#endif // BIN_FILE_LOAD_H_INCLUDED
