#ifndef BIN_FILE_LOAD_H_INCLUDED
#define BIN_FILE_LOAD_H_INCLUDED
void load_file()
{
    FILE * fpin;
    fpin=fopen("saved_game.bin","rb");
    fread(&round1,sizeof(int),1,fpin);
    fread(&jack,sizeof(int),1,fpin);
    fread(&s,sizeof(int),1,fpin);
    fread(&cnt_zoj,sizeof(int),1,fpin);
    fread(&cnt_fard,sizeof(int),1,fpin);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<13;j++)
            fread(&board[i][j],sizeof(board),1,fpin);
    }
    Round();
}


#endif // BIN_FILE_LOAD_H_INCLUDED
