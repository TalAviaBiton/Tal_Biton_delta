/*------------------------------------------------------
* Filename: TalBiton_print_chars_fix.c
* Description: recives a number and prints a square of a chracter according to ints deviders
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    int size_of_side=0;
    char char_to_print='@';
    printf("please enter an integer\n");
    if(scanf("%d", &size_of_side) != 1){
        printf("Bad Input!");
        return 0;
    }

    if(size_of_side%2==0){
        char_to_print='*';
    }
    else if(size_of_side%3==0){
        char_to_print='^';
    }
    else if(size_of_side%5==0){
        char_to_print='%';
    }

    for(int i=0;i<size_of_side;i++){
        for(int j=0;j<size_of_side;j++){
            printf("%c",char_to_print);
        }       
        printf("\n");
    }
    
    return 0;
}