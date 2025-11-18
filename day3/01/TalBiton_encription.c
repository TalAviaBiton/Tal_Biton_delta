/*------------------------------------------------------
* Filename: TalBiton_encription.c
* Description: gets an array of 26 numbers and decode it to be a message
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#include<string.h>

#define CODE_LENGTH 26

int main() {
    int input[CODE_LENGTH]={0};
    int tmp[CODE_LENGTH]={0};
    char result[CODE_LENGTH+1]="00000000000000000000000000";

    for(int i=0;i<CODE_LENGTH-1;i++){
        scanf("%d ,", &input[i]);
    }
    scanf("%d", &input[CODE_LENGTH-1]);

    //switchs the halfs of the array
    for(int i=0;i<CODE_LENGTH/2;i++){
        tmp[i]=input[i+CODE_LENGTH/2];
        tmp[i+CODE_LENGTH/2]=input[i];
    }

    input[0]=tmp[0];//firs number should stay the same
    for(int i=1;i<CODE_LENGTH;i++){//decreasing each number from its following number
        input[i]=tmp[i]-input[i-1];
    }

    for(int i=0;i<5;i++){//rotateing by 5
        tmp[i]=input[CODE_LENGTH-5+i];
    }
    for(int i=0;i<CODE_LENGTH;i++){
        tmp[i+5]=input[i];
    }

    for(int i=0;i<CODE_LENGTH;i+=2){//dividing even indexes by 7
        tmp[i]/=7;
    }

    for(int i=0;i<CODE_LENGTH-4;i++){//rotateing by 4
        input[i]=tmp[i+4];
    }
    for(int i=CODE_LENGTH-4, j=0;i<CODE_LENGTH;i++, j++){
        input[i]=tmp[j];
    }

    for(int i=0;i<CODE_LENGTH;i++){//decreading by 5
        input[i]-=5;
    }

    for(int i=0;i<CODE_LENGTH;i++){//translates to chars
        result[i]=input[i];
    }

    printf(res);

    return 0;
}