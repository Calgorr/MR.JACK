#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
#include "Character.h"
struct node * create_node(char name1[3],int movement1[2],char ability1_s[200]);
void add_end(struct node * head,struct node * new_node);
void delete_node(struct node** phead, char str[3]);
void assign_node();
int check_array(int arr[],int i);
int check_array2(int arr[],int i);
void print_list(struct node * head);
struct node * head1;
struct node * head2;;
struct node
{
    char name[3];
    int movement[2];
    char ability[200];
    struct node *next;
};
void assign_node()
{
    int r[4];
    srand(time(NULL));
    r[0]=rand()%8;
    int j=1;
    while(j<5)
    {
        do
        {
            srand(time(NULL));
            r[j]=rand()%8;
        }while(check_array(r,j));
        j++;
    }
    system("cls");
    for(int i=0;i<4;i++)
        printf("%d\n",r[i]);
    head1=create_node(character[r[0]].abrv,character[r[0]].movement,character[r[0]].ability_s);
    for(int i=1;i<=3;i++)
    {
        struct node * new_node;
        new_node=create_node(character[r[i]].abrv,character[r[i]].movement,character[r[i]].ability_s);
        add_end(head1,new_node);
    }
    int range[8]={0,1,2,3,4,5,6,7};
    int r2[4];
    int i=0,counter1=0;
    while(1)
    {
        if(counter1==4)
            break;
        while(check_array2(r,range[i]))
            i++;
        r2[counter1++]=range[i];
        i++;
    }
    system("cls");
    for(int j=0;j<4;j++)
        printf("%d",r2[j]);
    head2=create_node(character[r2[0]].abrv,character[r2[0]].movement,character[r2[0]].ability_s);
    for(int i=1;i<=3;i++)
    {
        struct node * new_node;
        new_node=create_node(character[r2[i]].abrv,character[r2[i]].movement,character[r2[i]].ability_s);
        add_end(head2,new_node);
    }
}
int check_array(int arr[],int i)
{
    for(int j=i-1;j>=0;j--)
        if(arr[j]==arr[i])
            return 1;
    return 0;
}
struct node * create_node(char name1[3],int movement1[],char ability1_s[200])
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    strcpy(new_node->ability,ability1_s);
    strcpy(new_node->name,name1);
    new_node->movement[0]=movement1[0];
    new_node->movement[1]=movement1[1];
    new_node->next=NULL;
    return new_node;
}
void add_end(struct node * head,struct node * new_node)
{
    struct node * current=head;
    while(current->next!=NULL)
        current=current->next;
    current->next=new_node;
    new_node->next=NULL;

}
void delete_node(struct node** phead, char str[3])
{
    struct node *temp = *phead;
    if (temp != NULL && !strcmp(temp->name,str))
    {
        *phead= temp->next;
        free(temp);
        return;
    }
    while (strcmp(temp->next->name,str))
        temp = temp->next;
    temp->next=temp->next->next;
}
int check_array2(int arr[],int i)
{
    for(int j=0;j<4;j++)
        if(arr[j]==i)
            return 1;
    return 0;
}
void print_list(struct node * head)
{
    struct node * current=head;
    while(current!=NULL)
    {
        printf("%s : 1)Move %d To %d Houses , 2)%s\n",current->name,current->movement[0],current->movement[1],current->ability);
        current=current->next;
    }
}
#endif // LINKED_LIST_H_INCLUDED
