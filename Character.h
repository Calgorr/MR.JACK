#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
typedef struct
{
    char name[50];
    char abrv[3];
    int ability;
    int movement[2];
}player;
player character[8];
void assign_character()
{
    strcpy(character[0].name,"Sherlock Holmes");
    character[0].ability=1;
    character[0].movement[0]=1;
    character[0].movement[1]=3;
    strcpy(character[0].abrv,"SH");
    strcpy(character[1].name,"John H. Watson");
    character[1].ability=1;
    character[1].movement[0]=1;
    character[1].movement[1]=3;
    strcpy(character[1].abrv,"JW");
    strcpy(character[2].name,"John Smith");
    character[2].ability=2;
    character[2].movement[0]=1;
    character[2].movement[1]=3;
    strcpy(character[2].abrv,"JS");
    strcpy(character[3].name,"Inspector Lestrade");
    character[3].ability=2;
    character[3].movement[0]=1;
    character[3].movement[1]=3;
    strcpy(character[3].abrv,"IL");
    strcpy(character[4].name,"Miss Stealthy");
    character[4].ability=4;
    character[4].movement[0]=1;
    character[4].movement[1]=4;
    strcpy(character[5].name,"Sergeant Goodley");
    character[5].ability=2;
    character[5].movement[0]=1;
    character[5].movement[1]=3;
    strcpy(character[5].abrv,"SG");
    strcpy(character[6].name,"Sir William Gull");
    character[6].ability=2;
    character[6].movement[0]=1;
    character[6].movement[1]=3;
    strcpy(character[6].abrv,"WG");
    strcpy(character[7].name,"Jeremy Bert");
    character[7].ability=2;
    character[7].movement[0]=1;
    character[7].movement[1]=3;
    strcpy(character[7].abrv,"JB");
}
void print_JACK()
{
    system("cls");
    int i;
    srand(time(NULL));
    i=rand()%8;
    printf("\n\n\n\n\n                           MR.JACK Is %s",character[i].name);
}
#endif // CHARACTER_H_INCLUDED
