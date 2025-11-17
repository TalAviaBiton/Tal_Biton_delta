/*------------------------------------------------------
* Filename: TalBiton_print_chars.c
* Description: recives a number and prints a square of a chracter according to ints deviders
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    int num=0, i=0, j=0;
    char to_print='@';
    if(scanf("%d", &num) != 1){
        printf("Bad Input!");
        return 0;
    }

    if(num%2==0){
        to_print='*';
    }
    else if(num%3==0){
        to_print='^';
    }
    else if(num%5==0){
        to_print='%';
    }

    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            printf("%c",to_print);
        }       
        printf("\n");
    }
    
    return 0;
}