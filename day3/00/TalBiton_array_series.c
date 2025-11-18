/*------------------------------------------------------
* Filename: TalBiton_array_series.c
* Description: gets an array of 15 numbers and says if its ordered and if it is how
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    int flag=0;
    int input[15]={0};
    int i=0;
    //input
    scanf("%d", &input[0]);
    scanf("%d", &input[1]);
    if(input[i]<input[i-1]){
        flag=1;
        }
    if(input[i]>input[i-1]){
        flag=2;
        }
    if(input[i]==input[i-1]){
        flag=3;
        }
    for(i=2;i<15;i++){
        scanf("%d", &input[i]);
        if((flag==1&&input[i]>=input[i-1])||(flag==2&&input[i]<=input[i-1])||(flag==3&&input[i]!=input[i-1])){
            flag=0;
        }
    }

    //output
    switch (flag)
    {
    case 1:
        printf("The array is decreasing");
        break;
    case 2:
        printf("The array is increasing");
        break;
    case 3:
        printf("The array is constant");
        break;
    default:
        printf("The array is messed up");
        break;
    }

    return 0;
}