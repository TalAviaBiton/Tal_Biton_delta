/*------------------------------------------------------
* Filename: TalBiton_max_fix.c
* Description: prints the largest between two numbers
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    int x=2;
    int y=-1;
    int z=(y>=x)*y+(x>y)*x;
    printf("%d", z);
    return 0;
}