/*------------------------------------------------------
* Filename: TalBiton_print_value_address_fix.c
* Description: recives a string and a series of numbers and pints them
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>

#define LEN 8

int main() {
    char input_chars[LEN+1]="00000000";
    int input_ints[LEN]={0};
    int *p_int=input_ints;
    char *p_char=input_chars;
    char enter;

    printf("please enter 8 numbers with no enters\n");


    for(int index=0;index<LEN;index++){
        while(scanf(" %d", &input_ints[index])!=1){
            printf("error try again\n");
            scanf(" %d", &input_ints[index]);
        }
    }
    scanf("%c",enter);

    printf("please enter 8 chars with no enters\n");

    for(int index=0;index<LEN;index++){
        while(scanf(" %c", &input_chars[index])!=1){
            printf("error try again\n");
            scanf(" %c", &input_chars[index]);
        }
    }

    for(int index=0;index<LEN;p_int++,index++){
        printf("%d,", *p_int);
        printf("%p ", p_int);

    }
    printf("\n");
    for(int index=0;index<LEN;p_char++,index++){
        printf("%c,", *p_char);
        printf("%p ", p_char);

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
