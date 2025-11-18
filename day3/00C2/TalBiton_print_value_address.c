/*------------------------------------------------------
* Filename: TalBiton_print_value_address.c
* Description: recives a string and a series of numbers and pints them
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>

#define LEN 10

int main() {
    char input_chars[LEN+1]="0000000000";
    int input_ints[LEN]={0};
    int *p_int=input_ints;
    char *p_char=input_chars;

    for(int index=0;index<LEN;index++){
        scanf("%d", &input_ints[index]);
    }
    for(int index=0;index<LEN;index++){
        scanf("%c", &input_chars[index]);
    }

    for(int index=0;index<LEN;p_int++,index++){
        printf("%d,", *p_int);
        printf("%x ", p_int);

    }
    printf("\n");
    for(int index=0;index<LEN;p_char++,index++){
        printf("%c,", *p_char);
        printf("%x ", p_char);

    }
    printf("\n");

    for(int index=0;index<LEN;index++){
        printf("%d ",input_ints[index]);
    }
    printf("\n");
    for(int index=0;index<LEN;index++){
        printf("%c ",input_chars[index]);
    }

    return 0;
}
