/*------------------------------------------------------
* Filename: TalBiton_str_to_int.a.c
* Description: recives a string of a number and returns the number+36
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> 

#define LEN 10//because the largest number int can hold is 2,147,483,647 wich has 10 digits
int main() {
    char input[LEN+1]="0000000000";
    int num=36;
    scanf("%s", &input);
    num= atoi(input);
    printf("%d", num);  
    return 0;
}