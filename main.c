#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Lobby.h"
#include "Character.h"
#include "Map.h"
int count(int num);
int main()
{
    assign_map_struct();
    return 0;
}
int count(int num)
{
    int count1=0;
    while(num!=0)
    {
        count1++;
        num/=10;
    }
    return count1;
}
