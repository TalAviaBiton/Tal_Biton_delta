/*------------------------------------------------------
* Filename: TalBiton_array_series_fix.c
* Description: gets an array of 15 numbers and says if its ordered and if it is how
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#define SERIES_LENGTH 15

void output(int array_order_status);

int main() {
    int array_order_status =0;
    int input[SERIES_LENGTH]={0};
    int index=0;

    scanf("%d", &input[0]);
    scanf("%d", &input[1]);
    if(input[index]<input[index-1]){
            array_order_status =1;
        }
    else if(input[index]>input[index-1]){
            array_order_status =2;
        }
    else if(input[index]==input[index-1]){
            array_order_status =3;
        }
    for(index=2;index<15;index++){
            scanf("%d", &input[index]);
            if( (array_order_status ==1&&input[index]>=input[index-1])||
                (array_order_status ==2&&input[index]<=input[index-1])||
                (array_order_status ==3&&input[index]!=input[index-1])){
                array_order_status =0;
            }
    }

    output(array_order_status);    
    return 0;
}

void output(int array_order_status){
    switch (array_order_status )
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
}