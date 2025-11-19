/*------------------------------------------------------
* Filename: TalBiton_median_fix.c
* Description: recives a series of numbers and prints its median
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> 

void swap(int *p1, int *p2);//swaps two numbers in the series
void bbl_sort(int size, int *numbers);//buble sort
float median(int size, int *numbers);//finds the median of a series

int main(){
    int *numbers = NULL;
    int num=0;
    int size=0;
    int flag=scanf("%d",&num);
    while(flag){
        int *tmp= (int *)malloc(sizeof(int)*size);

        for(int i=0;i<size;i++){//copiing numbers to tmp to redo numbers
            *(tmp+i)=*(numbers+i);
        }

        numbers=(int *)malloc(sizeof(int)*(size+1));
        if (numbers == NULL){//if somthing went wrong
            printf("Error\n");
            return 0;
        }

        for(int i=0;i<size;i++){//copiing tmp back to numbers
            *(numbers+i)=*(tmp+i);
        }
        
        *(numbers+size)=num;
        size++;
        free(tmp);
        flag=scanf("%d",&num);
    }

    for(int i=0;i<size;i++){
           printf("%d ",*(numbers+i));
        }

    size--;//because the last iteration of the loop increased size but didnt add a number to the series

    if(size==0){//if the series wasnt empty wich means we skipped the loop
        printf("\n%.2f\n",median(size,numbers));
        free(numbers);
    }

    return 0;
}

void bbl_sort(int size, int *numbers){//buble sort
    int swapped=0;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (*(numbers+j) > *(numbers+j + 1)){
                swap((numbers+j), (numbers+j + 1));
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void swap(int *p1, int *p2)//swaps two numbers in the series
{
    int tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}

float median(int size, int *numbers){//finds the median of a series
    bbl_sort(size, numbers);
    if(size%2){//==>even
        return *(numbers+size/2);//middle number
    }
    return (float)(*(numbers+size/2-1)+*(numbers+size/2))/2;//average of two middle numbers
}
