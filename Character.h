#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
typedef struct
{
    char name[50];
    char abrv[3];
    int ability;
    int movement[2];
    char ability_s[200];

}Token;
Token character[8];
//saved my character's information here
void assign_character()
{
    strcpy(character[0].name,"Sherlock Holmes");
    character[0].ability=1;
    character[0].movement[0]=1;
    character[0].movement[1]=3;
    strcpy(character[0].ability_s,"Sherlock Holmes secretly draws the first card from the alibi pile ,\nand places it face down in front of him");
    strcpy(character[0].abrv,"SH");
    strcpy(character[1].name,"John H. Watson");
    character[1].ability=1;
    character[1].movement[0]=1;
    character[1].movement[1]=3;
    strcpy(character[1].ability_s,"Watson bears a lantern,This lantern illuminates all the characters standing straight ahead of him!!");
    strcpy(character[1].abrv,"JW");
    strcpy(character[2].name,"John Smith");
    character[2].ability=2;
    character[2].movement[0]=1;
    character[2].movement[1]=3;
    strcpy(character[2].ability_s,"Move one of the lit gaslight tiles onto one of the shut-off gaslight hex");
    strcpy(character[2].abrv,"JS");
    strcpy(character[3].name,"Inspector Lestrade");
    character[3].ability=2;
    character[3].movement[0]=1;
    character[3].movement[1]=3;
    strcpy(character[3].ability_s,"Move one police cordon. This will free one of the exits but block another!!");
    strcpy(character[3].abrv,"IL");
    strcpy(character[4].name,"Miss Stealthy");
    character[4].ability=4;
    character[4].movement[0]=1;
    character[4].movement[1]=4;
    strcpy(character[4].ability_s,"During her movement, Miss Stealthy can cross any hex ,\n(building, gaslight, garden) but she must stop her movement on a street hex.");
    strcpy(character[4].abrv,"MS");
    strcpy(character[5].name,"Sergeant Goodley");
    character[5].ability=2;
    character[5].movement[0]=1;
    character[5].movement[1]=3;
    strcpy(character[5].ability_s,"With His Whistle You Can Move Any Other Character For 1 To 3 Move closer To Him");
    strcpy(character[5].abrv,"SG");
    strcpy(character[6].name,"Sir William Gull");
    character[6].ability=2;
    character[6].movement[0]=1;
    character[6].movement[1]=3;
    strcpy(character[6].ability_s,"Instead of moving normally William Gull,\nyou can exchange this character's location with the location of any other character.");
    strcpy(character[6].abrv,"WG");
    strcpy(character[7].name,"Jeremy Bert");
    character[7].ability=2;
    character[7].movement[0]=1;
    character[7].movement[1]=3;
    strcpy(character[7].ability_s,"Jeremy Bert opens a manhole and closes another (move one covered manhole tile on any other open manhole hex.)");
    strcpy(character[7].abrv,"JB");
}
#endif // CHARACTER_H_INCLUDED
