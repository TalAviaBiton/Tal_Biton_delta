/*------------------------------------------------------
* Filename: TalBiton_print_hanukiya.c
* Description: prints a hanukiya by the day of hanuka
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#define SPACES 5
int main() {
    int num=0;
    char first_row[] = " #    #    #    #    #    #    #    # ";
    printf("enter the day number\n");
    scanf("%d", &num);
    printf("%.*s\n", num*SPACES, first_row);
    printf("###  ###  ###  ###  ###  ###  ###  ###\n");
    printf("###  ###  ###  ###  ###  ###  ###  ###\n");
    printf("###  ###  ###  ###  ###  ###  ###  ###\n");
    printf("######################################\n");
    printf("                  ||                  \n");
    printf("                  ||                  \n");
    printf("                  ||                  \n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    return 0;
}