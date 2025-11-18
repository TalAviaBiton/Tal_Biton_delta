/*------------------------------------------------------
* Filename: TalBiton_str_to_int.b.c
* Description: recives a string of a number and returns the number+36
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define LEN 10//because the largest number int can hold is 2,147,483,647 wich has 10 digits

int main() {
    char input[LEN+1]="0000000000";
    int num=36;
    int place=1;
    int len=0;
    int tmp=0;

    scanf("%s", &input);
    len=strlen(input);
    
    for(int i=len-1;i>=0;i--){
        switch (input[i])
        {
        case '0':
            break;
        case '1':
            tmp=1;
            break;
        case '2':
            tmp=2;
            break;
        case '3':
            tmp=3;
            break;
        case '4':
            tmp=4;
            break;
        case '5':
            tmp=5;
            break;
        case '6':
            tmp=6;
            break;
        case '7':
            tmp=7;
            break;
        case '8':
            tmp=8;
            break;
        case '9':
            tmp=9;
            break;
        default:
            printf("error\n");
            return 0;
            break;
        }
        num=num+tmp*place;
        place*=10;
    }

    printf("%d", num);  
    return 0;
}